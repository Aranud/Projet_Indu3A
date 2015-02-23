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
#include <QtWidgets/QFrame>
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
    QLineEdit *gpsPort;
    QPushButton *pbSendData;
    QPushButton *pbConnection;
    QLineEdit *leDataToSend;
    QLabel *img;
    QLabel *altitude;
    QLabel *longitude;
    QLabel *latitude;
    QLabel *quality;
    QLabel *altitudeResult;
    QLabel *longitudeResult;
    QLabel *latitudeResult;
    QLabel *qualityResult;
    QLineEdit *acceleroPort;
    QLineEdit *motorPort;
    QLineEdit *leServerPort_4;
    QLineEdit *leServerPort_5;
    QLineEdit *leServerPort_6;
    QLineEdit *leServerPort_7;
    QLineEdit *leServerPort_8;
    QLineEdit *leServerPort_9;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *line;
    QFrame *line_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(735, 399);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        leServerAddress = new QLineEdit(centralWidget);
        leServerAddress->setObjectName(QStringLiteral("leServerAddress"));
        leServerAddress->setGeometry(QRect(60, 10, 271, 20));
        gpsPort = new QLineEdit(centralWidget);
        gpsPort->setObjectName(QStringLiteral("gpsPort"));
        gpsPort->setGeometry(QRect(60, 40, 51, 20));
        pbSendData = new QPushButton(centralWidget);
        pbSendData->setObjectName(QStringLiteral("pbSendData"));
        pbSendData->setGeometry(QRect(350, 150, 75, 23));
        pbConnection = new QPushButton(centralWidget);
        pbConnection->setObjectName(QStringLiteral("pbConnection"));
        pbConnection->setGeometry(QRect(350, 10, 75, 23));
        leDataToSend = new QLineEdit(centralWidget);
        leDataToSend->setObjectName(QStringLiteral("leDataToSend"));
        leDataToSend->setGeometry(QRect(60, 150, 271, 20));
        img = new QLabel(centralWidget);
        img->setObjectName(QStringLiteral("img"));
        img->setGeometry(QRect(160, 210, 261, 131));
        altitude = new QLabel(centralWidget);
        altitude->setObjectName(QStringLiteral("altitude"));
        altitude->setGeometry(QRect(40, 230, 21, 16));
        longitude = new QLabel(centralWidget);
        longitude->setObjectName(QStringLiteral("longitude"));
        longitude->setGeometry(QRect(30, 250, 47, 13));
        latitude = new QLabel(centralWidget);
        latitude->setObjectName(QStringLiteral("latitude"));
        latitude->setGeometry(QRect(40, 270, 31, 16));
        quality = new QLabel(centralWidget);
        quality->setObjectName(QStringLiteral("quality"));
        quality->setGeometry(QRect(20, 290, 47, 16));
        altitudeResult = new QLabel(centralWidget);
        altitudeResult->setObjectName(QStringLiteral("altitudeResult"));
        altitudeResult->setGeometry(QRect(80, 230, 47, 13));
        longitudeResult = new QLabel(centralWidget);
        longitudeResult->setObjectName(QStringLiteral("longitudeResult"));
        longitudeResult->setGeometry(QRect(80, 250, 47, 13));
        latitudeResult = new QLabel(centralWidget);
        latitudeResult->setObjectName(QStringLiteral("latitudeResult"));
        latitudeResult->setGeometry(QRect(80, 270, 47, 13));
        qualityResult = new QLabel(centralWidget);
        qualityResult->setObjectName(QStringLiteral("qualityResult"));
        qualityResult->setGeometry(QRect(80, 290, 47, 13));
        acceleroPort = new QLineEdit(centralWidget);
        acceleroPort->setObjectName(QStringLiteral("acceleroPort"));
        acceleroPort->setGeometry(QRect(170, 40, 51, 20));
        motorPort = new QLineEdit(centralWidget);
        motorPort->setObjectName(QStringLiteral("motorPort"));
        motorPort->setGeometry(QRect(280, 40, 51, 20));
        leServerPort_4 = new QLineEdit(centralWidget);
        leServerPort_4->setObjectName(QStringLiteral("leServerPort_4"));
        leServerPort_4->setGeometry(QRect(60, 70, 51, 20));
        leServerPort_5 = new QLineEdit(centralWidget);
        leServerPort_5->setObjectName(QStringLiteral("leServerPort_5"));
        leServerPort_5->setGeometry(QRect(280, 70, 51, 20));
        leServerPort_6 = new QLineEdit(centralWidget);
        leServerPort_6->setObjectName(QStringLiteral("leServerPort_6"));
        leServerPort_6->setGeometry(QRect(170, 70, 51, 20));
        leServerPort_7 = new QLineEdit(centralWidget);
        leServerPort_7->setObjectName(QStringLiteral("leServerPort_7"));
        leServerPort_7->setGeometry(QRect(60, 100, 51, 20));
        leServerPort_8 = new QLineEdit(centralWidget);
        leServerPort_8->setObjectName(QStringLiteral("leServerPort_8"));
        leServerPort_8->setGeometry(QRect(280, 100, 51, 20));
        leServerPort_9 = new QLineEdit(centralWidget);
        leServerPort_9->setObjectName(QStringLiteral("leServerPort_9"));
        leServerPort_9->setGeometry(QRect(170, 100, 51, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 100, 47, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 40, 47, 13));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 70, 47, 13));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(120, 100, 47, 13));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 70, 47, 13));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(230, 40, 47, 13));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(230, 100, 47, 13));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 150, 47, 13));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 190, 441, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(430, 0, 20, 351));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 735, 21));
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
        gpsPort->setText(QApplication::translate("MainWindow", "3334", 0));
        pbSendData->setText(QApplication::translate("MainWindow", "SendData", 0));
        pbConnection->setText(QApplication::translate("MainWindow", "Connection", 0));
        img->setText(QString());
        altitude->setText(QApplication::translate("MainWindow", "alt", 0));
        longitude->setText(QApplication::translate("MainWindow", "long", 0));
        latitude->setText(QApplication::translate("MainWindow", "lat", 0));
        quality->setText(QApplication::translate("MainWindow", "quality", 0));
        altitudeResult->setText(QString());
        longitudeResult->setText(QString());
        latitudeResult->setText(QString());
        qualityResult->setText(QString());
        acceleroPort->setText(QApplication::translate("MainWindow", "3339", 0));
        motorPort->setText(QApplication::translate("MainWindow", "3331", 0));
        leServerPort_4->setText(QApplication::translate("MainWindow", "3337", 0));
        leServerPort_5->setText(QApplication::translate("MainWindow", "3335", 0));
        leServerPort_6->setText(QApplication::translate("MainWindow", "3340", 0));
        leServerPort_7->setText(QApplication::translate("MainWindow", "3345", 0));
        leServerPort_8->setText(QApplication::translate("MainWindow", "3338", 0));
        leServerPort_9->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Ip", 0));
        label_3->setText(QApplication::translate("MainWindow", "GPS", 0));
        label_4->setText(QApplication::translate("MainWindow", "Lidar", 0));
        label_5->setText(QApplication::translate("MainWindow", "Actuator", 0));
        label_6->setText(QApplication::translate("MainWindow", "Accelero", 0));
        label_7->setText(QApplication::translate("MainWindow", "Gyro", 0));
        label_8->setText(QApplication::translate("MainWindow", "Magneto", 0));
        label_9->setText(QApplication::translate("MainWindow", "Odo", 0));
        label_10->setText(QApplication::translate("MainWindow", "Motor", 0));
        label_11->setText(QApplication::translate("MainWindow", "Remote", 0));
        label_12->setText(QApplication::translate("MainWindow", "Data ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
