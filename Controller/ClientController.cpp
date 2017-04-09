#include "Controller/ClientController.h"

ClientController::ClientController(QObject *parent): QObject(parent)
{
    tcpClient = new TcpClient(parent);
    mainWindow = new MainWindow();

    connect(mainWindow, SIGNAL(sendMessage(QString)), tcpClient, SLOT(sendMessage(QString)));

    connect(mainWindow, SIGNAL(signalConnectButtonPressed(QString, int)), tcpClient, SLOT(slotConnectToServer(QString, int)));
    connect(mainWindow, SIGNAL(signalCheckPingButton()), tcpClient, SLOT(slotSendPingRequest()));

    connect(tcpClient, SIGNAL(signalConnected()), mainWindow, SLOT(slotClientConnected()));
    connect(tcpClient, SIGNAL(signalDisconnected()), mainWindow, SLOT(slotClientDisconnected()));
    connect(tcpClient, SIGNAL(signalReceivedAnswerPing(int)), mainWindow, SLOT(slotPing(int)));

    mainWindow->show();
}
