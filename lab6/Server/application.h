#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include "../Common/communicator.h"
#include "SquareMatrix.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT

    TCommunicator *comm;

public:

    TApplication(int, char**);

signals:

public slots:

    void recieve(QByteArray);

private:

    template<typename Number>
    QString formingAnswer(QByteArray message, SquareMatrix<Number> matrix, int mode);

};

#endif // APPLICATION_H


