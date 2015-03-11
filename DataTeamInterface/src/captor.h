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

private:
    bool m_IsConnected;

public:
    explicit Captor();
    ~Captor();

    bool ConnectCaptor(QString p_sAddresse, qint16 p_iPort);
    void DisconnectCaptor();
    bool SendData(QByteArray p_pDataToSend);
    QByteArray ReverseData(QByteArray p_baData);

    bool getIsConnected();
    void setIsConnected(bool IsConnected);

    eIDCommand getEIDCommand() ;
    void setEIDCommand(eIDCommand &eIDCommand);

signals:
    void emitDataExtractedAvailable(QByteArray);
    void emitDataAvailable();
    void emitConnected();

public slots:

protected slots:
    void slotOnConnection();
    void slotOnDisconnection();
    void slotOnDataReceivedFromServer(QByteArray p_baData);
    virtual void slotOnDataExtractedReady(QByteArray p_baDataExtracted);

};

#endif // CAPTOR_H
