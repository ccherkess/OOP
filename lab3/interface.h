#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

#include "SquareMatrix.h"


class interface : public QWidget
{
    Q_OBJECT
    QLineEdit*** numeratorInputs;
    QLineEdit*** denominatorInputs;
    QPushButton* button1, * button2, * button3, * button4;
    QLabel* result, *** resultMatrix;

public:
    interface(QWidget *parent = nullptr);
    ~interface();


public slots:

    void determinant();
    void showMatrix();
    void rang();
    void transpore();

private:

    const int n = 2;
    const int wInput = 100, hInput = 20;
    const int wButton = 250, hButton = 50;
    const int wWindow = (wButton) * 4 + 60, hWindow = 50 * 2 + hButton + ((hInput + 50) * n) * 2;

    void initButton();
    void initInput();
    void initLabel();

    void setDefaultLabel();

    SquareMatrix* inputMatrix();

};
