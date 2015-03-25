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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QLineEdit *lidarPort;
    QLineEdit *odoPort;
    QLineEdit *gyroPort;
    QLineEdit *actuatorPort;
    QLineEdit *remotePort;
    QLineEdit *magnetoPort;
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
    QLabel *label;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *gyroXResult;
    QLabel *gyroYResult;
    QLabel *gyroZResult;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *acceleroXResult;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *acceleroYResult;
    QLabel *label_19;
    QLabel *acceleroZResult;
    QFrame *line_5;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *actuatorResult;
    QPushButton *pbLevel1;
    QPushButton *pbLevel2;
    QPushButton *pbLevel3;
    QFrame *line_6;
    QLabel *label_23;
    QLabel *fl;
    QLabel *fr;
    QLabel *rl;
    QLabel *rr;
    QPushButton *pbDroite;
    QPushButton *pbGauche;
    QLabel *labelDemitour;
    QLabel *label_24;
    QLabel *timeResult;
    QPushButton *pbAvant;
    QPushButton *pbArriere;
    QPushButton *pbDt;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_22;
    QLabel *label_28;
    QLabel *odoXResult;
    QLabel *odoYResult;
    QLabel *fr_2;
    QLabel *fl_2;
    QLabel *rl_2;
    QLabel *rr_2;
    QFrame *line_8;
    QPushButton *pbBordure;
    QPushButton *pbRigole;
    QGraphicsView *graphicsView;
    QLabel *label_27;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *magnetoXResult;
    QLabel *magnetoYResult;
    QLabel *magnetoZResult;
    QPushButton *pbReset;
    QPushButton *pbAvantGauche;
    QPushButton *pbArriereGauche;
    QPushButton *pbAvantDroit;
    QPushButton *pbArierreDroit;
    QDoubleSpinBox *ratio;
    QSpinBox *maxWheel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(738, 616);
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
        img->setGeometry(QRect(130, 200, 161, 101));
        altitude = new QLabel(centralWidget);
        altitude->setObjectName(QStringLiteral("altitude"));
        altitude->setGeometry(QRect(30, 210, 21, 16));
        longitude = new QLabel(centralWidget);
        longitude->setObjectName(QStringLiteral("longitude"));
        longitude->setGeometry(QRect(20, 230, 47, 13));
        latitude = new QLabel(centralWidget);
        latitude->setObjectName(QStringLiteral("latitude"));
        latitude->setGeometry(QRect(30, 250, 31, 16));
        quality = new QLabel(centralWidget);
        quality->setObjectName(QStringLiteral("quality"));
        quality->setGeometry(QRect(10, 270, 47, 16));
        altitudeResult = new QLabel(centralWidget);
        altitudeResult->setObjectName(QStringLiteral("altitudeResult"));
        altitudeResult->setGeometry(QRect(70, 210, 47, 13));
        longitudeResult = new QLabel(centralWidget);
        longitudeResult->setObjectName(QStringLiteral("longitudeResult"));
        longitudeResult->setGeometry(QRect(70, 230, 47, 13));
        latitudeResult = new QLabel(centralWidget);
        latitudeResult->setObjectName(QStringLiteral("latitudeResult"));
        latitudeResult->setGeometry(QRect(70, 250, 47, 13));
        qualityResult = new QLabel(centralWidget);
        qualityResult->setObjectName(QStringLiteral("qualityResult"));
        qualityResult->setGeometry(QRect(70, 270, 47, 13));
        acceleroPort = new QLineEdit(centralWidget);
        acceleroPort->setObjectName(QStringLiteral("acceleroPort"));
        acceleroPort->setGeometry(QRect(170, 40, 51, 20));
        motorPort = new QLineEdit(centralWidget);
        motorPort->setObjectName(QStringLiteral("motorPort"));
        motorPort->setGeometry(QRect(280, 40, 51, 20));
        lidarPort = new QLineEdit(centralWidget);
        lidarPort->setObjectName(QStringLiteral("lidarPort"));
        lidarPort->setGeometry(QRect(60, 70, 51, 20));
        odoPort = new QLineEdit(centralWidget);
        odoPort->setObjectName(QStringLiteral("odoPort"));
        odoPort->setGeometry(QRect(280, 70, 51, 20));
        gyroPort = new QLineEdit(centralWidget);
        gyroPort->setObjectName(QStringLiteral("gyroPort"));
        gyroPort->setGeometry(QRect(170, 70, 51, 20));
        actuatorPort = new QLineEdit(centralWidget);
        actuatorPort->setObjectName(QStringLiteral("actuatorPort"));
        actuatorPort->setGeometry(QRect(60, 100, 51, 20));
        remotePort = new QLineEdit(centralWidget);
        remotePort->setObjectName(QStringLiteral("remotePort"));
        remotePort->setGeometry(QRect(280, 100, 51, 20));
        magnetoPort = new QLineEdit(centralWidget);
        magnetoPort->setObjectName(QStringLiteral("magnetoPort"));
        magnetoPort->setGeometry(QRect(170, 100, 51, 20));
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
        line->setGeometry(QRect(0, 180, 441, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(430, 0, 20, 311));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 20, 47, 13));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(460, 40, 47, 13));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(460, 60, 47, 13));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(460, 0, 47, 13));
        gyroXResult = new QLabel(centralWidget);
        gyroXResult->setObjectName(QStringLiteral("gyroXResult"));
        gyroXResult->setGeometry(QRect(480, 20, 47, 13));
        gyroYResult = new QLabel(centralWidget);
        gyroYResult->setObjectName(QStringLiteral("gyroYResult"));
        gyroYResult->setGeometry(QRect(480, 40, 47, 13));
        gyroZResult = new QLabel(centralWidget);
        gyroZResult->setObjectName(QStringLiteral("gyroZResult"));
        gyroZResult->setGeometry(QRect(480, 60, 47, 13));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(440, 80, 301, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(523, 0, 20, 91));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        acceleroXResult = new QLabel(centralWidget);
        acceleroXResult->setObjectName(QStringLiteral("acceleroXResult"));
        acceleroXResult->setGeometry(QRect(560, 20, 47, 13));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(540, 0, 47, 13));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(540, 20, 47, 13));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(540, 60, 47, 13));
        acceleroYResult = new QLabel(centralWidget);
        acceleroYResult->setObjectName(QStringLiteral("acceleroYResult"));
        acceleroYResult->setGeometry(QRect(560, 40, 47, 13));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(540, 40, 47, 13));
        acceleroZResult = new QLabel(centralWidget);
        acceleroZResult->setObjectName(QStringLiteral("acceleroZResult"));
        acceleroZResult->setGeometry(QRect(560, 60, 47, 13));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(610, 0, 20, 191));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(660, 0, 47, 13));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(630, 40, 31, 16));
        actuatorResult = new QLabel(centralWidget);
        actuatorResult->setObjectName(QStringLiteral("actuatorResult"));
        actuatorResult->setGeometry(QRect(660, 40, 47, 13));
        pbLevel1 = new QPushButton(centralWidget);
        pbLevel1->setObjectName(QStringLiteral("pbLevel1"));
        pbLevel1->setGeometry(QRect(330, 220, 75, 23));
        pbLevel2 = new QPushButton(centralWidget);
        pbLevel2->setObjectName(QStringLiteral("pbLevel2"));
        pbLevel2->setGeometry(QRect(330, 250, 75, 23));
        pbLevel3 = new QPushButton(centralWidget);
        pbLevel3->setObjectName(QStringLiteral("pbLevel3"));
        pbLevel3->setGeometry(QRect(330, 280, 75, 23));
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(0, 300, 741, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(520, 90, 47, 13));
        fl = new QLabel(centralWidget);
        fl->setObjectName(QStringLiteral("fl"));
        fl->setGeometry(QRect(450, 110, 16, 16));
        fr = new QLabel(centralWidget);
        fr->setObjectName(QStringLiteral("fr"));
        fr->setGeometry(QRect(520, 110, 16, 16));
        rl = new QLabel(centralWidget);
        rl->setObjectName(QStringLiteral("rl"));
        rl->setGeometry(QRect(450, 130, 16, 16));
        rr = new QLabel(centralWidget);
        rr->setObjectName(QStringLiteral("rr"));
        rr->setGeometry(QRect(520, 130, 16, 16));
        pbDroite = new QPushButton(centralWidget);
        pbDroite->setObjectName(QStringLiteral("pbDroite"));
        pbDroite->setGeometry(QRect(570, 250, 51, 23));
        pbGauche = new QPushButton(centralWidget);
        pbGauche->setObjectName(QStringLiteral("pbGauche"));
        pbGauche->setGeometry(QRect(450, 250, 51, 23));
        labelDemitour = new QLabel(centralWidget);
        labelDemitour->setObjectName(QStringLiteral("labelDemitour"));
        labelDemitour->setGeometry(QRect(660, 280, 71, 20));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(20, 290, 47, 13));
        timeResult = new QLabel(centralWidget);
        timeResult->setObjectName(QStringLiteral("timeResult"));
        timeResult->setGeometry(QRect(70, 290, 71, 16));
        pbAvant = new QPushButton(centralWidget);
        pbAvant->setObjectName(QStringLiteral("pbAvant"));
        pbAvant->setGeometry(QRect(510, 220, 51, 23));
        pbArriere = new QPushButton(centralWidget);
        pbArriere->setObjectName(QStringLiteral("pbArriere"));
        pbArriere->setGeometry(QRect(510, 280, 51, 23));
        pbDt = new QPushButton(centralWidget);
        pbDt->setObjectName(QStringLiteral("pbDt"));
        pbDt->setGeometry(QRect(510, 250, 51, 23));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(450, 200, 51, 16));
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(630, 280, 31, 21));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(450, 150, 16, 16));
        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(520, 150, 16, 16));
        odoXResult = new QLabel(centralWidget);
        odoXResult->setObjectName(QStringLiteral("odoXResult"));
        odoXResult->setGeometry(QRect(470, 150, 31, 16));
        odoYResult = new QLabel(centralWidget);
        odoYResult->setObjectName(QStringLiteral("odoYResult"));
        odoYResult->setGeometry(QRect(540, 150, 31, 16));
        fr_2 = new QLabel(centralWidget);
        fr_2->setObjectName(QStringLiteral("fr_2"));
        fr_2->setGeometry(QRect(540, 110, 31, 16));
        fl_2 = new QLabel(centralWidget);
        fl_2->setObjectName(QStringLiteral("fl_2"));
        fl_2->setGeometry(QRect(470, 110, 31, 16));
        rl_2 = new QLabel(centralWidget);
        rl_2->setObjectName(QStringLiteral("rl_2"));
        rl_2->setGeometry(QRect(470, 130, 31, 16));
        rr_2 = new QLabel(centralWidget);
        rr_2->setObjectName(QStringLiteral("rr_2"));
        rr_2->setGeometry(QRect(540, 130, 31, 16));
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setGeometry(QRect(440, 180, 301, 20));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        pbBordure = new QPushButton(centralWidget);
        pbBordure->setObjectName(QStringLiteral("pbBordure"));
        pbBordure->setGeometry(QRect(650, 200, 75, 23));
        pbRigole = new QPushButton(centralWidget);
        pbRigole->setObjectName(QStringLiteral("pbRigole"));
        pbRigole->setGeometry(QRect(650, 220, 75, 23));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 320, 701, 241));
        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(660, 90, 47, 13));
        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(630, 110, 16, 16));
        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(630, 130, 16, 16));
        label_31 = new QLabel(centralWidget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(630, 150, 16, 16));
        magnetoXResult = new QLabel(centralWidget);
        magnetoXResult->setObjectName(QStringLiteral("magnetoXResult"));
        magnetoXResult->setGeometry(QRect(640, 110, 61, 16));
        magnetoYResult = new QLabel(centralWidget);
        magnetoYResult->setObjectName(QStringLiteral("magnetoYResult"));
        magnetoYResult->setGeometry(QRect(640, 130, 61, 16));
        magnetoZResult = new QLabel(centralWidget);
        magnetoZResult->setObjectName(QStringLiteral("magnetoZResult"));
        magnetoZResult->setGeometry(QRect(640, 150, 61, 16));
        pbReset = new QPushButton(centralWidget);
        pbReset->setObjectName(QStringLiteral("pbReset"));
        pbReset->setGeometry(QRect(350, 40, 75, 23));
        pbAvantGauche = new QPushButton(centralWidget);
        pbAvantGauche->setObjectName(QStringLiteral("pbAvantGauche"));
        pbAvantGauche->setGeometry(QRect(450, 220, 51, 23));
        pbArriereGauche = new QPushButton(centralWidget);
        pbArriereGauche->setObjectName(QStringLiteral("pbArriereGauche"));
        pbArriereGauche->setGeometry(QRect(450, 280, 51, 23));
        pbAvantDroit = new QPushButton(centralWidget);
        pbAvantDroit->setObjectName(QStringLiteral("pbAvantDroit"));
        pbAvantDroit->setGeometry(QRect(570, 220, 51, 23));
        pbArierreDroit = new QPushButton(centralWidget);
        pbArierreDroit->setObjectName(QStringLiteral("pbArierreDroit"));
        pbArierreDroit->setGeometry(QRect(570, 280, 51, 23));
        ratio = new QDoubleSpinBox(centralWidget);
        ratio->setObjectName(QStringLiteral("ratio"));
        ratio->setGeometry(QRect(691, 250, 41, 22));
        ratio->setMaximum(100);
        ratio->setValue(1.67);
        maxWheel = new QSpinBox(centralWidget);
        maxWheel->setObjectName(QStringLiteral("maxWheel"));
        maxWheel->setGeometry(QRect(630, 250, 51, 22));
        maxWheel->setMaximum(127);
        maxWheel->setValue(127);
        MainWindow->setCentralWidget(centralWidget);
        line_5->raise();
        line_8->raise();
        line->raise();
        line_4->raise();
        leServerAddress->raise();
        gpsPort->raise();
        pbSendData->raise();
        pbConnection->raise();
        leDataToSend->raise();
        img->raise();
        altitude->raise();
        longitude->raise();
        latitude->raise();
        quality->raise();
        altitudeResult->raise();
        longitudeResult->raise();
        latitudeResult->raise();
        qualityResult->raise();
        acceleroPort->raise();
        motorPort->raise();
        lidarPort->raise();
        odoPort->raise();
        gyroPort->raise();
        actuatorPort->raise();
        remotePort->raise();
        magnetoPort->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        line_2->raise();
        label->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        gyroXResult->raise();
        gyroYResult->raise();
        gyroZResult->raise();
        line_3->raise();
        acceleroXResult->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        acceleroYResult->raise();
        label_19->raise();
        acceleroZResult->raise();
        label_20->raise();
        label_21->raise();
        actuatorResult->raise();
        pbLevel1->raise();
        pbLevel2->raise();
        pbLevel3->raise();
        line_6->raise();
        label_23->raise();
        fl->raise();
        fr->raise();
        rl->raise();
        rr->raise();
        pbDroite->raise();
        pbGauche->raise();
        labelDemitour->raise();
        label_24->raise();
        timeResult->raise();
        pbAvant->raise();
        pbArriere->raise();
        pbDt->raise();
        label_25->raise();
        label_26->raise();
        label_22->raise();
        label_28->raise();
        odoXResult->raise();
        odoYResult->raise();
        fr_2->raise();
        fl_2->raise();
        rl_2->raise();
        rr_2->raise();
        pbBordure->raise();
        pbRigole->raise();
        graphicsView->raise();
        label_27->raise();
        label_29->raise();
        label_30->raise();
        label_31->raise();
        magnetoXResult->raise();
        magnetoYResult->raise();
        magnetoZResult->raise();
        pbReset->raise();
        pbAvantGauche->raise();
        pbArriereGauche->raise();
        pbAvantDroit->raise();
        pbArierreDroit->raise();
        ratio->raise();
        maxWheel->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 738, 21));
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
        pbSendData->setText(QApplication::translate("MainWindow", "Envoyer", 0));
        pbConnection->setText(QApplication::translate("MainWindow", "Connexion", 0));
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
        lidarPort->setText(QApplication::translate("MainWindow", "3337", 0));
        odoPort->setText(QApplication::translate("MainWindow", "3335", 0));
        gyroPort->setText(QApplication::translate("MainWindow", "3340", 0));
        actuatorPort->setText(QApplication::translate("MainWindow", "3345", 0));
        remotePort->setText(QApplication::translate("MainWindow", "3338", 0));
        magnetoPort->setText(QApplication::translate("MainWindow", "3341", 0));
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
        label_12->setText(QApplication::translate("MainWindow", "Donn\303\251e", 0));
        label->setText(QApplication::translate("MainWindow", "X:", 0));
        label_13->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Z:", 0));
        label_15->setText(QApplication::translate("MainWindow", "Gyro", 0));
        gyroXResult->setText(QString());
        gyroYResult->setText(QString());
        gyroZResult->setText(QString());
        acceleroXResult->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "Accelero", 0));
        label_17->setText(QApplication::translate("MainWindow", "X:", 0));
        label_18->setText(QApplication::translate("MainWindow", "Z:", 0));
        acceleroYResult->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "Y:", 0));
        acceleroZResult->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "Actuator", 0));
        label_21->setText(QApplication::translate("MainWindow", "Tool:", 0));
        actuatorResult->setText(QString());
        pbLevel1->setText(QApplication::translate("MainWindow", "1", 0));
        pbLevel2->setText(QApplication::translate("MainWindow", "2", 0));
        pbLevel3->setText(QApplication::translate("MainWindow", "3", 0));
        label_23->setText(QApplication::translate("MainWindow", "Odo", 0));
        fl->setText(QString());
        fr->setText(QString());
        rl->setText(QString());
        rr->setText(QString());
        pbDroite->setText(QApplication::translate("MainWindow", "\342\206\222", 0));
        pbGauche->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        labelDemitour->setText(QApplication::translate("MainWindow", "Unused", 0));
        label_24->setText(QApplication::translate("MainWindow", "time", 0));
        timeResult->setText(QString());
        pbAvant->setText(QApplication::translate("MainWindow", "\342\206\221", 0));
        pbArriere->setText(QApplication::translate("MainWindow", "\342\206\223", 0));
        pbDt->setText(QApplication::translate("MainWindow", "\342\206\273", 0));
        label_25->setText(QApplication::translate("MainWindow", "Contr\303\264le", 0));
        label_26->setText(QApplication::translate("MainWindow", "etat:", 0));
        label_22->setText(QApplication::translate("MainWindow", "x:", 0));
        label_28->setText(QApplication::translate("MainWindow", "y:", 0));
        odoXResult->setText(QString());
        odoYResult->setText(QString());
        fr_2->setText(QApplication::translate("MainWindow", "0", 0));
        fl_2->setText(QApplication::translate("MainWindow", "0", 0));
        rl_2->setText(QApplication::translate("MainWindow", "0", 0));
        rr_2->setText(QApplication::translate("MainWindow", "0", 0));
        pbBordure->setText(QApplication::translate("MainWindow", "Bordure", 0));
        pbRigole->setText(QApplication::translate("MainWindow", "Rigole", 0));
        label_27->setText(QApplication::translate("MainWindow", "Magneto", 0));
        label_29->setText(QApplication::translate("MainWindow", "x:", 0));
        label_30->setText(QApplication::translate("MainWindow", "y:", 0));
        label_31->setText(QApplication::translate("MainWindow", "z:", 0));
        magnetoXResult->setText(QString());
        magnetoYResult->setText(QString());
        magnetoZResult->setText(QString());
        pbReset->setText(QApplication::translate("MainWindow", "Reset", 0));
        pbAvantGauche->setText(QApplication::translate("MainWindow", "\342\206\226", 0));
        pbArriereGauche->setText(QApplication::translate("MainWindow", "\342\206\231", 0));
        pbAvantDroit->setText(QApplication::translate("MainWindow", "\342\206\227", 0));
        pbArierreDroit->setText(QApplication::translate("MainWindow", "\342\206\230", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
