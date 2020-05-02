#include "gladiatorgame.h"

gladiatorgame::gladiatorgame()
{

}

void gladiatorgame::SetupGame(){

    card1.setID(1);
    card2.setID(2);
    card3.setID(3);
    card4.setID(4);
    card6.setID(5);
    card6.setID(6);
    card7.setID(7);
    card8.setID(8);
    card9.setID(9);
    card10.setID(10);
    card11.setID(11);
    card12.setID(12);
    card13.setID(13);
    card14.setID(14);

    this->KICards[0]=8;
    this->KICards[1]=9;
    this->KICards[2]=10;
    this->KICards[3]=11;
    this->KICards[4]=12;
    this->KICards[5]=13;
    this->KICards[6]=14;



    card1.setKlasse ("blue_Bounty_Hunter");
    card2.setKlasse ("blue_Guardian");
    card3.setKlasse ("blue_Vikinger");
    card4.setKlasse ("blue_King_Arthur");
    card5.setKlasse ("blue_God_Of_Nature");
    card6.setKlasse ("blue_Mechaknight");
    card7.setKlasse ("blue_Robin_Hood");
    card8.setKlasse ("red_Bounty_Hunter");
    card9.setKlasse ("red_Guardian");
    card10.setKlasse("red_Vikinger");
    card11.setKlasse("red_King_Arthur");
    card12.setKlasse("red_God_Of_Nature");
    card13.setKlasse("red_Mechaknight");
    card14.setKlasse("red_Robin_Hood");


}

void gladiatorgame::setBluePlayer(QString Username){

    Blue_Player.setName(Username);

}

void gladiatorgame::setBluePlayerAuswahl(int i){

    Blue_Player.setAuswahl(i);

}

void gladiatorgame::setRedPlayerAuswhl(int i){

    Red_Player.setAuswahl(i);

}

void gladiatorgame::ResetPlayerHP(){

    Blue_Player.setHP(7);
    Red_Player.setHP(7);

}

void gladiatorgame::KIauswahl(){

    bool check = false;
    //Eine Zahl zwischen 7 und 14 wird generiert
    int KI =rand() % 7 + 8;
    qDebug()<<"Random Zahl =" << KI;

    //check ob die Karte noch lebt

    for(int i=0; i<=6; i++){
        qDebug()<< "for schleife gestrtet:" << i;
        if(this->KICards[i] == KI){

            Red_Player.setAuswahl(KI);
            check = true;

            if(check == true){
                qDebug() << "KI gesetzt: " << KI;
            }
        }
    }

    qDebug()<< "for schleife beendet";
    if(check == false){
        qDebug()<<"Ki konnte nicht gesetzt werden, starte Auswahl erneut!";
        this->KIauswahl();

    }
    qDebug()<<"Ende der Methode KIauswahl";
}

void gladiatorgame::KICardsDelete(int DelID){

    for(int i=0; i<=6; i++){

        if(this->KICards[i] == DelID){

            KICards[i] = 0;
            qDebug()<< "Cardid: " << DelID <<"gelöscht";

        }
    }
}

