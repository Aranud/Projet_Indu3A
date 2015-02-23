#include "robotinterface.h"
#include "gps.h"

RobotInterface::RobotInterface()
{
    //*******Accelero*******//
    qint16 accX,accY,accZ;
    //new accelero

    //*******Actuator*******//
    QByteArray tool;
    //new actuator

    //*********GPS*********//
    double time,lat,lon,alt,speed;
    QByteArray unit,nbrSat,quality;
    //new gps

    //********Lidar*********//

    //*******Motors********//

    //*********Odo*********//
    bool fr,fl,rr,rl;
    //new odo

    //*******Remote*******//

}

RobotInterface::~RobotInterface()
{

}

