#include "application.h"
#include "SquareMatrix.h"

#include <QDateTime>

#include "../Common/common.h"

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
    QString answer;
    
    int index;

    index = message.indexOf(separator);
    int mode = message.left(index).toInt();
    message = message.right(message.length() - index - 1);

    index = message.indexOf(separator);
    int order = message.left(index).toInt();
    message = message.right(message.length() - index - 1);

    SquareMatrix matrix(order);

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
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
        
        return;

    }

    comm->send(QByteArray().append(answer));
}
