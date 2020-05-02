#include "frmssh.h"
#include "ui_frmssh.h"

FrmSSH::FrmSSH(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmSSH)
{
    ui->setupUi(this);
}

FrmSSH::~FrmSSH()
{
    delete ui;
}




void FrmSSH::on_Schwert_btn_clicked()
{
    this->Winner = GameObj->PSchwert();
    if (Winner == 1){

        this->FrmSSH::close();

    }else if(Winner == 2){

        this->FrmSSH::close();

    }else if(Winner == 0){

        ui->SSHAusgabe->addItem("Draw bitte erneut Spielen");

    }

}

void FrmSSH::on_Schild_btn_clicked()
{
    this->Winner = GameObj->PSchild();

    if(this->Winner == 1){
        this->FrmSSH::close();

    }else if(Winner == 2){
        this->FrmSSH::close();

    }else if(Winner == 0){

        ui->SSHAusgabe->addItem("Draw bitte erneut Spielen");

    }

}

void FrmSSH::on_Hammer_btn_clicked()
{
    this->Winner = GameObj->PHammer();

    if (Winner == 1){

        this->FrmSSH::close();

    }else if(Winner == 2){

        this->FrmSSH::close();

    }else if(Winner == 0){

        ui->SSHAusgabe->addItem("Draw bitte erneut Spielen");

    }


}

void FrmSSH::closeEvent(QCloseEvent *event){

    emit on_FrmSSH_closed(this->Winner);
    ui->SSHAusgabe->clear();
    this->Winner = 0;

}

