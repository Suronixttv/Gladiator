#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "datenbank.h"
#include "frmadminpanel.h"

namespace Ui {
class frmLogin;
}

class frmLogin : public QDialog
{
    Q_OBJECT

public:
    explicit frmLogin(QWidget *parent = nullptr);
    ~frmLogin();
    bool getLoggedIn();
    QString getUsername();

private slots:
    void on_btn_AddUser_clicked();

    void on_btn_Login_clicked();

    void on_btn_admin_clicked();

    void on_btn_logout_clicked();

private:
    Ui::frmLogin *ui;
    FrmAdminPanel *admin = new FrmAdminPanel;
    Datenbank gladiatordb;
    bool LoggedIn = false;

};

#endif // FRMLOGIN_H
