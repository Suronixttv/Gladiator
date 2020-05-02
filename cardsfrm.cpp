#include "cardsfrm.h"
#include "ui_cardsfrm.h"

Cardsfrm::Cardsfrm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cardsfrm)
{
    ui->setupUi(this);
    ui->lbl_card->setScaledContents(true);

}

Cardsfrm::~Cardsfrm()
{
    delete ui;
}


void Cardsfrm::setCardid(int id){


    QPixmap image;
    switch(id){

    case 1:
        image.load(":/images/images/Blaues Team Bounty Hunter.png");
        ui->lbl_card->setPixmap(image);

        break;
    case 2:
        image.load(":/images/images/Blaues Team Guardian.png");
        ui->lbl_card->setPixmap(image);
        break;
    case 3:
        image.load(":/images/images/Blaues Team Vikinger.png");
        ui->lbl_card->setPixmap(image);
        break;
    case 4:
        image.load(":/images/images/Blaues Team King Arthur.png");
        ui->lbl_card->setPixmap(image);
        break;
    case 5:
        image.load(":/images/images/Blaues Team God Of Nature.png");
        ui->lbl_card->setPixmap(image);
        break;
    case 6:
        image.load(":/images/images/Blaues Team Mechaknight.png");
        ui->lbl_card->setPixmap(image);
        break;
    case 7:
        image.load(":/images/images/Blaues Team Robin Hood.png");
        ui->lbl_card->setPixmap(image);
        break;

    }

}
