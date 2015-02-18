#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpconnection.h"
#include "protocole.h"
#include "joystick.h"

#include "global.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TCPConnection* m_pTCPConnection;
    Joystick* m_pJoystick;
    Protocole* m_pProtocole;

    bool m_bIsConnectionEtablished;

public slots:
    void slotOnConnection();
    void slotOnDisconnection();
    void slotOnDataReceived(QString p_sDataReceived);
    void slotOnJoystickTouch(QByteArray p_baData);

private slots:
    void on_pbConnection_clicked();
    void on_pbSendData_clicked();
};

#endif // MAINWINDOW_H
