#include "application.h"
#include "SquareMatrix.h"
#include "ComplexNumber.h"
#include "RationalNumber.h"
#include "../Common/common.h"
#include "SquareMatrix.cpp"
#include <QDateTime>


TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));

    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " server has started.";

}

void TApplication::recieve(QByteArray message)
{
    
    int index;

    index = message.indexOf(separator);
    int type = message.left(index).toInt();
    message = message.right(message.length() - index - 1);

    index = message.indexOf(separator);
    int mode = message.left(index).toInt();
    message = message.right(message.length() - index - 1);

    index = message.indexOf(separator);
    int order = message.left(index).toInt();
    message = message.right(message.length() - index - 1);

    QString answer;

    switch (type)
    {
    case DOUBLE:

        answer = formingAnswer(message, SquareMatrix<double>(order), mode);
        break;
    
    case COMPLEX:

        answer = formingAnswer(message, SquareMatrix<ComplexNumber>(order), mode);
        break;

    case RATIONAL:

        answer = formingAnswer(message, SquareMatrix<RationalNumber>(order), mode);
        break;

    default:
        return;
    }

    comm->send(
        QByteArray().append(answer)
    );
}

template<typename Number>
inline QString TApplication::formingAnswer(QByteArray message, SquareMatrix<Number> matrix, int mode)
{
    QString answer;
    

    for (int i = 0; i < matrix.getN(); i++)
    {
        for (int j = 0; j < matrix.getN(); j++)
        {
            message >> *matrix.getCell(i, j);
        }
    }


    switch (mode)
    {
    case CALCULATE_DETERMINANT:

        answer << QString::number(mode) << matrix.determinant();

        break;

    case TRANSPORE_MATRIX:

        answer << QString::number(mode) << *matrix.transpore();

        break;

    case CALCULATE_RANG:

        answer << QString::number(mode) << QString::number(matrix.rang());

        break;

    case OUTPUT_MATRIX:

        answer << QString::number(mode) << matrix;

        break;

    default:

        break;

    }

    return answer;
}