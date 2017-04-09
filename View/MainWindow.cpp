#include "View/MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->connectionStateLabel->setStyleSheet("QLabel { background-color : red;}");
    ui->connectionStatusLabel->setText("Not connected");
    ui->ipLineEdit->setText("192.168.153.1");
    ui->portLineEdit->setText("5001");

    QWidget::setFocusPolicy(Qt::StrongFocus);

    connect(this, SIGNAL(pressed(QKeyEvent*)), this, SLOT(slotKeyPressed(QKeyEvent*)));
    //connect(this, SIGNAL(released(QKeyEvent*)), this, SLOT(slotKeyReleased(QKeyEvent*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    //When ENTER key is pressed behaves, like connect button was pressed.
    case Qt::Key_Return:
    {
        on_connectButton_clicked();
    }
        break;
    }
}

void MainWindow::slotClientConnected()
{
    ui->connectionStatusLabel->setText("Connected to the server.");
    ui->connectionStateLabel->setStyleSheet("QLabel { background-color : green;}");

    ui->portLineEdit->setEnabled(false);
    ui->ipLineEdit->setEnabled(false);
    ui->connectButton->setEnabled(false);
}

void MainWindow::slotClientDisconnected()
{
    ui->connectionStatusLabel->setText("Disconnected from the server.");
    ui->connectionStateLabel->setStyleSheet("QLabel { background-color : red;}");
}

void MainWindow::slotPing(int latency)
{
    ui->pingValueLabel->setText(QString::number(latency));
}

void MainWindow::on_connectButton_clicked()
{
    //TODO: regex checking and port range checking.
    emit signalConnectButtonPressed(ui->ipLineEdit->text(), ui->portLineEdit->text().toInt());
}

//Ping check button, bad name but nevermind ....
void MainWindow::on_pushButton_2_clicked()
{
    emit signalCheckPingButton();
}

void MainWindow::on_sendButton_clicked()
{
    emit sendMessage(ui->messageLineEdit->text());
}
