#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QList>
#include <QSignalMapper>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "protocole.h"
#include "gps.h"
#include "actuator.h"
#include "gyro.h"
#include "lidar.h"
//#include "joystick.h"
#include "accelero.h"
#include "magneto.h"
#include "odo.h"
#include "motor.h"
#include "ui_mainwindow.h"
#include "iamoteur.h"
#include "tcpsocketserver.h"

class RobotInterface : public QObject
{
    Q_OBJECT

private:
    Ui::MainWindow* m_pUi;
    QGraphicsScene* m_pGraphScene;
    QPoint* m_pPoint;
    Protocole* m_pProtocole;

    QList<Captor*> m_lstCaptors;

    QSignalMapper* m_pSignalConnectionMapper;
    QSignalMapper* m_pSignalCaptorMapper;

    GPS *m_pGps;
    Gyro *m_pGyro;
    //Joystick* m_pJoystick;
    Actuator *m_pActuator;
    Accelero *m_pAccelero;
    Lidar *m_pLidar;
    Odo *m_pOdo;
    Motor *m_pMotor;
    Magneto* m_pMagneto;

    bool m_bRr,m_bRl,m_bFr,m_bFl;
    //Remote *m_pRemote;

    int m_iCompteur;

    QTimer* m_pTimer;
    bool m_bDraw;

    eDirection m_eDirection;
    IAMoteur* m_pIAMoteur;

    TCPSocketServer* m_pTCPSocketServer;

    void slotOnGpsDataAvailable();
    void slotOnGyroDataAvailable();
    void slotOnActuatorDataAvailable();
    void slotOnAcceleroDataAvailable();
    void slotOnLidarDataAvailable();
    void slotOnMagnetoDataAvailable();
    void slotOnOdoDataAvailable();
    void slotOnRemoteDataAvailable();
    void slotOnMotorDataAvailable();

public:
    RobotInterface(Ui::MainWindow* ui);
    ~RobotInterface();
    bool connectRobot();
    void pushLevel1();
    void pushButton(int button);
    void P_valueChanged(double dKp);
    void I_valueChanged(double dKi);
    void D_valueChanged(double dKd);

public slots:   
    void slotTimeOut();
    void slotOnCaptorSignals(int p_iValue);
    void slotOnConectedCaptorReady(int p_iValue);
    void slotOnRigolEnd();
    void slotOnReceivedFromIPAD(QString p_sData);

private slots:
    void on_P_valueChanged(double arg1);
    void on_I_valueChanged(double arg1);
    void on_D_valueChanged(double arg1);
};

#endif // ROBOTINTERFACE_H
