#include "frmlogin.h"
#include "ui_frmlogin.h"

frmLogin::frmLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmLogin)
{
    ui->setupUi(this);
    ui->btn_admin->hide();
    this->gladiatordb.connOpen();
    this->gladiatordb.connClose();
}

frmLogin::~frmLogin()
{
    delete ui;
}

void frmLogin::on_btn_AddUser_clicked()
{
    QString Username = ui->le_Username_add->text();
    QString Name = ui->le_Name_add->text();
    QString Pw = ui->le_Pw_add->text();
    QString Pwcheck = ui->le_PW2_add->text();

    if(Pw == Pwcheck){

        this->gladiatordb.addUser(Username,Name,Pw,false);

    }else{

        QMessageBox msgbox;
        msgbox.setText("Die Passwörter sind nicht identisch");
        msgbox.exec();
    }

}

void frmLogin::on_btn_Login_clicked()
{
    QMessageBox Login;
    QString Username = ui->le_User_Login->text();
    QString Pw = ui->le_Passwort_Login->text();

    this->LoggedIn = this->gladiatordb.Login(Username,Pw);

    if(LoggedIn == true){

        Login.setText("Erfolgreich eingeloggt!");
        Login.exec();

    }else if (LoggedIn == false) {

        Login.setText("Login fehlgeschlagen!");
        Login.exec();
    }

    bool admin = this->gladiatordb.checkAdmin();

    if(admin == true && ui->btn_admin->isHidden() == true){

        ui->btn_admin->show();

    }else if (admin == false && ui->btn_admin->isHidden() == false) {

        ui->btn_admin->hide();
}

}

void frmLogin::on_btn_admin_clicked()
{

    this->admin->show();
}

void frmLogin::on_btn_logout_clicked()
{

    gladiatordb.Logout();
    this->LoggedIn = false;

    if(ui->btn_admin->isHidden() == false){

        ui->btn_admin->hide();

    }

}

bool frmLogin::getLoggedIn(){

    return(this->LoggedIn);
}

QString frmLogin::getUsername(){

    return(this->gladiatordb.getUsername());
}
