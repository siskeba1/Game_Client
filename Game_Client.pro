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


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp \
    clientcontroller.cpp \
    keyboardlistener.cpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    clientcontroller.h \
    keyboardlistener.h

FORMS    += mainwindow.ui
