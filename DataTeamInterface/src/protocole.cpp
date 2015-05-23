#include "protocole.h"

/**
 * @brief Protocole::Protocole - Constructor
 * @param p_sName
 * @param parent
 */
Protocole::Protocole(QString p_sName, QObject *parent) :
    QObject(parent)
{
    if(p_sName.isEmpty())
        m_sDefautName = DEFAUT_NAME;
    else
        m_sDefautName = p_sName;
}

/**
 * @brief Protocole::~Protocole - Desctructor
 */
Protocole::~Protocole()
{

}

/*******************************************************************************/
/*********************************** METHOD ************************************/
/*******************************************************************************/

/**
 * @brief Protocole::FormateCommand -
 * @param p_eIDCommand
 * @param p_sValueCommand
 * @return
 */
QByteArray Protocole::FormateCommand(eIDCommand p_eIDCommand, QByteArray p_baValueCommand)
{
    const QChar cFillChar = 0x00;  //Zero non significatif

    QByteArray baDataToSend;
    baDataToSend.clear();

//    baDataToSend[0] = 0x4E;  // N
//    baDataToSend[1] = 0x41;  // A
//    baDataToSend[2] = 0x49;  // I
//    baDataToSend[3] = 0x4F;  // O
//    baDataToSend[4] = 0x30;  // 0
//    baDataToSend[5] = 0x31;  // 1
    baDataToSend.append(m_sDefautName);

//    baDataToSend[6] = 0x01;  // ID  = 01)
    baDataToSend.append((int)p_eIDCommand);

//    baDataToSend[7] = 0x00;  // SIZE
//    baDataToSend[8] = 0x00;  // SIZE
//    baDataToSend[9] = 0x00;  // SIZE
//    baDataToSend[10] = 0x02;  // SIZE
    baDataToSend.append(QString("%1").arg(p_baValueCommand.size(), 4, 10, cFillChar));

//    baDataToSend[11] = 0x7F;  // Left
//    baDataToSend[12] = 0x7F;  // Right
    baDataToSend.append(p_baValueCommand);

//    baDataToSend[13] = 0x00;  // CRC
//    baDataToSend[14] = 0x00;  // CRC
//    baDataToSend[15] = 0x00;  // CRC
//    baDataToSend[16] = 0x00;  // CRC
    baDataToSend.append(cFillChar);
    baDataToSend.append(cFillChar);
    baDataToSend.append(cFillChar);
    baDataToSend.append(cFillChar);

    return baDataToSend;
}

/**
 * @brief Protocole::ExtractData
 * @param p_baData
 * @return
 */
QByteArray Protocole::ExtractData(QByteArray p_baData)
{
    int iSize = p_baData.mid(7, 4).toHex().toInt(0, 16);
    return p_baData.mid(11, iSize);
}

/**
 * @brief Protocole::ReverseData
 * @param p_baData
 * @return
 */
QByteArray Protocole::ReverseData(QByteArray p_baData)
{
    QByteArray baData;
    for(int iIncrement = p_baData.length() - 1; iIncrement >= 0; iIncrement--)
        baData += p_baData.mid(iIncrement, 1);
    return baData;
}

/*******************************************************************************/
/**************************** ACCESSOR - MUTATOR *******************************/
/*******************************************************************************/

/**
 * @brief Protocole::getDefautName
 * @return
 */
QString Protocole::getDefautName() const
{
    return m_sDefautName;
}

/**
 * @brief Protocole::setDefautName
 * @param sDefautName
 */
void Protocole::setDefautName(const QString &p_sDefautName)
{
    m_sDefautName = p_sDefautName;
}
