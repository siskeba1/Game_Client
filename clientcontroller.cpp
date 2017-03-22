#include "clientcontroller.h"

ClientController::ClientController(QObject *parent): QObject(parent)
{
    tcpClient = new TcpClient(parent);
    mainWindow = new MainWindow();

    connect(mainWindow, SIGNAL(clicked(QString)), tcpClient, SLOT(sendMessage(QString)));

    mainWindow->show();
}
