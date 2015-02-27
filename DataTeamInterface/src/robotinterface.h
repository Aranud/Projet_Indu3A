#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QObject>
#include <QTimer>

#include "protocole.h"
#include "gps.h"
#include "actuator.h"
#include "gyro.h"
#include "lidar.h"
#include "joystick.h"
#include "accelero.h"
#include "magneto.h"
#include "odo.h"
#include "motor.h"
#include "ui_mainwindow.h"

class RobotInterface : public QObject
{
    Q_OBJECT

private:
    Ui::MainWindow* m_pUi;
    Protocole* m_pProtocole;
    GPS *m_pGps;
    Gyro *m_pGyro;
    Joystick* m_pJoystick;
    Actuator *m_pActuator;
    Accelero *m_pAccelero;
    Lidar *m_pLidar;
    //Magneto *m_pMagneto;
    Odo *m_pOdo;
    Motor *m_pMotor;
    //Remote *m_pRemote;
    Magneto* m_pMagneto;
    int m_iCompteur;

    QTimer* m_pTimer;

    eDirection m_eDirection;

public:
    RobotInterface(Ui::MainWindow* ui);
    ~RobotInterface();
    bool connectRobot();
    void PushButonRight();
    void PushButonLeft();
    void PushButonFront();
public slots:
    void slotOnGpsDataAvailable();
    void slotOnGyroDataAvailable();
    void slotOnActuatorDataAvailable();
    void slotOnAcceleroDataAvailable();
    void slotOnLidarDataAvailable();
    void slotOnMagnetoDataAvailable();
    void slotOnOdoDataAvailable();
    void slotOnRemoteDataAvailable();
    void slotTimeOut();
};

#endif // ROBOTINTERFACE_H
