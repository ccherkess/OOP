#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Number.h"
#include "iostream"


class SquareMatrix
{
public:

    SquareMatrix(int n); //�����������, ������� ��������� �� ���� ������� �������

    ~SquareMatrix(); //����������

    SquareMatrix* transpore(); //�������, ������� ������� � ���������� ����������������� �������

    int rang(); //�������, ������� ������� ���� �������

    Number determinant(); //�������, ������� ������� ������������ �������

    Number* getCell(int i, int j); //��������� a(i, j) ������ �������

    int getN(); //��������� ������� �������

    friend std::ostream& operator << (std::ostream& os, const SquareMatrix& matrix); //����� ������� � �����

private:

    int n; //������� �������

    Number** matrixArray; //������, �������� �������� �������

    Number** gauss(); //�������� ������, ���������� ����������� �������

    Number** cloneMatrixArray(); //����������� ������� ��������

};

#endif // SQUAREMATRIX_H
