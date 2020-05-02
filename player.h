#ifndef PLAYER_H
#define PLAYER_H
#include "QString"
#include "datenbank.h"

class Player
{
public:
    Player();
    void setName(QString Username);
    void setAdmin(bool admin);
    void setWins(int W);
    void setLoses(int L);
    void setHP(int hp);
    void setAuswahl(int i);

    QString getUsername();
    int  getWins();
    int  getLoses();
    int  getHP();
    int  getAuswahl();




private:
    QString Name;
    QString Passwort;
    int Wins;
    int Loses;
    int HP = 7;
    int Auswahl;
    Datenbank gladiatordb;




};

#endif // PLAYER_H
