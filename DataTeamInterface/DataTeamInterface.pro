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

INCLUDEPATH += "$${_PRO_FILE_PWD_}/src"
INCLUDEPATH += "$${_PRO_FILE_PWD_}/src/captor"
INCLUDEPATH += "$${_PRO_FILE_PWD_}/src/captor/SimpleXbox360Controller"

win32:LIBS += $${_PRO_FILE_PWD_}/SimpleXbox360Controller/XInput.lib

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/tcpconnection.cpp \
    src/captor/joystick.cpp \
    src/simplexbox360controller.cpp \
    src/protocole.cpp\
    src/captor.cpp\
    src/robotinterface.cpp \
    src/captor/gps.cpp \
    src/captor/lidar.cpp \
    src/captor/gyro.cpp \
    src/captor/actuator.cpp \
    src/captor/accelero.cpp \
    src/captor/magneto.cpp \
    src/captor/odo.cpp \
    src/captor/motor.cpp


HEADERS  += src/mainwindow.h \
    src/tcpconnection.h \
    src/captor/joystick.h \
    src/simplexbox360controller.h \
    src/protocole.h \
    src/global.h \
    src/captor.h\
    src/robotinterface.h \
    src/captor/gps.h \
    src/captor/lidar.h \
    src/captor/gyro.h \
    src/captor/actuator.h \
    src/captor/accelero.h \
    src/captor/magneto.h \
    src/captor/odo.h \
    src/captor/motor.h

FORMS    += src/mainwindow.ui

RESOURCES += \
    res/ressources.qrc
