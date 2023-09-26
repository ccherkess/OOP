#include "SquareMatrix.h"
#include "Number.h"
#include <iostream>
#include <iomanip>

SquareMatrix::SquareMatrix(int n)
{
    matrixArray = new Number*[n];

    this->n = n;

    for (int i = 0; i < n; i++) matrixArray[i] = new Number[n];

    //������� ������� �� ���������
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) matrixArray[i][j] = 0;
    }
}

SquareMatrix::~SquareMatrix()
{
    for (int i = 0; i < n; i++) {
        delete[] matrixArray[i];
    }

    delete[] matrixArray;
}

Number* SquareMatrix::getCell(int i, int j)
{
    return &matrixArray[i][j];
}

int SquareMatrix::getN()
{
    return n;
}

SquareMatrix* SquareMatrix::transpore() {

    SquareMatrix* transporeMatrix = new SquareMatrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
          transporeMatrix->matrixArray[i][j] = this->matrixArray[j][i];
        }
    }

    return transporeMatrix;
}

Number** SquareMatrix::cloneMatrixArray()
{
    Number** clone = new Number*[n];

    for (int i = 0; i < n; i++) clone[i] = new Number[n];

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            clone[i][j] = matrixArray[i][j];
        }
    }

    return clone;
}

Number** SquareMatrix::gauss()
{
    Number** matrix = cloneMatrixArray();

    for (int i = 0; i < n - 1; i++)
    {
        int j = i;
        //���� ������, � ������� a(i, j) != 0
        while (j < n && matrix[j][i] == 0) j++;

        if (j == n) continue; //���� j == n - ���� ������� ������� �� 0

        //������ i � j ������� �������
        for (int k = 0; k < n; k++) 
        {
            Number tmp = matrix[i][k];
            matrix[i][k] = matrix[j][k];
            matrix[j][k] = tmp;
        }

        //�������� �������
        for (j = i + 1; j < n; j++) 
        {
            Number coef = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < n; k++) {
                matrix[j][k] = (matrix[j][k] - (matrix[i][k] * (coef)));
            }
        }
    }

    return matrix;
}

Number SquareMatrix::determinant()
{
    Number result = 1;

    Number** matrix = gauss(); //�������� ������� ������������ ����

    for (int i = 0; i < n; i++)
    {
        /*
        * ��� ��� ������� ��������� � ������������ ����
        * � ������������ ����� ������������ ������������ ���������
        */
        result *= matrix[i][i]; 

        delete[] matrix[i];
    }

    delete[] matrix;

    return result;
}

int SquareMatrix::rang()
{
    int result = 0; //���� �������

    Number** matrix = gauss(); //�������� ������� ������������ ����

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] != 0) result++; //���� ������� �� ��������� �� 0, �� ����++

        delete[] matrix[i];
    }

    delete[] matrix;

    return result;
}

std::ostream& operator << (std::ostream& os, const SquareMatrix& matrix)
{
    for (int i = 0; i < matrix.n; i++)
    {
        os << "|";

        for (int j = 0; j < matrix.n; j++)
        {
            os << std::setw(10) << std::setfill(' ') << matrix.matrixArray[i][j] << " ";
        }

        os << "|";

        if (i != matrix.n - 1) os << std::endl;
    }

    return os;
}
