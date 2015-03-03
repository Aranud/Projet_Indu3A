#ifndef IAMOTEUR_H
#define IAMOTEUR_H

#include <QObject>

class IAMoteur : public QObject
{
    Q_OBJECT
public:
    explicit IAMoteur(QObject *parent = 0);
    ~IAMoteur();

    Lidar *m_pLidar;
    Motor *m_pMotor;

    void MachineEtat();

signals:

public slots:

};

#endif // IAMOTEUR_H
