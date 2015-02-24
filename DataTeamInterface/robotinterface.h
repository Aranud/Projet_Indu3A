#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QObject>
#include "protocole.h"
#include "gps.h"
#include "actuator.h"
#include "gyro.h"
#include "lidar.h"
#include "joystick.h"
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

public:
    RobotInterface(Ui::MainWindow* ui);
    ~RobotInterface();
    bool connectRobot();

public slots:
    void slotOnGpsDataAvailable();
    void slotOnGyroDataAvailable();
};

#endif // ROBOTINTERFACE_H
