#include "frmadminpanel.h"
#include "ui_frmadminpanel.h"

FrmAdminPanel::FrmAdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmAdminPanel)
{
    ui->setupUi(this);
}

FrmAdminPanel::~FrmAdminPanel()
{
    delete ui;
}

void FrmAdminPanel::on_btn_addUser_clicked()
{
    QString Username = ui->le_Username->text();
    QString Name = ui->le_Name->text();
    QString Pw = ui->le_Passwort->text();
    QString Pwcheck = ui->le_Passwort_2->text();

    bool admin = ui->checkBox->isChecked();


    if(Pw == Pwcheck){

        this->gladiatordb.addUser(Username,Name,Pw,admin);

    }else{

        QMessageBox msgbox;
        msgbox.setText("Die Passwörter sind nicht identisch");
        msgbox.exec();

    }

}
