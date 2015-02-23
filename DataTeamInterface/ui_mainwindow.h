/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *leServerAddress;
    QLineEdit *leServerPort;
    QLabel *lbDataReceived;
    QPushButton *pbSendData;
    QPushButton *pbConnection;
    QLineEdit *leDataToSend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(476, 417);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        leServerAddress = new QLineEdit(centralWidget);
        leServerAddress->setObjectName(QStringLiteral("leServerAddress"));
        leServerAddress->setGeometry(QRect(90, 10, 171, 20));
        leServerPort = new QLineEdit(centralWidget);
        leServerPort->setObjectName(QStringLiteral("leServerPort"));
        leServerPort->setGeometry(QRect(270, 10, 171, 20));
        lbDataReceived = new QLabel(centralWidget);
        lbDataReceived->setObjectName(QStringLiteral("lbDataReceived"));
        lbDataReceived->setGeometry(QRect(260, 160, 211, 201));
        lbDataReceived->setFrameShape(QFrame::Box);
        pbSendData = new QPushButton(centralWidget);
        pbSendData->setObjectName(QStringLiteral("pbSendData"));
        pbSendData->setGeometry(QRect(90, 120, 75, 23));
        pbConnection = new QPushButton(centralWidget);
        pbConnection->setObjectName(QStringLiteral("pbConnection"));
        pbConnection->setGeometry(QRect(10, 10, 75, 23));
        leDataToSend = new QLineEdit(centralWidget);
        leDataToSend->setObjectName(QStringLiteral("leDataToSend"));
        leDataToSend->setGeometry(QRect(190, 120, 231, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 476, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        leServerAddress->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        leServerPort->setText(QApplication::translate("MainWindow", "3331", 0));
        lbDataReceived->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pbSendData->setText(QApplication::translate("MainWindow", "SendData", 0));
        pbConnection->setText(QApplication::translate("MainWindow", "Connection", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
