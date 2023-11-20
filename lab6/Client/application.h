#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QApplication>

#include "interface.h"
#include "../Common/communicator.h"

class TApplication : public QApplication
{
    Q_OBJECT

    TCommunicator *comm;
    Interface    *interface;

public:
    TApplication(int, char**);
    ~TApplication();

public slots:
    void fromCommunicator(QByteArray);
    void toCommunicator(QString);

};

#endif // APPLICATION_H
