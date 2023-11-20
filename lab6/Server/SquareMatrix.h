#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "iostream"
#include <QString>
#include "Matrix.h"
#include "Matrix.cpp"

template<typename Number>
class SquareMatrix : public Matrix<Number>
{
public:

    SquareMatrix(int n); //a constructor that takes the order of the matrix as input

    SquareMatrix(const SquareMatrix& matrix);

    Number determinant(); //a function that counts the determinant of the matrix

private:
};

#endif // SQUAREMATRIX_H
