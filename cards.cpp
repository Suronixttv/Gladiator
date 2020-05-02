#include "cards.h"

Cards::Cards()
{

}

void Cards::setKlasse(QString Klassenname){

    this->Klasse=Klassenname;
}

QString Cards::getKlasse(){

    return(this->Klasse);
}

int Cards::getID(){

    return (this->cardID);
}

void Cards::setID(int i){

    this->cardID = i;

}


