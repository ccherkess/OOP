#include "interface.h"

interface::interface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("lab3");
    setFixedSize(wWindow, hWindow);

    initInput();
    initButton();
    initLabel();

}

interface::~interface()
{

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            delete numeratorInputs[i][j];
            delete denominatorInputs[i][j];
            delete resultMatrix[i][j];
        }

        delete[] numeratorInputs[i];
        delete[] denominatorInputs[i];
        delete[] resultMatrix[i];

    }

    delete[] numeratorInputs;
    delete[] denominatorInputs;
    delete[] resultMatrix;
   
    delete button1;
    delete button2;
    delete button3;
    delete button4;

    delete result;
}

void interface::initLabel()
{
    result = new QLabel(this);

    result->setGeometry(wWindow / 2, 200 + hInput * n * 2.5, wInput * 2, hInput);

    resultMatrix = new QLabel * *[n];
    for (int i = 0; i < n; i++) resultMatrix[i] = new QLabel * [n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int x = wWindow / 2 - (wInput / 2 + 20) * (n-1)  + (wInput + 20) * i;
            int y = 100 + hButton + hInput * 2.5 * (n + j + 1);

            resultMatrix[i][j] = new QLabel(this);
            resultMatrix[i][j]->setGeometry(x, y, wInput, hInput);

        }
    }
}

void interface::setDefaultLabel()
{
    result->setText(" ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultMatrix[i][j]->setText(" ");
        }
    }
}

void interface::initInput()
{
    numeratorInputs = new QLineEdit ** [n];
    denominatorInputs = new QLineEdit ** [n];

    for (int i = 0; i < n; i++) {
        numeratorInputs[i] = new QLineEdit * [n];
        denominatorInputs[i] = new QLineEdit * [n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int x = wWindow / 2 - (wInput + 20) * (n) / 2 + (wInput + 20) * i;
            int y = 50 + hInput * 2.5 * j;

            numeratorInputs[i][j] = new QLineEdit(QString::number(i + j), this);
            numeratorInputs[i][j]->setGeometry(x, y, wInput, hInput);

            denominatorInputs[i][j] = new QLineEdit(QString::number(i + j + 1), this);
            denominatorInputs[i][j]->setGeometry(x, y + hInput, wInput, hInput);

        }
    }
}

void interface::initButton()
{
    /*
    List of commands:
    1) Calculate the determinant of the matrix.
    2) To form a transposed matrix.
    3) Calculate the rank of the matrix.
    4) Output the matrix.
    */

    button1 = new QPushButton("Calculate the determinant of the matrix.", this);
    button1->setGeometry(30, 50 + 30 + hInput * n * 2.5, wButton, hButton);

    button2 = new QPushButton("To form a transposed matrix.", this);
    button2->setGeometry(30 + wButton, 50 + 30 + hInput * n * 2.5, wButton, hButton);

    button3 = new QPushButton("Calculate the rank of the matrix.", this);
    button3->setGeometry(30 + wButton*2, 50 + 30 + hInput * n * 2.5, wButton, hButton);

    button4 = new QPushButton("Output the matrix.", this);
    button4->setGeometry(30 + wButton*3, 50 + 30 + hInput * n * 2.5, wButton, hButton);

    connect(button1, SIGNAL(pressed()), this, SLOT(determinant()));
    connect(button2, SIGNAL(pressed()), this, SLOT(transpore()));
    connect(button3, SIGNAL(pressed()), this, SLOT(rang()));
    connect(button4, SIGNAL(pressed()), this, SLOT(showMatrix()));
}


void interface::determinant()
{

    setDefaultLabel();

    SquareMatrix* matrix = inputMatrix();

    RationalNumber result = matrix->determinant();

    delete matrix;

    QString s = QString();
    s << result;

    this->result->setText(s);
}

void interface::showMatrix() 
{
    setDefaultLabel();

    SquareMatrix* matrix = inputMatrix();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            QString s = QString();
            s << *matrix->getCell(i, j);

            resultMatrix[j][i]->setText(s);
        }
    }

    delete matrix;
}

void interface::transpore() 
{
    setDefaultLabel();

    SquareMatrix* matrix = inputMatrix()->transpore();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            QString s = QString();
            s << *matrix->getCell(i, j);

            resultMatrix[j][i]->setText(s);
        }
    }

    delete matrix;
}

void interface::rang()
{
    setDefaultLabel();

    SquareMatrix* matrix = inputMatrix();

    QString s = QString::number(matrix->rang());

    delete matrix;

    this->result->setText(s);
}

SquareMatrix* interface::inputMatrix() 
{
    SquareMatrix* matrix = new SquareMatrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *matrix->getCell(i, j) = RationalNumber(numeratorInputs[j][i]->text().toInt(), denominatorInputs[j][i]->text().toInt());
        }
    }

    return matrix;
}