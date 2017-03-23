#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QObject>
#include <Model/TcpClient.h>
#include <View/MainWindow.h>

class ClientController : public QObject
{
    Q_OBJECT
public:
    ClientController(QObject *parent = NULL);
private:
    TcpClient *tcpClient;
    MainWindow *mainWindow;
};

#endif // CLIENTCONTROLLER_H
