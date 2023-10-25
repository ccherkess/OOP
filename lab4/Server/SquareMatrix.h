#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Number.h"
#include "iostream"
#include <QString>


class SquareMatrix
{
public:

    SquareMatrix(int n); //a constructor that takes the order of the matrix as input

    ~SquareMatrix(); //destructor

    SquareMatrix* transpore(); //a function that creates and returns a transposed matrix

    int rang(); //a function that counts the rank of a matrix

    Number determinant(); //a function that counts the determinant of the matrix

    Number* getCell(int i, int j); //getting a(i, j) matrix cells

    int getN(); //getting the order of the matrix

    friend std::ostream& operator << (std::ostream& os, const SquareMatrix& matrix); //output of the matrix to the stream

    friend QString& operator << (QString& os, const SquareMatrix& matrix);


private:

    int n; //matrix order

    Number** matrixArray; //array storing matrix values

    Number** gauss(); //gauss algorithm, returns a triangular matrix

    Number** cloneMatrixArray(); //copying an array of values

};

#endif // SQUAREMATRIX_H
