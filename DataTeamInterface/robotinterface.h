#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QObject>
#include "protocole.h"
#include "gps.h"
#include "actuator.h"
#include "gyro.h"
#include "lidar.h"
#include "ui_mainwindow.h"

class RobotInterface : public QObject
{
    Q_OBJECT

    private:
       Ui::MainWindow* m_pUi;
        Protocole* m_pProtocole;
        GPS *m_pGps;

public:
    RobotInterface(Ui::MainWindow* ui);
    ~RobotInterface();
    bool connectRobot();

public slots:
    void slotOnGpsDataAvailable();
};

#endif // ROBOTINTERFACE_H