int gladiatorgame::getcardfight(int i){
    int HP_Blue = Blue_Player.getHP();
    int HP_Red  = Red_Player.getHP();

    switch (i){


    /* King_Arthur */
    case 1:/* SSH */ return(0); /* K_A vs. K_A */
    case 2: Blue_Player.setHP(HP_Blue - 1); return(8); /* K_A vs. B_H */
    case 3: Red_Player.setHP(HP_Red - 1); return(4); /* K_A vs. V */
    case 4: Blue_Player.setHP(HP_Blue - 1); return(14); /* K_A vs. R_H */
    case 5: Red_Player.setHP(HP_Red - 1); return(4); /* K_A vs. G */
    case 6: Red_Player.setHP(HP_Red - 1); return(4); /* K_A vs. MK */
    case 7: Blue_Player.setHP(HP_Blue - 1); return(12); /* K_A vs. G_O_N */

        /* Bounty_Hunter */
    case 8: /* SSH */ return(0); /* B_H vs. B_H */
    case 9: Red_Player.setHP(HP_Red - 1); return(1); /* B_H vs. V */
    case 10: Blue_Player.setHP(HP_Blue - 1); return(14); /* B_H vs. R_H */
    case 11: Blue_Player.setHP(HP_Blue - 1); return(9); /* B_H vs. G */
    case 12: Blue_Player.setHP(HP_Blue - 1); return(13); /* B_H vs. MK */
    case 13: Red_Player.setHP(HP_Red - 1); return(1); /* B_H vs. G_O_N */
    case 14: Red_Player.setHP(HP_Red - 1); return(1); /* B_H vs. K_A */

        /* Vikinger */
    case 15: /* SSH */ return(0); /* V vs. V */
    case 16: Red_Player.setHP(HP_Red - 1); return(3); /* V vs. R_H */
    case 17: Blue_Player.setHP(HP_Blue - 1); return(9); /* V vs. G */
    case 18: Red_Player.setHP(HP_Red - 1); return(3); /* V vs. MK */
    case 19: Red_Player.setHP(HP_Red - 1); return(3); /* V vs. G_O_N */
    case 20: Blue_Player.setHP(HP_Blue - 1); return(11); /* V vs. K_A */
    case 21: Blue_Player.setHP(HP_Blue - 1); return(8); /* V vs. B_H */

        /* Robin_Hood */
    case 22: /* SSH */ return(0); /* R_H vs. R_H */
    case 23: Red_Player.setHP(HP_Red - 1); return(7); /* R_H vs. G */
    case 24: Blue_Player.setHP(HP_Blue - 1); return(13); /* R_H vs. MK */
    case 25: Blue_Player.setHP(HP_Blue - 1); return(12); /* R_H vs. G_O_N */
    case 26: Red_Player.setHP(HP_Red - 1); return(7); /* R_H vs. K_A */
    case 27: Red_Player.setHP(HP_Red - 1); return(7); /* R_H vs. B_H */
    case 28: Blue_Player.setHP(HP_Blue - 1); return(10); /* R_H vs. V */

        /* Guardian */
    case 29: /* SSH */ return(0); /* G vs. G */
    case 30: Red_Player.setHP(HP_Red - 1); return(2); /* G vs. MK */
    case 31: Blue_Player.setHP(HP_Blue - 1); return(12); /* G vs. G_O_N */
    case 32: Blue_Player.setHP(HP_Blue - 1); return(11); /* G vs. K_A */
    case 33: Red_Player.setHP(HP_Red - 1); return(2); /* G vs. B_H */
    case 34: Red_Player.setHP(HP_Red - 1); return(2); /* G vs. V */
    case 35: Blue_Player.setHP(HP_Blue - 1); return(14); /* G vs. R_H */

        /* Mechaknight */
    case 36: /* SSH */ return(0); /* MK vs. MK */
    case 37: Red_Player.setHP(HP_Red - 1); return(6); /* MK vs. G_O_N */
    case 38: Red_Player.setHP(HP_Red - 1); return(6); /* MK vs. R_H */
    case 39: Red_Player.setHP(HP_Red - 1); return(6); /* MK vs. B_H */
    case 40: Blue_Player.setHP(HP_Blue - 1); return(11); /* MK vs. K_A */
    case 41: Blue_Player.setHP(HP_Blue - 1); return(10); /* MK vs. V */
    case 42: Blue_Player.setHP(HP_Blue - 1); return(9); /* MK vs. G */

        /* God_Of_Nature */
    case 43: /* SSH */ return(0); /* G_O_N vs. G_O_N */
    case 44: Red_Player.setHP(HP_Red - 1); return(5); /* G_O_N vs. K_A */
    case 45: Red_Player.setHP(HP_Red - 1); return(5); /* G_O_N vs. R_H */
    case 46: Red_Player.setHP(HP_Red - 1); return(5); /* G_O_N vs. G */
    case 47: Blue_Player.setHP(HP_Blue - 1); return(8); /* G_O_N vs. B_H */
    case 48: Blue_Player.setHP(HP_Blue - 1); return(10); /* G_O_N vs. V */
    case 49: Blue_Player.setHP(HP_Blue - 1); return(13); /* G_O_N vs. MK */}
}

QString gladiatorgame::getKampfNamen(){

    QString BlueCard = getCardName(Blue_Player.getAuswahl());
    QString Redcard = getCardName(Red_Player.getAuswahl());

    return(BlueCard + " vs. " + Redcard);


}

