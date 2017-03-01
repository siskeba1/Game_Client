#include "mainwindow.h"
#include <QApplication>
#include <tcpclient.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TcpClient *tcpClient = new TcpClient(new QObject);

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
