#include "SquareMatrix.h"

#include <iostream>
#include <iomanip>
#include "Matrix.h"

template<typename Number>
SquareMatrix<Number>::SquareMatrix(int n) : Matrix(n, n)
{
    
}

template<typename Number>
SquareMatrix<Number>::SquareMatrix(const SquareMatrix& matrix) : Matrix(matrix)
{

}

template<typename Number>
Number SquareMatrix<Number>::determinant()
{
    Number result = 1;

    Number** matrix = gauss(); //we get matrices of the triangular form

    for (int i = 0; i < getN(); i++)
    {
        /*
        * since the matrix is reduced to a triangular form
        * its determinant is equal to the product of diagonal elements
        */
        result *= matrix[i][i]; 

        delete[] matrix[i];
    }

    delete[] matrix;

    return (getN() == 1) ? result : result;
}

