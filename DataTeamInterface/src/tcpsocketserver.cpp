#include "tcpsocketserver.h"

/**
 * @brief TCPSocketServer::TCPSocketServer
 * @param parent
 */
TCPSocketServer::TCPSocketServer(QObject *parent) :
    QObject(parent)
{
    m_pTCPSocketServer = new QTcpServer(parent);
    m_pTCPSocketClient = NULL;

    m_pTCPSocketServer->listen(QHostAddress::Any, 22496);

    connect(m_pTCPSocketServer, SIGNAL(newConnection()), this, SLOT(slotOnConnectionPending()));
}

/**
 * @brief TCPSocketServer::~TCPSocketServer
 */
TCPSocketServer::~TCPSocketServer()
{
    m_pTCPSocketServer->close();

    if(m_pTCPSocketServer)
        m_pTCPSocketServer->deleteLater();
}

/***********************************************************/
/*************************** SLOT **************************/
/***********************************************************/

/**
 * @brief TCPSocketServer::slotOnConnectionPending
 */
void TCPSocketServer::slotOnConnectionPending()
{
    if(m_pTCPSocketServer->hasPendingConnections())
        if((m_pTCPSocketClient = m_pTCPSocketServer->nextPendingConnection()))
            connect(m_pTCPSocketClient, SIGNAL(readyRead()), this, SLOT(slotOnClientSendData()));
}

/**
 * @brief TCPSocketServer::slotOnClientSendData
 */
void TCPSocketServer::slotOnClientSendData()
{
    emit emitDataReceived(m_pTCPSocketClient->readAll());
}
