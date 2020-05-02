#ifndef GLADIATORGAME_H
#define GLADIATORGAME_H
#include <QString>
#include <QDebug>
#include <QVector>
#include "player.h"
#include "datenbank.h"
#include "cards.h"

class gladiatorgame
{
public:
    gladiatorgame();
    void SetupGame();
    void setBluePlayer(QString Username);
    void setRedPlayer();
    void setBluePlayerAuswahl(int i);
    void setRedPlayerAuswhl(int i);
    void KIauswahl();
    void KICardsDelete(int i);
    void ResetPlayerHP();
    void setWinner(int i);
    void setLoser(int i);



    int getRedPlayerHP();
    int getBluePlayerHP();
    int getRedPlayerAuswahl();
    int getBluePlayerAuswahl();
    int getBluePlayerWins();
    int getBluePlayerLoses();
    int getcardfight(int DelID);
    int KampfAuswahl();
    QString getCardName(int id);
    QString getKampfNamen();

    //SSH Funktionen
    void setSSHLoserHP(int w);



private:
    Player Blue_Player;
    Player Red_Player;
    int KICards[7];
    int SSHWinner = 0;
    Datenbank gladiatordb;


    Cards card1;
    Cards card2;
    Cards card3;
    Cards card4;
    Cards card5;
    Cards card6;
    Cards card7;
    Cards card8;
    Cards card9;
    Cards card10;
    Cards card11;
    Cards card12;
    Cards card13;
    Cards card14;


};

#endif // GLADIATORGAME_H
