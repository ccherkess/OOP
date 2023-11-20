#include "interface.h"
#include "../Common/common.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("lab3");

    n = 3;

    initInput();
    initButton();
    initLabel();
    initComboBox();

    initWindow();
}

Interface::~Interface()
{

    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
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

    delete comboBox;
}

void Interface::initWindow()
{
    wWindow = ((20 + wInput) * n + 100 < (wButton) * 4 + 60) 
        ? (wButton) * 4 + 60 : (20 + wInput) * n + 100;

    hWindow = 50 * 3 + hButton + ((hInput + 50) * n) * 2;

    setFixedSize(wWindow, hWindow);

    setGeometry();
}

void Interface::changeOrderMatrix()
{
    n = setOrderMatrixLineEdit->text().toInt();
    
    if (n < minOrderMatrix || n > maxOrderMatrix || (comboBox->currentIndex() == 1 && n > 7))
    {
        errorSetOrderMatrixLabel->setGeometry(300, 10, 400, 20);
        return;
    }

    initWindow();
}

void Interface::setDefaultLabel()
{
    result->setText(" ");

    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
        {
            resultMatrix[i][j]->setText(" ");
        }
    }
}

void Interface::setGeometry()
{
    button1->setGeometry(30, 100 + 30 + hInput * n * 2.5, wButton, hButton);
    button2->setGeometry(30 + wButton, 100 + 30 + hInput * n * 2.5, wButton, hButton);
    button3->setGeometry(30 + wButton * 2, 100 + 30 + hInput * n * 2.5, wButton, hButton);
    button4->setGeometry(30 + wButton * 3, 100 + 30 + hInput * n * 2.5, wButton, hButton);

    errorSetOrderMatrixLabel->setGeometry(0, 0, 0, 0);
    setOrderMatrixLineEdit->setText(QString::number(n));

    setDefaultGeometry();

    switch (index) {
    case 0:
        setGeometryDouble();
        break;

    case 1:
        setGeometryComplex();
        break;

    case 2:
        setGeometryRational();
        break;

    default:
        setGeometryDouble();

    }

    result->setGeometry(wWindow / 2, 250 + hInput * n * 2.5, wInput * 2, hInput);
    result->setText("");


}

void Interface::setDefaultGeometry()
{
    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
        {
            numeratorInputs[i][j]->setGeometry(0, 0, 0, 0);

            denominatorInputs[i][j]->setGeometry(0, 0, 0, 0);

            resultMatrix[i][j]->setGeometry(0, 0, 0, 0);

            resultMatrix[i][j]->setText("");

            complexLabel[i][j]->setText(" + i");
            complexLabel[i][j]->setGeometry(0, 0, 0, 0);
        }
    }
}

void Interface::setGeometryDouble()
{
    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
        {
            if (i < n && j < n)
            {
                int x = wWindow / 2 - (wInput + 20) * (n) / 2 + (wInput + 20) * i;
                int y = 100 + hInput * 2.5 * j;

                numeratorInputs[i][j]->setGeometry(x, y, wInput, hInput);

                x = wWindow / 2 - (wInput / 2 + 20) * (n - 1) + (wInput + 20) * i;
                y = 150 + hButton + hInput * 2.5 * (n + j + 1);

                resultMatrix[i][j]->setGeometry(x, y, wInput, hInput);
            }
            else
            {
                numeratorInputs[i][j]->setGeometry(0, 0, 0, 0);

                resultMatrix[i][j]->setGeometry(0, 0, 0, 0);
            }

            resultMatrix[i][j]->setText("");

        }
    }
}

void Interface::setGeometryComplex()
{
    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
        {
            if (i < n && j < n)
            {
                int x = wWindow / 2 - (wInput * 1.5) * n / 2 + (wInput * 1.5) * i;
                int y = 100 + hInput * 2.5 * j;

                numeratorInputs[i][j]->setGeometry(x, y, wInput / 2, hInput);

                complexLabel[i][j]->setGeometry(x + wInput * 1 / 3 + 15, y, 20, 20);

                denominatorInputs[i][j]->setGeometry(x + wInput * 2 / 3 + 7, y, wInput / 2, hInput);

                x = wWindow / 2 - (wInput / 2 + 20) * (n - 1) + (wInput + 20) * i;
                y = 150 + hButton + hInput * 2.5 * (n + j + 1);

                resultMatrix[i][j]->setGeometry(x, y, wInput, hInput);
            }
            else
            {
                numeratorInputs[i][j]->setGeometry(0, 0, 0, 0);

                resultMatrix[i][j]->setGeometry(0, 0, 0, 0);
            }

            resultMatrix[i][j]->setText("");

        }
    }
}

