#ifndef CAPTOR_H
#define CAPTOR_H

#include <QObject>
#include "global.h"
#include "tcpconnection.h"
#include "protocole.h"

class Captor : public QObject
{
    Q_OBJECT
protected:
    TCPConnection* m_pTCPConnection;
    Protocole* m_pProtocole;
    eIDCommand m_eIDCommand;

    bool m_bIsConnectionEtablished;

public:
    explicit Captor(eIDCommand p_eIDCommand, QObject *parent = 0);
    ~Captor();

    virtual bool ConnectCaptor(QString p_sAddresse, qint16 p_iPort);
    virtual void DisconnectCaptor();
    virtual bool SendData(QByteArray p_pDataToSend);

signals:
    void emitDataExtractedAvailable(QString);
    void emitDataAvailable(QString);
public slots:

protected slots:
    void slotOnDataReceivedFromServer(QByteArray p_baData);
    virtual void slotOnDataExtractedReady(QString p_sDataExtracted);

};

#endif // CAPTOR_H
