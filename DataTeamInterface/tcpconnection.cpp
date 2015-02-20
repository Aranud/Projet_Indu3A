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
    connect(m_pTcpSocket, SIGNAL(connected()), this, SIGNAL(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), this, SLOT(slotOnDisconnected()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), this, SIGNAL(slotDisconnected()));

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
/*********************************** METHOD ************************************/
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

    qDebug() << "Try to Connect From : " << m_pTcpSocket->peerName() << " ("  << m_sAddress << ":" << m_iPort << ")";
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
    if(p_baData.isEmpty())
        return false;

//    QByteArray baDataToSend;
//    baDataToSend.clear();

//    baDataToSend[0] = 0x4E;  // N
//    baDataToSend[1] = 0x41;  // A
//    baDataToSend[2] = 0x49;  // I
//    baDataToSend[3] = 0x4F;  // O
//    baDataToSend[4] = 0x30;  // 0
//    baDataToSend[5] = 0x31;  // 1
//    baDataToSend[6] = 0x01;  // ID  = 01)
//    baDataToSend[7] = 0x00;  // SIZE
//    baDataToSend[8] = 0x00;  // SIZE
//    baDataToSend[9] = 0x00;  // SIZE
//    baDataToSend[10] = 0x02;  // SIZE
//    baDataToSend[11] = 0x7F;  // Left
//    baDataToSend[12] = 0x7F;  // Right
//    baDataToSend[13] = 0x00;  // crc
//    baDataToSend[14] = 0x00;  // crc
//    baDataToSend[15] = 0x00;  // crc
//    baDataToSend[16] = 0x00;  // crc

    m_pTcpSocket->write(p_baData);

    qDebug() << p_baData.toHex() << " |---> Data Lenght To Write : " << m_pTcpSocket->bytesToWrite();

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
    qDebug() << "Connection Etablished From : " << m_pTcpSocket->peerName() << " ("  << m_sAddress << ":" << m_iPort << ")";
}

/**
 * @brief TCPConnection::slotOnDisconnected
 */
void TCPConnection::slotOnDisconnected()
{
    m_bIsConnectionEtablished = false;
    qDebug() << "Disconnect From : " << m_pTcpSocket->peerName() << " ("  << m_sAddress << ":" << m_iPort << ")";
}

/**
 * @brief TCPConnection::slotOnDataReceived
 */
void TCPConnection::slotOnDataReceived()
{
    QByteArray baDataReceived;
    baDataReceived.clear();

    qDebug() << "Something Received";

    baDataReceived = m_pTcpSocket->readAll();
    while(m_pTcpSocket->bytesAvailable())
        baDataReceived += m_pTcpSocket->readAll();

    qDebug() << "Data Received Result : " << baDataReceived.toHex();

    emit DataReceivedFromServer(baDataReceived);
}

/**
 * @brief TCPConnection::slotOnDataWritten
 * @param p_iDataLength
 */
void TCPConnection::slotOnDataWritten(qint64 p_iDataLength)
{
    qDebug() << "Number Of Byte Written ---> " << p_iDataLength;
}
