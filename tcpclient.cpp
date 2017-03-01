#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent)
    : QObject(parent),
      tcpSocket(new QTcpSocket(this)),
      networkSession(Q_NULLPTR)
{

}
