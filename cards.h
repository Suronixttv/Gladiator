#ifndef CARDS_H
#define CARDS_H

#include "QString"


class Cards
{
public:
    Cards();
    void setKlasse(QString Klassenname);
    QString getKlasse();
    void setID(int ID);
    int getID();

private:
    QString Klasse;
    int cardID;

};

#endif // CARDS_H
