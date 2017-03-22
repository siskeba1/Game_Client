#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QObject>
#include <tcpclient.h>
#include <mainwindow.h>
#include <keyboardlistener.h>

class ClientController : public QObject
{
    Q_OBJECT
public:
    ClientController(QObject *parent = NULL);
private:
    TcpClient *tcpClient;
    MainWindow *mainWindow;
    KeyBoardListener *keyBoardListener;
};

#endif // CLIENTCONTROLLER_H
