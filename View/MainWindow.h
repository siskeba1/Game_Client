#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void sendMessage(QString message);
    void pressed(QKeyEvent *event);
    void released(QKeyEvent *event);

    void signalConnectButtonPressed(QString ip, int port);
    void signalCheckPingButton();

protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent*){}
public slots:
    void slotKeyPressed(QKeyEvent*){}
    void slotKeyReleased(QKeyEvent*){}
    void slotClientConnected();
    void slotClientDisconnected();
    void slotPing(int latency);
private slots:
    void on_connectButton_clicked();

    void on_pushButton_2_clicked();

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
