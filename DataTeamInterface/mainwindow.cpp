#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->img->setPixmap(QPixmap("img2.png").scaled(ui->img->width(),ui->img->height(),Qt::KeepAspectRatio));

    m_pRobot = new RobotInterface(ui);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief MainWindow::slotOnConnection
 */
void MainWindow::slotOnConnection()
{
    m_bIsConnectionEtablished = true;
    ui->pbConnection->setText("Disconnect");
}

/**
 * @brief MainWindow::slotOnDisconnection
 */
void MainWindow::slotOnDisconnection()
{
    m_bIsConnectionEtablished = false;
    ui->pbConnection->setText("Connect");
}

/**
 * @brief MainWindow::slotOnDataReceived
 * @param p_sDataReceived
 */
void MainWindow::slotOnDataReceived(QString p_sDataReceived)
{
    Q_UNUSED(p_sDataReceived);
}

/**
 * @brief MainWindow::slotOnJoystickTouch
 * @param p_baData
 */
void MainWindow::slotOnJoystickTouch(QByteArray p_baData)
{
    QByteArray baCommandFormatted;
    baCommandFormatted.clear();

    baCommandFormatted = m_pProtocole->FormateCommand(eIDCommmandMotors, p_baData);

    qDebug() << baCommandFormatted;

    m_pTCPConnection->SendData(baCommandFormatted);
}

/*******************************************************************************/
/*********************************** SLOT BUTTON *******************************/
/*******************************************************************************/

/**
 * @brief MainWindow::on_pbConnection_clicked
 */
void MainWindow::on_pbConnection_clicked()
{
   m_pRobot->connectRobot();
}

/**
 * @brief MainWindow::on_pbSendData_clicked
 */
void MainWindow::on_pbSendData_clicked()
{
    m_pTCPConnection->SendData(ui->leDataToSend->text().toUtf8());
}
