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
    ui->img->setPixmap(QPixmap(":icons/ICON_OZ_DISABLE").scaled(ui->img->width(),ui->img->height(),Qt::KeepAspectRatio));

    m_pRobot = new RobotInterface(ui);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    if(m_pRobot)
        delete m_pRobot;
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
    if(ui->pbConnection->text() == "Connexion")
        m_pRobot->connectRobot();
    else{
        ui->pbConnection->setText("Deconnexion");
        m_pRobot->desconect();
    }
}

/**
 * @brief MainWindow::on_pbSendData_clicked
 */
void MainWindow::on_pbSendData_clicked()
{
    m_pTCPConnection->SendData(ui->leDataToSend->text().toUtf8());

}

void MainWindow::on_pbDroite_clicked()
{
    ui->labelDemitour->setText("Demi tour in process");
    m_pRobot->PushButonRight();
    //ui->labelDemitour->setText("Unused");
}

void MainWindow::on_pbGauche_clicked()
{
    ui->labelDemitour->setText("Demi tour in process");
    m_pRobot->PushButonLeft();
    //ui->labelDemitour->setText("Unused");
}

void MainWindow::on_pbAvant_clicked()
{
    ui->labelDemitour->setText("Demi tour in process");
    m_pRobot->PushButonFront();
    ui->labelDemitour->setText("Unused");
}
