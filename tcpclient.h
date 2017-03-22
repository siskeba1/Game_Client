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
    void connectToServer(QString serverIp, int serverPort);
    void disconnectFromServer();
private slots:
    void sessionOpened();
private:
    QTcpSocket *tcpSocket;
    QString message;
    QNetworkSession *networkSession;
    QDataStream in;
    void configureClient();
public slots:
    void socketConnected();
    void socketDisconnected();
    void sendMessage(QString message);
};

#endif // TCPCLIENT_H