int gladiatorgame::KampfAuswahl(){

    /* Blue_King_Arthur */

    /* Blue_King_Arthur vs. Red_Bounty_Hunter */
    if (Blue_Player.getAuswahl() == 4  && Red_Player.getAuswahl() == 8 ){
        return(getcardfight(2));
    }

    /* Blue_King_Arthur vs. Red_Guardian */
    else if (Blue_Player.getAuswahl() == 4 && Red_Player.getAuswahl() == 9){
        return(getcardfight(5));
    }

    /* Blue_King_Arthur vs. Red_Vikinger */
    else if (Blue_Player.getAuswahl() == 4 && Red_Player.getAuswahl() == 10){
        return(getcardfight(3));
    }

    /* Blue_King_Arthur vs. Red_King_Arthur */
    else if (Blue_Player.getAuswahl() == 4 && Red_Player.getAuswahl() == 11){
        return(getcardfight(1));
    }

    /* Blue_King_Arthur vs. Red_God_Of_Nature */
    else if (Blue_Player.getAuswahl() == 4 && Red_Player.getAuswahl() == 12){
        return getcardfight(7);
    }

    /* Blue_King_Arthur vs. Red_Mechaknight */
    else if (Blue_Player.getAuswahl() == 4 && Red_Player.getAuswahl() == 13){
        return(getcardfight(6));
    }

    /* Blue_King_Arthur vs. Red_Robin_Hood */
    else if (Blue_Player.getAuswahl() == 4 && Red_Player.getAuswahl() == 14){
        return(getcardfight(4));
    }

    /* Blue_Bounty_Hunter */

    /* Blue_Bounty_Hunter vs. Red_Bounty_Hunter */
    else if (Blue_Player.getAuswahl() == 1 && Red_Player.getAuswahl() == 8){
        return(getcardfight(8));
        qDebug("vs redbounty");
    }

    /* Blue_Bounty_Hunter vs. Red_Guardian */
    else if (Blue_Player.getAuswahl() == 1 && Red_Player.getAuswahl() == 9){
        return(getcardfight(11));
        qDebug("vs_redguardian");
    }

    /* Blue_Bounty_Hunter vs. Red_Vikinger */
    else if (Blue_Player.getAuswahl() == 1 && Red_Player.getAuswahl() == 10){
        return(getcardfight(9));
        qDebug("vs_redviking");
    }

    /* Blue_Bounty_Hunter vs. Red_King_Arthur */
    else if (Blue_Player.getAuswahl() == 1 && Red_Player.getAuswahl() == 11){
        return(getcardfight(14));
        qDebug("vs_red_king");
    }

    /* Blue_Bounty_Hunter vs. Red_God_Of_Nature */
    else if (Blue_Player.getAuswahl() == 1 && Red_Player.getAuswahl() == 12){
        return(getcardfight(13));
        qDebug("vs_redGod");
    }

    /* Blue_Bounty_Hunter vs. Red_Mechaknight */
    else if (Blue_Player.getAuswahl() == 1 && Red_Player.getAuswahl() == 13){
        return(getcardfight(12));
        qDebug("vs_red_mecha");
    }

    /* Blue_Bounty_Hunter vs. Red_Robin_Hood */
    else if (Blue_Player.getAuswahl() == 1 && Red_Player.getAuswahl() == 14){
        return(getcardfight(10));
        qDebug("vs_redRobin");
    }


    /* Blue_Vikinger */

    /* Blue_Vikinger vs. Red_Vikinger */
    else if (Blue_Player.getAuswahl() == 3 && Red_Player.getAuswahl() == 10){
        return(getcardfight(15));
    }

    /* Blue_Vikinger vs. Red_Guardian */
    else if (Blue_Player.getAuswahl() == 3 && Red_Player.getAuswahl() == 9){
        return(getcardfight(17));
    }

    /* Blue_Vikinger vs. Red_Bounty_Hunter */
    else if (Blue_Player.getAuswahl() == 3 && Red_Player.getAuswahl() == 8){
        return(getcardfight(21));
    }

    /* Blue_Vikinger vs. Red_King_Arthur */
    else if (Blue_Player.getAuswahl() == 3 && Red_Player.getAuswahl() == 11){
        return(getcardfight(20));
    }

    /* Blue_Vikinger vs. Red_God_Of_Nature */
    else if (Blue_Player.getAuswahl() == 3 && Red_Player.getAuswahl() == 12){
        return(getcardfight(19));
    }

    /* Blue_Vikinger vs. Red_Mechaknight */
    else if (Blue_Player.getAuswahl() == 3 && Red_Player.getAuswahl() == 13){
        return(getcardfight(18));
    }

    /* Blue_Vikinger vs. Red_Robin_Hood */
    else if (Blue_Player.getAuswahl() == 3 && Red_Player.getAuswahl() == 14){
        return(getcardfight(16));
    }


    /* Blue_Robin_Hood */

    /* Blue_Robin_Hood vs. Red_Robin_Hood */
    else if (Blue_Player.getAuswahl() == 7 && Red_Player.getAuswahl() == 14){
        return(getcardfight(22));
    }

    /* Blue_Robin_Hood vs. Red_Bounty_Hunter */
    else if (Blue_Player.getAuswahl() == 7 && Red_Player.getAuswahl() == 8){
        return(getcardfight(27));
    }

    /* Blue_Robin_Hood vs. Red_Guardian */
    else if (Blue_Player.getAuswahl() == 7 && Red_Player.getAuswahl() == 9){
        return(getcardfight(23));
    }

    /* Blue_Robin_Hood vs. Red_Vikinger */
    else if (Blue_Player.getAuswahl() == 7 && Red_Player.getAuswahl() == 10){
        return(getcardfight(28));
    }

    /* Blue_Robin_Hood vs. Red_King_Arthur */
    else if (Blue_Player.getAuswahl() == 7 && Red_Player.getAuswahl() == 11){
        return(getcardfight(26));
    }

    /* Blue_Robin_Hood vs. Red_God_Of_Nature */
    else if (Blue_Player.getAuswahl() == 7 && Red_Player.getAuswahl() == 12){
        return(getcardfight(25));
    }

    /* Blue_Robin_Hood vs. Red_Mechaknight */
    else if (Blue_Player.getAuswahl() == 7 && Red_Player.getAuswahl() == 13){
        return(getcardfight(24));
    }


    /* Blue_Guardian */

    /* Blue_Guardian vs. Red_Guardian */
    else if (Blue_Player.getAuswahl() == 2 && Red_Player.getAuswahl() == 9){
        return(getcardfight(29));
    }

    /* Blue_Guardian vs. Red_Bounty_Hunter */
    else if (Blue_Player.getAuswahl() == 2 && Red_Player.getAuswahl() == 8){
        return(getcardfight(33));
    }

    /* Blue_Guardian vs. Red_Vikinger */
    else if (Blue_Player.getAuswahl() == 2 && Red_Player.getAuswahl() == 10){
        return(getcardfight(34));
    }

    /* Blue_Guardian vs. Red_King_Arthur */
    else if (Blue_Player.getAuswahl() == 2 && Red_Player.getAuswahl() == 11){
        return(getcardfight(32));
    }

    /* Blue_Guardian vs. Red_God_Of_Nature */
    else if (Blue_Player.getAuswahl() == 2 && Red_Player.getAuswahl() == 12){
        return( getcardfight(31));
    }

    /* Blue_Guardian vs. Red_Mechaknight */
    else if (Blue_Player.getAuswahl() == 2 && Red_Player.getAuswahl() == 13){
        return(getcardfight(30));
    }

    /* Blue_Guardian vs. Red_Robin_Hood */
    else if (Blue_Player.getAuswahl() == 2 && Red_Player.getAuswahl() == 14){
        return(getcardfight(35));
    }


    /* Blue_Mechaknight */

    /* Blue_Mechaknight vs. Red_Mechaknight */
    else if (Blue_Player.getAuswahl() == 6 && Red_Player.getAuswahl() == 13){
        return(getcardfight(36));
    }

    /* Blue_Mechaknight vs. Red_Bounty_Hunter */
    else if (Blue_Player.getAuswahl() == 6 && Red_Player.getAuswahl() == 8){
        return(getcardfight(39));
    }

    /* Blue_Mechaknight vs. Red_Guardian*/
    else if (Blue_Player.getAuswahl() == 6 && Red_Player.getAuswahl() == 9){
        return(getcardfight(42));
    }

    /* Blue_Mechaknight vs. Red_Vikinger */
    else if (Blue_Player.getAuswahl() == 6 && Red_Player.getAuswahl() == 10){
        return(getcardfight(41));
    }

    /* Blue_Mechaknight vs. Red_King_Arthur */
    else if (Blue_Player.getAuswahl() == 6 && Red_Player.getAuswahl() == 11){
        return(getcardfight(40));
    }

    /* Blue_Mechaknight vs. Red_God_Of_Nature */
    else if (Blue_Player.getAuswahl() == 6 && Red_Player.getAuswahl() == 12){
        return(getcardfight(37));
    }

    /* Blue_Mechaknight vs. Red_Robin_Hood */
    else if (Blue_Player.getAuswahl() == 6 && Red_Player.getAuswahl() == 14){
        return(getcardfight(38));
    }


    /* Blue_God_Of_Nature */

    /* Blue_ God_Of_Nature vs. Red_ God_Of_Nature */
    else if (Blue_Player.getAuswahl() == 5 && Red_Player.getAuswahl() == 12){
        return(getcardfight(43));
    }

    /* Blue_ God_Of_Nature vs. Red_ Bounty_Hunter */
    else if (Blue_Player.getAuswahl() == 5 && Red_Player.getAuswahl() == 8){
        return(getcardfight(47));
    }

    /* Blue_ God_Of_Nature vs. Red_ Guardian */
    else if (Blue_Player.getAuswahl() == 5 && Red_Player.getAuswahl() == 9){
        return(getcardfight(46));
    }

    /* Blue_ God_Of_Nature vs. Red_ Vikinger */
    else if (Blue_Player.getAuswahl() == 5 && Red_Player.getAuswahl() == 10){
        return(getcardfight(48));
    }

    /* Blue_ God_Of_Nature vs. Red_ King_Arthur */
    else if (Blue_Player.getAuswahl() == 5 && Red_Player.getAuswahl() == 11){
        return(getcardfight(44));
    }

    /* Blue_ God_Of_Nature vs. Red_ Mecha_Knight */
    else if (Blue_Player.getAuswahl() == 5 && Red_Player.getAuswahl() == 13){
        return(getcardfight(49));
    }

    /* Blue_ God_Of_Nature vs. Red_ Robin_Hood */
    else if (Blue_Player.getAuswahl() == 5 && Red_Player.getAuswahl() == 14){
        return(getcardfight(45));
    }
}

