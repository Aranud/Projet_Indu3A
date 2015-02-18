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

win32:LIBS += $${_PRO_FILE_PWD_}/SimpleXbox360Controller/XInput.lib

SOURCES += main.cpp\
        mainwindow.cpp \
    tcpconnection.cpp \
    joystick.cpp \
    simplexbox360controller.cpp \
    protocole.cpp\

HEADERS  += mainwindow.h \
    tcpconnection.h \
    joystick.h \
    simplexbox360controller.h \
    protocole.h \

FORMS    += mainwindow.ui
