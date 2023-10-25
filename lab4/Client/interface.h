#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class Interface : public QWidget
{
    Q_OBJECT
    QLineEdit*** numeratorInputs;
    QLineEdit*** denominatorInputs;
    QPushButton* button1, * button2, * button3, * button4;

    QPushButton* setOrderMatrixButton;
    QLineEdit* setOrderMatrixLineEdit;
    QLabel* setOrderMatrixLabel;

    QLabel* errorSetOrderMatrixLabel;

    QLabel* result, *** resultMatrix;

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

public slots:

    void answer(QString message);

private slots:

    void formRequest();
    void changeOrderMatrix();

signals:

    void request(QString message);
    
private:

    int n;

    const int wInput = 100, hInput = 20;
    const int wButton = 250, hButton = 50;
    const int minOrderMatrix = 1, maxOrderMatrix = 10;

    int wWindow, hWindow;

    void initWindow();
    void initButton();
    void initInput();
    void initLabel();

    void setGeometry();

    void setDefaultLabel();

};
