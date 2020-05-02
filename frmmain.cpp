#include "frmmain.h"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::on_btn_Singleplayer_clicked()
{
   if(this->login->getLoggedIn() == true){

    this->maingame->setUsername(this->login->getUsername());
    this->maingame->setWindowFlags(Qt::FramelessWindowHint);
    this->maingame->setWindowState(this->maingame->windowState() | Qt::WindowFullScreen);
    this->maingame->show();
    this->maingame->activateWindow();

   }else if(this->login->getLoggedIn() == false){
       QMessageBox msg;
       msg.setText("Sie müssen sich erst Einloggen");
       msg.exec();
   }

}

void FrmMain::on_btn_Multiplayer_clicked()
{
    this->wip->show();

}


void FrmMain::on_btn_Login_clicked()
{
    this->login->setWindowTitle("Login");
    this->login->show();

}


void FrmMain::on_btn_Highscore_clicked()
{
    this->highscore->setWindowTitle("Highscorelist");
    this->highscore->show();
}


void FrmMain::on_btn_Help_clicked()
{
    this->wip->show();
}

void FrmMain::on_btn_close_clicked()
{

    FrmMain::close();

}
