#include "player.h"

Player::Player()
{

}

void Player::setName(QString Username){

    this->Name = Username;

}

void Player::setWins(int W){

    qDebug()<<"Player::Wins W = " + QString::number(W) + "Name:" + this->Name;
    gladiatordb.setWins(W,this->Name);

}

void Player::setLoses(int L){

    qDebug()<<"Player::setLoses L = " + QString::number(L) + "Name:" + this->Name;
    gladiatordb.setLoses(L,this->Name);


}

void Player::setHP(int hp){

    this->HP = hp;

}

void Player::setAuswahl(int i){

   this->Auswahl = i;

}

int Player::getWins(){

    qDebug("In player.cpp");
    this->Wins = gladiatordb.getWins(this->Name);

    return(this->Wins);
}

int Player::getLoses(){

    this->Loses = gladiatordb.getLoses(this->Name);

    return(this->Loses);

}

int Player::getHP(){



    return(this->HP);
}

int Player::getAuswahl(){


    return(this->Auswahl);
}

QString Player::getUsername(){

    return(this->Name);
}

