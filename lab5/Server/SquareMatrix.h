#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Number.h"
#include "iostream"
#include <QString>
#include "Matrix.h"


class SquareMatrix : public Matrix
{
public:

    SquareMatrix(int n); //a constructor that takes the order of the matrix as input

    Number determinant(); //a function that counts the determinant of the matrix

private:
};

#endif // SQUAREMATRIX_H
