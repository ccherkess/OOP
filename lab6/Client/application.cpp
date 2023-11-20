#include "application.h"

#include "../Common/common.h"
#include "../Common/communicator.h"

TApplication::TApplication(int argc, char *argv[])
            : QApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10001,
                         QHostAddress("127.0.0.1"), 10000};
    comm = new TCommunicator(pars, this);

    interface = new Interface();

    interface->show();

    connect(comm,SIGNAL(recieved(QByteArray)),this,
            SLOT(fromCommunicator(QByteArray)));

    connect(interface,SIGNAL(request(QString)),
            this,SLOT(toCommunicator(QString)));

}

void TApplication::fromCommunicator(QByteArray msg)
{
    interface->answer(QString(msg));
}

TApplication::~TApplication()
{
    delete interface;
    delete comm;
}

void TApplication::toCommunicator(QString msg)
{
    comm->send(QByteArray().append(msg));
}
