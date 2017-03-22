#include <clientcontroller.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ClientController *clientController = new ClientController();

    return a.exec();
}
