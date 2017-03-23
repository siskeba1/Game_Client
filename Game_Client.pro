#-------------------------------------------------
#
# Project created by QtCreator 2017-03-01T09:37:41
#
#-------------------------------------------------

QT       += core gui
QT += network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game_Client
TEMPLATE = app


SOURCES += Main/main.cpp\
    Controller/ClientController.cpp \
    View/MainWindow.cpp \
    Model/TcpClient.cpp

HEADERS  += \
    Controller/ClientController.h \
    View/MainWindow.h \
    Model/TcpClient.h

FORMS    += GUI/mainwindow.ui
