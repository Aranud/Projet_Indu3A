#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QObject>
#include "protocole.h"
#include "gps.h"
#include "actuator.h"
#include "gyro.h"
#include "lidar.h"
#include "joystick.h"
#include "accelero.h"
#include "magneto.h"
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
    Magneto* m_pMagneto;

public:
    RobotInterface(Ui::MainWindow* ui);
    ~RobotInterface();
    bool connectRobot();

public slots:
    void slotOnGpsDataAvailable();
    void slotOnGyroDataAvailable();
    void slotOnActuatorDataAvailable();
    void slotOnAcceleroDataAvailable();
    void slotOnMagnetoDataAvailable();
};

#endif // ROBOTINTERFACE_H
