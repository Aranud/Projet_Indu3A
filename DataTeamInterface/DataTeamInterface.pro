#-------------------------------------------------
#
# Project created by QtCreator 2015-02-16T08:30:19
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataTeamInterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpconnection.cpp

HEADERS  += mainwindow.h \
    tcpconnection.h

FORMS    += mainwindow.ui
