#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QTcpSocket>

#define MIN_PORT_ALLOW 1000

class TCPConnection : public QObject
{
    Q_OBJECT
public:
    explicit TCPConnection(QObject *parent = 0);
    ~TCPConnection();

    bool ConnectFromServer(QString p_sAddress, int p_iPort);
    bool DisconnectFromServer();

    bool SendData(QByteArray p_baData);

private:
    QTcpSocket* m_pTcpSocket;
    QString m_sAddress;
    int m_iPort;
    bool m_bIsConnectionEtablished;

signals:
    void Connected();
    void Disconnected();
    void DataReceivedFromServer(QString);

public slots:
    void OnConnected();
    void OnDisconnected();
    void OnDataReceived();

    void OnDataWritten(qint64 p_iDataLength);
};

#endif // TCPCONNECTION_H