void Interface::setGeometryRational()
{
    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
        {
            if (i < n && j < n)
            {
                int x = wWindow / 2 - (wInput + 20) * (n) / 2 + (wInput + 20) * i;
                int y = 100 + hInput * 2.5 * j;

                numeratorInputs[i][j]->setGeometry(x, y, wInput, hInput);

                denominatorInputs[i][j]->setGeometry(x, y + hInput, wInput, hInput);

                x = wWindow / 2 - (wInput / 2 + 20) * (n - 1) + (wInput + 20) * i;
                y = 150 + hButton + hInput * 2.5 * (n + j + 1);

                resultMatrix[i][j]->setGeometry(x, y, wInput, hInput);
            }
            else
            {
                numeratorInputs[i][j]->setGeometry(0, 0, 0, 0);

                denominatorInputs[i][j]->setGeometry(0, 0, 0, 0);

                resultMatrix[i][j]->setGeometry(0, 0, 0, 0);
            }

            resultMatrix[i][j]->setText("");

        }
    }
}

void Interface::initLabel()
{
    setOrderMatrixLabel = new QLabel("Set order the matrix:", this);
    setOrderMatrixLabel->setGeometry(20, 10, 150, 20);

    errorSetOrderMatrixLabel = new QLabel("Error: the order must be a number from 1 to 10 (7 for Complex).", this);
    errorSetOrderMatrixLabel->setGeometry(0, 0, 0, 0);
    errorSetOrderMatrixLabel->setStyleSheet("QLabel {color : red;}");

    result = new QLabel(this);

    complexLabel = new QLabel ** [maxOrderMatrix];
    resultMatrix = new QLabel **[maxOrderMatrix];

    for (int i = 0; i < maxOrderMatrix; i++)
    {
        resultMatrix[i] = new QLabel * [maxOrderMatrix];
        complexLabel[i] = new QLabel * [maxOrderMatrix];
    }

    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
        {
            resultMatrix[i][j] = new QLabel(this);
            complexLabel[i][j] = new QLabel(this);
        }
    }
}

void Interface::initComboBox()
{
    comboBox = new QComboBox(this);

    comboBox->addItem("Double");
    comboBox->addItem("Complex");
    comboBox->addItem("Rational");

    comboBox->setCurrentIndex(0);

    comboBox->setGeometry(20, 40, 120, 20);
    
    connect(comboBox, SIGNAL(activated(int)), this, SLOT(changeTypeMatrix(int)));
}

void Interface::initInput()
{
    setOrderMatrixLineEdit = new QLineEdit(this);
    setOrderMatrixLineEdit->setGeometry(150, 12, 50, 20);

    numeratorInputs = new QLineEdit ** [maxOrderMatrix];
    denominatorInputs = new QLineEdit ** [maxOrderMatrix];

    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        numeratorInputs[i] = new QLineEdit * [maxOrderMatrix];
        denominatorInputs[i] = new QLineEdit * [maxOrderMatrix];
    }

    for (int i = 0; i < maxOrderMatrix; i++) 
    {
        for (int j = 0; j < maxOrderMatrix; j++) 
        {
            numeratorInputs[i][j] = new QLineEdit(QString::number(i + j), this);

            denominatorInputs[i][j] = new QLineEdit(QString::number(i + j + 1), this);
        }
    }
}

void Interface::initButton()
{
    /*
    List of commands:
    1) Calculate the determinant of the matrix.
    2) To form a transposed matrix.
    3) Calculate the rank of the matrix.
    4) Output the matrix.
    */

    setOrderMatrixButton = new QPushButton("set", this);
    setOrderMatrixButton->setGeometry(215, 8, 50, 30);
    connect(setOrderMatrixButton, SIGNAL(pressed()), this, SLOT(changeOrderMatrix()));

    button1 = new QPushButton("Calculate the determinant of the matrix.", this);
    button2 = new QPushButton("To form a transposed matrix.", this);
    button3 = new QPushButton("Calculate the rank of the matrix.", this);
    button4 = new QPushButton("Output the matrix.", this);

    connect(button1, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(button2, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(button3, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(button4, SIGNAL(pressed()), this, SLOT(formRequest()));

}

void Interface::changeTypeMatrix(int index) 
{
    this->index = index;

    this->n = 3;

    initWindow();
}

void Interface::formRequest()
{
    QString message;

    message << comboBox->currentIndex();

    QPushButton* button = (QPushButton*) sender();

    if (button == button1) message << "1";
    if (button == button2) message << "2";
    if (button == button3) message << "3";
    if (button == button4) message << "4";

    message << QString::number(n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            QString number;
            number += numeratorInputs[i][j]->text();
            number += "-";
            number += denominatorInputs[i][j]->text();

            message << number;
        }
    }

    emit request(message);
}

void Interface::answer(QString message)
{
    int index;

    index = message.indexOf(separator);
    int mode = message.left(index).toInt();
    message = message.right(message.length() - index - 1);

    setDefaultLabel();

    if (mode == 1 || mode == 3)
    {
        index = message.indexOf(separator);
        QString number = message.left(index);
        message = message.right(message.length() - index - 1);

        result->setText(number);
    } 
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                index = message.indexOf(separator);
                QString number = message.left(index);
                message = message.right(message.length() - index - 1);

                resultMatrix[i][j]->setText(number);
            }
        }
    }
}