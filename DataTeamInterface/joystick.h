#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>
#include "simplexbox360controller.h"

class Joystick : public QObject
{
    Q_OBJECT
private:
    SimpleXbox360Controller* m_pController;
    float m_fOldStickValue;

public:
    explicit Joystick(QObject *parent = 0);

signals:
    void dataReceivedFromStick(QByteArray);

public slots:
    void slotOnControllerConntected(unsigned int p_iControllerNum);
    void slotOnControllerDisconntected(unsigned int p_iControllerNum);
    void slotOnEvent(SimpleXbox360Controller::InputState p_InputState);

};

#endif // JOYSTICK_H
