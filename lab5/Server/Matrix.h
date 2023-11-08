#pragma once

#include "Number.h"
#include "iostream"
#include <QString>


class Matrix
{
public:

    Matrix(int n, int m); //a constructor that takes the order of the matrix as input

    ~Matrix(); //destructor

    Matrix* transpore(); //a function that creates and returns a transposed matrix

    int rang(); //a function that counts the rank of a matrixd

    Number* getCell(int i, int j); //getting a(i, j) matrix cells

    int getN(); //getting the order of the matrix

    int getM();

    friend std::ostream& operator << (std::ostream& os, const Matrix& matrix); //output of the matrix to the stream

    friend QString& operator << (QString& os, const Matrix& matrix);

protected:

    Number** gauss(); //gauss algorithm, returns a triangular matrix

private:

    int n, m;

    Number** matrixArray; //array storing matrix values

    Number** cloneMatrixArray(); //copying an array of values

};

