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
    Model/TcpClient.cpp \
    Player/Player.cpp \
    View/Scene/Scene.cpp

HEADERS  += \
    Controller/ClientController.h \
    View/MainWindow.h \
    Model/TcpClient.h \
    Player/Player.h \
    View/Scene/Scene.h

FORMS    += \
    GUI/MainWindow.ui
