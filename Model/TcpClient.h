#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include <QElapsedTimer>

class QTcpSocket;
class QNetworkSession;

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = Q_NULLPTR);  
    void disconnectFromServer();
private slots:
    void sessionOpened();
private:
    QTcpSocket *tcpSocket;
    QString message;
    QNetworkSession *networkSession;
    QDataStream in;
    QElapsedTimer timer_;
    int latency_;
    void configureClient();
public slots:
    void slotConnectToServer(QString serverIp, int serverPort);
    void socketConnected();
    void socketDisconnected();
    void sendMessage(QString message);
    void readMessage();

    void slotSendPingRequest();

signals:
    signalConnected();
    signalDisconnected();

    signalReceivedAnswerPing(int);
};

#endif // TCPCLIENT_H
