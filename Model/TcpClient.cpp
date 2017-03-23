#include "Model/TcpClient.h"
#include <QtWidgets>
#include <QtNetwork>

TcpClient::TcpClient(QObject *parent)
    : QObject(parent),
      tcpSocket(new QTcpSocket(this)),
      networkSession(Q_NULLPTR)
{
    configureClient();
    connectToServer(QString("192.168.153.1"), 5001);
}

/**
 * @brief TcpClient::configureClient
 * Configures the client.
 */
void TcpClient::configureClient()
{
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_7);
    connect(tcpSocket, &QIODevice::readyRead, this, &TcpClient::readMessage);
    typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
    //connect(tcpSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error),this, &TcpClient::displayError);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(socketConnected()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        //Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();
        //If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }
        networkSession = new QNetworkSession(config, this);
        connect(networkSession, &QNetworkSession::opened, this, &TcpClient::sessionOpened);
        networkSession->open();
    }
}

void TcpClient::socketConnected()
{
    qDebug() << "connected";
}

void TcpClient::socketDisconnected()
{
    qDebug() << "dc";
}

/**
 * @brief TcpClient::sessionOpened
 * Called when a session opened, sets the used configuration.
 */
void TcpClient::sessionOpened()
{
    //Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();
    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();
}

/**
 * @brief TcpClient::connectToServer
 * @param serverIp
 * @param serverPort
 * Connects to the host. Waiting time: 1 sec.
 */
void TcpClient::connectToServer(QString serverIp, int serverPort)
{
    tcpSocket->connectToHost(serverIp, serverPort);
    tcpSocket->waitForConnected(1000);
}

/**
 * @brief TcpClient::disconnectFromServer
 * Disconnects from the connected host.
 */
void TcpClient::disconnectFromServer()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}

void TcpClient::sendMessage(QString message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);

    //Encrypting
    //out << QString::fromStdString(AESCrypter->encryption(newMessage.toStdString().c_str()).toStdString());
    out << message;
    tcpSocket->write(block);
    tcpSocket->waitForBytesWritten();
}

void TcpClient::readMessage()
{
    in.startTransaction();
    in >> message;
    qDebug() << "incoming message : " << message;
}