QString gladiatorgame::getCardName(int id){

    switch(id){

    case 1 : return(card1.getKlasse());
    case 2 : return(card2.getKlasse());
    case 3 : return(card3.getKlasse());
    case 4 : return(card4.getKlasse());
    case 5 : return(card5.getKlasse());
    case 6 : return(card6.getKlasse());
    case 7 : return(card7.getKlasse());
    case 8 : return(card8.getKlasse());
    case 9 : return(card9.getKlasse());
    case 10: return(card10.getKlasse());
    case 11: return(card11.getKlasse());
    case 12: return(card12.getKlasse());
    case 13: return(card13.getKlasse());
    case 14: return(card14.getKlasse());
    default: return("Nobody");

    }

}

int gladiatorgame::getRedPlayerHP(){

    return(Red_Player.getHP());


}

int gladiatorgame::getBluePlayerHP(){


    return(Blue_Player.getHP());
}

int gladiatorgame::getBluePlayerAuswahl(){

    return(Blue_Player.getAuswahl());

}

int gladiatorgame::getRedPlayerAuswahl(){

    return(Red_Player.getAuswahl());
}

void gladiatorgame::setSSHLoserHP(int w){

    this->SSHWinner = w;
    int HP_Blue = Blue_Player.getHP();
    int HP_Red  = Red_Player.getHP();


    if(SSHWinner == 1){
        qDebug()<<"Blau gewinnt Rot HP -1";
        Red_Player.setHP(HP_Red -1);

    }else if(SSHWinner == 2){
        qDebug()<<"Rot gewinnt SSH Blau HP -1";
        Blue_Player.setHP(HP_Blue -1);

    }
}

void gladiatorgame::setWinner(int i){

    qDebug()<<"Inside gewinner funktion";
    if(i == 1){
        qDebug("i = 1");
        int Wins =Blue_Player.getWins();
        Blue_Player.setWins(Wins +1);

    }else if(i ==2){
        qDebug("i = 2");
        int Loses = Blue_Player.getLoses();
        Blue_Player.setLoses(Loses +1);
    }

}

int gladiatorgame::getBluePlayerWins(){

    qDebug()<<"Blue Player Wins" + QString::number(Blue_Player.getWins());
    return(Blue_Player.getWins());
}

int gladiatorgame::getBluePlayerLoses(){

    return(Blue_Player.getLoses());
}
