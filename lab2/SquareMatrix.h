#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Number.h"
#include "iostream"


class SquareMatrix
{
public:

    SquareMatrix(int n); //конструктор, который принимает на вход пор€док матрицы

    ~SquareMatrix(); //деструктор

    SquareMatrix* transpore(); //функци€, котора€ создает и возвращает транспонированную матрицу

    int rang(); //функци€, котора€ считает ранг матрицы

    Number determinant(); //функци€, котора€ считает определитель матрицы

    Number* getCell(int i, int j); //получение a(i, j) €чейки матрицы

    int getN(); //получение пор€дка матрицы

    friend std::ostream& operator << (std::ostream& os, const SquareMatrix& matrix); //вывод матрицы в поток

private:

    int n; //пор€док матрицы

    Number** matrixArray; //массив, хран€щий значени€ матрицы

    Number** gauss(); //алгоритм гаусса, возвращает треугольную матрицу

    Number** cloneMatrixArray(); //копирование массива значений

};

#endif // SQUAREMATRIX_H
