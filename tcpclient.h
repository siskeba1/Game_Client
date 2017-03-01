#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>

class QTcpSocket;
class QNetworkSession;

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = Q_NULLPTR);
private:
    QTcpSocket *tcpSocket;
    QString message;
    QNetworkSession *networkSession;
    QDataStream in;
};

#endif // TCPCLIENT_H
