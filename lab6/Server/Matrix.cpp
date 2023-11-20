#include "Matrix.h"
#include <iostream>
#include <iomanip>

template<typename Number>
Matrix<Number>::Matrix(int n, int m)
{
    matrixArray = new Number * [n];

    this->n = n;
    this->m = m;

    for (int i = 0; i < n; i++) matrixArray[i] = new Number[m];

    //setting the default matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) matrixArray[i][j] = 0;
    }
}

template<typename Number>
Matrix<Number>::Matrix(const Matrix& matrix)
{
    matrixArray = new Number * [matrix.n];

    this->n = matrix.n;
    this->m = matrix.m;

    for (int i = 0; i < n; i++) matrixArray[i] = new Number[m];

    //setting the default matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) matrixArray[i][j] = Number(matrix.getCell(i, j));
    }
}

template<typename Number>
Matrix<Number>::~Matrix()
{
    for (int i = 0; i < n; i++) {
        delete[] matrixArray[i];
    }

    delete[] matrixArray;
}


template<typename Number>
Number* Matrix<Number>::getCell(int i, int j)
{
    return &matrixArray[i][j];
}


template<typename Number>
int Matrix<Number>::getN()
{
    return n;
}


template<typename Number>
int Matrix<Number>::getM()
{
    return m;
}


template<typename Number>
Matrix<Number>* Matrix<Number>::transpore() {

    Matrix* transporeMatrix = new Matrix(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            transporeMatrix->matrixArray[i][j] = this->matrixArray[j][i];
        }
    }

    return transporeMatrix;
}

template<typename Number>
Number** Matrix<Number>::cloneMatrixArray()
{
    Number** clone = new Number * [n];

    for (int i = 0; i < n; i++) clone[i] = new Number[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            clone[i][j] = matrixArray[i][j];
        }
    }

    return clone;
}

template<typename Number>
Number** Matrix<Number>::gauss()
{
    Number** matrix = cloneMatrixArray();

    for (int i = 0; i < n - 1; i++)
    {
        int j = i;
        //looking for a string where a(i, j) != 0
        while (j < m && matrix[j][i] == 0) j++;

        if (j == m) continue; //if j == n - the whole column consists of 0

        ////swapping the i and j lines
        for (int k = 0; k < m; k++)
        {
            Number tmp = matrix[i][k];
            matrix[i][k] = matrix[j][k] * -1;
            matrix[j][k] = tmp;
        }

        //zeroing the column
        for (j = i + 1; j < n; j++)
        {
            Number coef = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < m; k++) {
                matrix[j][k] = (matrix[j][k] - (matrix[i][k] * (coef)));
            }
        }
    }

    return matrix;
}

template<typename Number>
int Matrix<Number>::rang()
{
    int result = 0; //matrix rank

    Number** matrix = gauss(); //we get matrices of the triangular form

    for (int i = 0; i < n; i++)
    {
        if (i < m && matrix[i][i] != 0) result++; //if the element on the diagonal is not 0, then the rank++

        delete[] matrix[i];
    }

    delete[] matrix;

    return result;
}

template<typename Number>
std::ostream& operator << (std::ostream& os, const Matrix<Number>& matrix)
{
    for (int i = 0; i < matrix.n; i++)
    {
        os << "|";

        for (int j = 0; j < matrix.m; j++)
        {
            os << std::setw(10) << std::setfill(' ') << matrix.matrixArray[i][j] << " ";
        }

        os << "|";

        if (i != matrix.n - 1) os << std::endl;
    }

    return os;
}

template<typename Number>
QString& operator<<(QString& os, const Matrix<Number>& matrix)
{
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.m; j++) {
            os << matrix.matrixArray[i][j];
        }
    }
    return os;
}