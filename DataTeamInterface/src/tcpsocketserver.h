#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TCPSocketServer : public QObject
{
    Q_OBJECT
private:
    QTcpServer* m_pTCPSocketServer;
    QTcpSocket* m_pTCPSocketClient;

public:
    explicit TCPSocketServer(QObject *parent = 0);
    ~TCPSocketServer();

signals:
    void emitDataReceived(QString);

public slots:
    void slotOnConnectionPending();
    void slotOnClientSendData();
};

#endif // WEBSOCKETSERVER_H
