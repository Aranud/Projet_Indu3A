#include "tcpconnection.h"

/**
 * @brief TCPConnection::TCPConnection
 * @param parent
 */
TCPConnection::TCPConnection(QObject *parent) :
    QObject(parent)
{
    m_pTcpSocket = new QTcpSocket();
    m_sAddress.clear();
    m_iPort = 0;

    m_bIsConnectionEtablished = false;

    connect(m_pTcpSocket, SIGNAL(connected()), this, SLOT(slotOnConnected()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), this, SLOT(slotOnDisconnected()));

    connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(slotOnDataReceived()));
    connect(m_pTcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(slotOnDataWritten(qint64)));
}

/**
 * @brief TCPConnection::~TCPConnection
 */
TCPConnection::~TCPConnection()
{

}

/*******************************************************************************/
/********************************* METHOD **************************************/
/*******************************************************************************/

/**
 * @brief TCPConnection::ConnectFromServer
 * @param p_sAddress
 * @param p_iPort
 * @return
 */
bool TCPConnection::ConnectFromServer(QString p_sAddress, int p_iPort)
{
    if(m_bIsConnectionEtablished)       // Connection already etablished
        return true;

    if(p_sAddress.isEmpty() || p_iPort <= MIN_PORT_ALLOW)
        return false;

    m_pTcpSocket->connectToHost(p_sAddress, p_iPort);

    m_sAddress = p_sAddress;    // Keep a trace
    m_iPort = p_iPort;          // Keep a trace

    //qDebug() << "Try to Connect From : " << m_pTcpSocket->peerName() << " ("  << m_sAddress << ":" << m_iPort << ")";

    return true;
}

/**
 * @brief TCPConnection::DisconnectFromServer
 * @return
 */
bool TCPConnection::DisconnectFromServer()
{
    m_pTcpSocket->disconnectFromHost();
    return true;
}

/**
 * @brief TCPConnection::SendData
 * @param p_baData
 * @return
 */
bool TCPConnection::SendData(QByteArray p_baData)
{
    if(p_baData.isEmpty() || !m_bIsConnectionEtablished)
        return false;

    m_pTcpSocket->write(p_baData);
    return true;
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief TCPConnection::slotOnConnected
 */
void TCPConnection::slotOnConnected()
{
    m_bIsConnectionEtablished = true;
    //qDebug() << "Connection Etablished From : " << m_pTcpSocket->peerName() << " ("  << m_sAddress << ":" << m_iPort << ")";
    emit Connected();
}

/**
 * @brief TCPConnection::slotOnDisconnected
 */
void TCPConnection::slotOnDisconnected()
{
    m_bIsConnectionEtablished = false;
    //qDebug() << "Disconnect From : " << m_pTcpSocket->peerName() << " ("  << m_sAddress << ":" << m_iPort << ")";
    emit Disconnected();
}

/**
 * @brief TCPConnection::slotOnDataReceived
 */
void TCPConnection::slotOnDataReceived()
{
    QByteArray baDataReceived;
    baDataReceived.clear();

    baDataReceived = m_pTcpSocket->readAll();
    while(m_pTcpSocket->bytesAvailable())
        baDataReceived += m_pTcpSocket->readAll();

    emit DataReceivedFromServer(baDataReceived);
}

/**
 * @brief TCPConnection::slotOnDataWritten
 * @param p_iDataLength
 */
void TCPConnection::slotOnDataWritten(qint64 p_iDataLength)
{
    Q_UNUSED(p_iDataLength);
    //qDebug() << "Number Of Byte Written ---> " << p_iDataLength;
}
