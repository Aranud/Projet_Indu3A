#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QObject>

class RobotInterface : public QObject
{
    Q_OBJECT
public:
    RobotInterface();
    ~RobotInterface();
};

#endif // ROBOTINTERFACE_H
