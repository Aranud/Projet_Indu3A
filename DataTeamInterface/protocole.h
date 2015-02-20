#ifndef PROTOCOLE_H
#define PROTOCOLE_H

#include <QObject>
#include <QDebug>

#include "global.h"

class Protocole : public QObject
{
    Q_OBJECT
private:
    QString m_sDefautName;

public:
    explicit Protocole(QString p_sName = "", QObject *parent = 0);
    ~Protocole();

    QByteArray FormateCommand(eIDCommand p_eIDCommand, QByteArray p_baValueCommand);
    QByteArray ExtractData(QByteArray p_baData);

    QString getDefautName() const;
    void setDefautName(const QString &p_sDefautName);

signals:

public slots:

};

#endif // PROTOCOLE_H
