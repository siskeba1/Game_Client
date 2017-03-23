#include "View/MainWindow.h"
#include "GUI/ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setFocusPolicy(Qt::StrongFocus);
    ui->label->setFocusPolicy(Qt::StrongFocus);

    connect(this, SIGNAL(pressed(QKeyEvent*)), this, SLOT(slotKeyPressed(QKeyEvent*)));
    //connect(this, SIGNAL(released(QKeyEvent*)), this, SLOT(slotKeyReleased(QKeyEvent*)));

    this->ui->label->setStyleSheet("QLabel { background-color : yellow;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    emit pressed(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
}

void MainWindow::on_pushButton_clicked()
{
    emit clicked(this->ui->lineEdit->text());
    this->ui->lineEdit->clear();
    this->ui->lineEdit->setFocus();
}

void MainWindow::slotKeyPressed(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        this->ui->label->setStyleSheet("QLabel { background-color : red;}");
    }
    else if(event->key() == Qt::Key_S)
    {
       this->ui->label->setStyleSheet("QLabel { background-color : green;}");
    }
}

void MainWindow::slotKeyReleased(QKeyEvent *event)
{
    this->ui->label->setStyleSheet("QLabel { background-color : red;}");
}
