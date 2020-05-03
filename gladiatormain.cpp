#include "gladiatormain.h"
#include "ui_gladiatormain.h"
#include <QPixmap>

Gladiatormain::Gladiatormain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gladiatormain)
{
    //Setup der Gui//
    //Vorbereiten des Spieles//
    //-----------------------------//

    ui->setupUi(this);

    this->sshgame = new FrmSSH;
    connect(sshgame,SIGNAL(on_FrmSSH_closed(int)),this,SLOT(on_sshclosed(int)));

    game->SetupGame();

    ui->btn_Close->hide();
    ui->btn_Rematch->hide();
    ui->lbl_BlueCard->hide();
    ui->lbl_RedCard->hide();
    ui->lbl_Versus->hide();
    //-----------------------------//

    //Label Hintergründe Transparent und Scalen der Bilder auf die Labels erlauben//
    //----------------------------------------------------------------------------//
    ui->lbl_Count->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_Round->setAttribute(Qt::WA_TranslucentBackground);

    ui->lbl_Username->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_Player->setAttribute(Qt::WA_TranslucentBackground);

    ui->lbl_RedHPBar->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_BlueHPBar->setAttribute(Qt::WA_TranslucentBackground);

    ui->lbl_BlueHP1->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_BlueHP2->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_BlueHP3->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_BlueHP4->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_BlueHP5->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_BlueHP6->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_BlueHP7->setAttribute(Qt::WA_TranslucentBackground);

    ui->lbl_RedHP1->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_RedHP2->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_RedHP3->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_RedHP4->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_RedHP5->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_RedHP6->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_RedHP7->setAttribute(Qt::WA_TranslucentBackground);

    ui->lbl_BlueHPBar->setScaledContents(true);
    ui->lbl_RedHPBar->setScaledContents(true);

    ui->lbl_BlueHP1->setScaledContents(true);
    ui->lbl_BlueHP2->setScaledContents(true);
    ui->lbl_BlueHP3->setScaledContents(true);
    ui->lbl_BlueHP4->setScaledContents(true);
    ui->lbl_BlueHP5->setScaledContents(true);
    ui->lbl_BlueHP6->setScaledContents(true);
    ui->lbl_BlueHP7->setScaledContents(true);

    ui->lbl_RedHP1->setScaledContents(true);
    ui->lbl_RedHP2->setScaledContents(true);
    ui->lbl_RedHP3->setScaledContents(true);
    ui->lbl_RedHP4->setScaledContents(true);
    ui->lbl_RedHP5->setScaledContents(true);
    ui->lbl_RedHP6->setScaledContents(true);
    ui->lbl_RedHP7->setScaledContents(true);

    ui->lbl_BlueCard->setScaledContents(true);
    ui->lbl_RedCard->setScaledContents(true);
    //----------------------------------------------------------------------------//

}

Gladiatormain::~Gladiatormain()
{
    delete ui;
}



void Gladiatormain::on_btn_card1_clicked()
{
    //Counter//
    //-----------------------------//
    this->Counter();
    //-----------------------------//

    //Setzen der Karten//
    //-----------------------------//
    qDebug()<<"Karte 1 gespielt!";
    game->setBluePlayerAuswahl(1);
    game->KIauswahl();
    //-----------------------------//

    //Anzeigen der kämpfenden Karten//
    //---------------------------------------------//
    this->BlueCardShow(1);
    this->RedCardShow(game->getRedPlayerAuswahl());
    //---------------------------------------------//

    //Gewinner des Kampfes festlegen//
    //---------------------------------------------------//
    int winner = game->KampfAuswahl();
    qDebug()<<"Gewinner festgelegt";
    QString winnercard = game->getCardName(winner);
    qDebug()<<"Gewinner Name gespeichert";
    ui->listWidget_test->addItem(winnercard + " Wins!");
    qDebug()<<"gewinner Ausgabe";
    //---------------------------------------------------//

    //Kampf//
    //---------------------------------------------------//
    if(winner == 1){

        //Blau gewinnt, Auswahl von Rot wird gespeichert und anschließend gelöscht//
        //-----------------------------------------------------------------------//
        int Verlierer = game->getRedPlayerAuswahl();
        game->KICardsDelete(Verlierer);
        qDebug()<<"Löschen gelungen";
        //-----------------------------------------------------------------------//


        //HP anzeige wird aktualisiert und das entspechnde Label wird gehidet//
        //-------------------------------------------------------------------//
        this->ChangeHeartsRed(game->getRedPlayerHP());
        QTimer::singleShot(4000, this, SLOT(RedLabelHide()));
        //------------------------------------------------------------------//

    }else if(winner == 0){
        //SSH wird gestartet//
        //------------------//
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        //------------------//

    }else if(winner == game->getRedPlayerAuswahl()){


        //Blau verliert//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(BlueButtonHide()));
        this->ChangeHeartsBlue(game->getBluePlayerHP());
        //-----------------------------//

    }
    //---------------------------------------------------//

    //Hp Abfrage
    if(game->getBluePlayerHP() == 0){

        //Blau verliert
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        //Blau gewinnt
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else{
        //Ausgabe der HP
        QString Blue = QString::number(game->getBluePlayerHP());
        QString Red  = QString::number(game->getRedPlayerHP());

        ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
        ui->listWidget_test->addItem("Red Player has " + Red + " HP");
    }

}

void Gladiatormain::on_btn_card1_rightClicked()
{
    CardsFrm->show();
    CardsFrm->setCardid(1);
}

void Gladiatormain::on_btn_card2_clicked()
{
    //Counter//
    //-----------------------------//
    this->Counter();
    //-----------------------------//


    qDebug()<<"Karte 2 gespielt!";
    game->setBluePlayerAuswahl(2);
    game->KIauswahl();

    //BlueCardShow//
    //-----------------------------//
    this->BlueCardShow(2);
    //-----------------------------//

    //RedCardShow//
    //-----------------------------//
    this->RedCardShow(game->getRedPlayerAuswahl());
    //-----------------------------//

    qDebug()<<"Auswahl durchgeführt";
    ui->listWidget_test->addItem(game->getKampfNamen());
    qDebug()<<"KampfName Ausgegeben";
    int winner = game->KampfAuswahl();
    qDebug()<<"Gewinner festgelegt";
    QString winnercard = game->getCardName(winner);
    qDebug()<<"Gewinner Namen";
    ui->listWidget_test->addItem(winnercard + " Wins!");
    qDebug()<<"Gewinner ausgegeben";


    if(winner == 2){
        qDebug()<< "Verlierer wird gesetzt";
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Label hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(RedLabelHide()));
        //-----------------------------//


    }else if(winner == 0){

        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";

    }else if(winner == game->getRedPlayerAuswahl()){
        qDebug()<<"Keine Karte gelöscht";

        //Blue Button Hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(BlueButtonHide()));
        //-----------------------------//

        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }


    qDebug()<<"Ende der Gewinner If-Else";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else{
        QString Blue = QString::number(game->getBluePlayerHP());
        QString Red  = QString::number(game->getRedPlayerHP());

        ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
        ui->listWidget_test->addItem("Red Player has " + Red + " HP");


    }
}

void Gladiatormain::on_btn_card2_rightClicked()
{
    CardsFrm->show();
    CardsFrm->setCardid(2);
}

void Gladiatormain::on_btn_card3_clicked()
{
    //Counter//
    //-----------------------------//
    this->Counter();
    //-----------------------------//


    qDebug()<<"Karte 3 gespielt!";
    game->setBluePlayerAuswahl(3);
    game->KIauswahl();

    //BlueCardShow//
    //-----------------------------//
    this->BlueCardShow(3);
    //-----------------------------//

    //RedCardShow//
    //-----------------------------//
    this->RedCardShow(game->getRedPlayerAuswahl());
    //-----------------------------//

    ui->listWidget_test->addItem(game->getKampfNamen());
    int winner = game->KampfAuswahl();
    QString winnercard = game->getCardName(winner);
    ui->listWidget_test->addItem(winnercard + " Wins!");


    if(winner == 3){
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Label hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(RedLabelHide()));
        //-----------------------------//

    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";


    }else if(winner == game->getRedPlayerAuswahl()){

        //Blue Button Hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(BlueButtonHide()));
        //-----------------------------//

        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }


    qDebug()<<"Ende der Gewinner If-Else";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){

        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else{
        QString Blue = QString::number(game->getBluePlayerHP());
        QString Red  = QString::number(game->getRedPlayerHP());

        ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
        ui->listWidget_test->addItem("Red Player has " + Red + " HP");


    }

}

void Gladiatormain::on_btn_card3_rightClicked()
{
    CardsFrm->show();
    CardsFrm->setCardid(3);
}

void Gladiatormain::on_btn_card4_clicked()
{
    //Counter//
    //-----------------------------//
    this->Counter();
    //-----------------------------//


    qDebug()<<"Karte 4 gespielt!";
    game->setBluePlayerAuswahl(4);
    game->KIauswahl();

    //BlueCardShow//
    //-----------------------------//
    this->BlueCardShow(4);
    //-----------------------------//

    //RedCardShow//
    //-----------------------------//
    this->RedCardShow(game->getRedPlayerAuswahl());
    //-----------------------------//

    ui->listWidget_test->addItem(game->getKampfNamen());
    int winner = game->KampfAuswahl();
    QString winnercard = game->getCardName(winner);
    ui->listWidget_test->addItem(winnercard + " Wins!");



    if(winner == 4){
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Label hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(RedLabelHide()));
        //-----------------------------//

    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";

    }else if(winner == game->getRedPlayerAuswahl()){

        //Blue Button Hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(BlueButtonHide()));
        //-----------------------------//

        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }

    qDebug()<<"Ende der Gewinner If-Else";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else{
        QString Blue = QString::number(game->getBluePlayerHP());
        QString Red  = QString::number(game->getRedPlayerHP());

        ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
        ui->listWidget_test->addItem("Red Player has " + Red + " HP");


    }


}

void Gladiatormain::on_btn_card4_rightClicked()
{
    CardsFrm->show();
    CardsFrm->setCardid(4);
}

void Gladiatormain::on_btn_card5_clicked()
{
    //Counter//
    //-----------------------------//
    this->Counter();
    //-----------------------------//


    qDebug()<<"Karte 5 gespielt!";
    game->setBluePlayerAuswahl(5);
    game->KIauswahl();

    //BlueCardShow//
    //-----------------------------//
    this->BlueCardShow(5);
    //-----------------------------//

    //RedCardShow//
    //-----------------------------//
    this->RedCardShow(game->getRedPlayerAuswahl());
    //-----------------------------//

    ui->listWidget_test->addItem(game->getKampfNamen());
    int winner = game->KampfAuswahl();
    QString winnercard = game->getCardName(winner);
    ui->listWidget_test->addItem(winnercard + " Wins!");

    if(winner == 5){
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Label hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(RedLabelHide()));
        //-----------------------------//

    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";

    }else if(winner == game->getRedPlayerAuswahl()){

        //Blue Button Hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(BlueButtonHide()));
        //-----------------------------//

        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }

    qDebug()<<"Ende der Gewinner If-Else";



    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else{
        QString Blue = QString::number(game->getBluePlayerHP());
        QString Red  = QString::number(game->getRedPlayerHP());

        ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
        ui->listWidget_test->addItem("Red Player has " + Red + " HP");


    }

}

void Gladiatormain::on_btn_card5_rightClicked()
{
    CardsFrm->show();
    CardsFrm->setCardid(5);
}

void Gladiatormain::on_btn_card6_clicked()
{
    //Counter//
    //-----------------------------//
    this->Counter();
    //-----------------------------//


    qDebug()<<"Karte 6 gespielt!";
    game->setBluePlayerAuswahl(6);
    game->KIauswahl();

    //BlueCardShow//
    //-----------------------------//
    this->BlueCardShow(6);
    //-----------------------------//

    //RedCardShow//
    //-----------------------------//
    this->RedCardShow(game->getRedPlayerAuswahl());
    //-----------------------------//

    ui->listWidget_test->addItem(game->getKampfNamen());
    int winner = game->KampfAuswahl();
    QString winnercard = game->getCardName(winner);
    ui->listWidget_test->addItem(winnercard + " Wins!");


    if(winner == 6){
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Red Label hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(RedLabelHide()));
        //-----------------------------//


    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";



    }else if(winner == game->getRedPlayerAuswahl()){

        //Blue Button Hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(BlueButtonHide()));
        //-----------------------------//

        this->ChangeHeartsBlue(game->getBluePlayerHP());
        qDebug()<<"Ende der Gewinner If-Else";


    }if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);

        ui->btn_Close->show();
        ui->btn_Rematch->show();


    }else{
        QString Blue = QString::number(game->getBluePlayerHP());
        QString Red  = QString::number(game->getRedPlayerHP());

        ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
        ui->listWidget_test->addItem("Red Player has " + Red + " HP");

    }
}

void Gladiatormain::on_btn_card6_rightClicked()
{
    CardsFrm->show();
    CardsFrm->setCardid(6);
}

void Gladiatormain::on_btn_card7_clicked()
{
    //Counter//
    //-----------------------------//
    this->Counter();
    //-----------------------------//


    qDebug()<<"Karte 7 gespielt!";
    game->setBluePlayerAuswahl(7);
    game->KIauswahl();

    //BlueCardShow//
    //-----------------------------//
    this->BlueCardShow(7);
    //-----------------------------//

    //RedCardShow//
    //-----------------------------//
    this->RedCardShow(game->getRedPlayerAuswahl());
    //-----------------------------//

    qDebug()<<"Ki auswahl fertig";
    ui->listWidget_test->addItem(game->getKampfNamen());
    qDebug()<<"KampfName ausgegeben";
    int winner = game->KampfAuswahl();
    qDebug()<<"Gewinner festgelegt";
    QString winnercard = game->getCardName(winner);
    qDebug()<<"Gewinner Name bestimmt";
    ui->listWidget_test->addItem(winnercard + " Wins!");
    qDebug()<<"Gewinner ausgegeben";

    if(winner == 7){
        qDebug("Blau gewinnt !");
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Red Label hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(RedLabelHide()));
        //-----------------------------//


    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";


    }else if(winner == game->getRedPlayerAuswahl()){
        qDebug()<<"Ki Gewinnt";

        //Blue Button Hide//
        //-----------------------------//
        QTimer::singleShot(4000, this, SLOT(BlueButtonHide()));
        //-----------------------------//

        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }


    qDebug()<<"Gewinner If-Else benndet";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);

        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);

        ui->btn_Close->show();
        ui->btn_Rematch->show();


    }else{
        QString Blue = QString::number(game->getBluePlayerHP());
        QString Red  = QString::number(game->getRedPlayerHP());

        ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
        ui->listWidget_test->addItem("Red Player has " + Red + " HP");


    }



}

void Gladiatormain::on_btn_card7_rightClicked()
{
    CardsFrm->show();
    CardsFrm->setCardid(7);
}



void Gladiatormain::on_sshclosed(int SSHWinner){

    int Card_Red  = game->getRedPlayerAuswahl();
    int Card_Blue = game->getBluePlayerAuswahl();

    qDebug()<<"SSHGewinner = " << SSHWinner;

    if(SSHWinner == 0){

        sshgame->show();

    }else if(SSHWinner==1){
        qDebug()<<"Blau gewinnt SSH";
        ui->listWidget_test->addItem(game->getCardName(Card_Blue) + "Wins");
        game->KICardsDelete(Card_Red);
        qDebug()<<"Löschen erfolgreich";

        QTimer::singleShot(1000, this, SLOT(RedLabelHide()));


    }else if(SSHWinner==2) {
        qDebug()<<"Rot gewinnt SSH";
        ui->listWidget_test->addItem(game->getCardName(Card_Red) + "Wins");

        //Blue Button Hide//
        //-----------------------------//
        QTimer::singleShot(1000, this, SLOT(BlueButtonHide()));
        //-----------------------------//


    }


    qDebug()<<"SSH Gewinner if else beendet";

    game->setSSHLoserHP(SSHWinner);

    qDebug()<<"HP abgezogen";

    if(SSHWinner == 1){
        this->ChangeHeartsRed(game->getRedPlayerHP());
    }

    else if(SSHWinner == 2){
        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }


    QString Blue = QString::number(game->getBluePlayerHP());
    QString Red  = QString::number(game->getRedPlayerHP());

    ui->listWidget_test->addItem("Blue Player has " + Blue + " HP");
    ui->listWidget_test->addItem("Red Player has " + Red + " HP");


}

void Gladiatormain::on_btn_Rematch_clicked()
{
    game->ResetPlayerHP();
    game->SetupGame();
    ui->btn_Close->hide();
    ui->btn_Rematch->hide();
    ui->listWidget_test->clear();
    ui->btn_card1->show();
    ui->btn_card2->show();
    ui->btn_card3->show();
    ui->btn_card4->show();
    ui->btn_card5->show();
    ui->btn_card6->show();
    ui->btn_card7->show();
    ui->lbl_backside_1->show();
    ui->lbl_backside_2->show();
    ui->lbl_backside_3->show();
    ui->lbl_backside_4->show();
    ui->lbl_backside_5->show();
    ui->lbl_backside_6->show();
    ui->lbl_backside_7->show();
    ui->lbl_Count->setNum(1);

    QPixmap Blue;
    Blue.load(":/images/images/heart_blue.png");
    ui->lbl_BlueHP1->setPixmap(Blue);
    ui->lbl_BlueHP2->setPixmap(Blue);
    ui->lbl_BlueHP3->setPixmap(Blue);
    ui->lbl_BlueHP4->setPixmap(Blue);
    ui->lbl_BlueHP5->setPixmap(Blue);
    ui->lbl_BlueHP6->setPixmap(Blue);
    ui->lbl_BlueHP7->setPixmap(Blue);

    QPixmap Red;
    Red.load(":/images/images/heart_red.png");
    ui->lbl_RedHP1->setPixmap(Red);
    ui->lbl_RedHP2->setPixmap(Red);
    ui->lbl_RedHP3->setPixmap(Red);
    ui->lbl_RedHP4->setPixmap(Red);
    ui->lbl_RedHP5->setPixmap(Red);
    ui->lbl_RedHP6->setPixmap(Red);
    ui->lbl_RedHP7->setPixmap(Red);

}

void Gladiatormain::on_btn_Close_clicked()
{

    Gladiatormain::close();

}

void Gladiatormain::RedLabelHide(/*int RedCardHide*/){

    int RedCardHide = game->getRedPlayerAuswahl();
    if(RedCardHide == 8){
        ui->lbl_backside_1->hide();

    }else if(RedCardHide == 9){
        ui->lbl_backside_2->hide();

    }else if(RedCardHide == 10){
        ui->lbl_backside_3->hide();

    }else if(RedCardHide == 11){
        ui->lbl_backside_4->hide();

    }else if(RedCardHide == 12){
        ui->lbl_backside_5->hide();

    }else if(RedCardHide == 13){
        ui->lbl_backside_6->hide();

    }else if(RedCardHide == 14){
        ui->lbl_backside_7->hide();

    }

}

void Gladiatormain::BlueButtonHide(){

    int BlueCardHide = game->getBluePlayerAuswahl();

    switch (BlueCardHide) {

    case 1:

        ui->btn_card1->hide();
        break;

    case 2:
        ui->btn_card2->hide();
        break;

    case 3:
        ui->btn_card3->hide();
        break;

    case 4:
        ui->btn_card4->hide();
        break;

    case 5:
        ui->btn_card5->hide();
        break;

    case 6:
        ui->btn_card6->hide();
        break;

    case 7:
        ui->btn_card7->hide();
        break;
    }

}

void Gladiatormain::Counter(){

    QString count = ui->lbl_Count->text();
    int c = count.toInt();
    c++;
    ui->lbl_Count->setNum(c);

}

void Gladiatormain::ChangeHeartsRed(int redHearts){

    QPixmap image;
    image.load(":/images/images/heart_grey.png");
    switch(redHearts){

    case 0:
        ui->lbl_RedHP1->setPixmap(image);
        break;
    case 1:
        ui->lbl_RedHP2->setPixmap(image);
        break;
    case 2:
        ui->lbl_RedHP3->setPixmap(image);
        break;
    case 3:
        ui->lbl_RedHP4->setPixmap(image);
        break;
    case 4:
        ui->lbl_RedHP5->setPixmap(image);
        break;
    case 5:
        ui->lbl_RedHP6->setPixmap(image);
        break;
    case 6:
        ui->lbl_RedHP7->setPixmap(image);
        break;
    case 7:
        break;
    default: qDebug()<<"Fehler bei ChangeHeartsRed";


    }
}

void Gladiatormain::ChangeHeartsBlue(int blueHearts){

    QPixmap image;
    image.load(":/images/images/heart_grey.png");
    switch(blueHearts){

    case 0:
        ui->lbl_BlueHP1->setPixmap(image);
        break;
    case 1:
        ui->lbl_BlueHP2->setPixmap(image);
        break;
    case 2:
        ui->lbl_BlueHP3->setPixmap(image);
        break;
    case 3:
        ui->lbl_BlueHP4->setPixmap(image);
        break;
    case 4:
        ui->lbl_BlueHP5->setPixmap(image);
        break;
    case 5:
        ui->lbl_BlueHP6->setPixmap(image);
        break;
    case 6:
        ui->lbl_BlueHP7->setPixmap(image);
        break;
    case 7:
        break;
    default: qDebug()<<"Fehler bei ChangeHeartsBlue";


    }
}

void Gladiatormain::setUsername(QString User){

    this->Username = User;
    this->game->setBluePlayer(User);
    ui->lbl_Username->setText(this->Username);
}


void Gladiatormain::BlueCardShow(int BlueCard){
    QPixmap CardBlue;

    switch (BlueCard) {

    case 1:
        CardBlue.load(":/images/images/Blaues Team Bounty Hunter.png");
        ui->lbl_BlueCard->setPixmap(CardBlue);
        ui->lbl_BlueCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_BlueCard->show();
        QTimer::singleShot(3000, this,  &Gladiatormain::BlueCardHide);
        ui->lbl_Versus->setText("Versus");
        //ui->lbl_Versus->setStyleSheet("font.pixelSize: 70");
        ui->lbl_Versus->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_Versus->show();
        QTimer::singleShot(3000, this, &Gladiatormain::VersusHide);
        break;

    case 2:
        CardBlue.load(":/images/images/Blaues Team Guardian.png");
        ui->lbl_BlueCard->setPixmap(CardBlue);
        ui->lbl_BlueCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_BlueCard->show();
        QTimer::singleShot(3000, this,  &Gladiatormain::BlueCardHide);
        ui->lbl_Versus->setText("Versus");
        //ui->lbl_Versus->setStyleSheet("font.pixelSize: 70");
        ui->lbl_Versus->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_Versus->show();
        QTimer::singleShot(3000, this, &Gladiatormain::VersusHide);
        break;

    case 3:
        CardBlue.load(":/images/images/Blaues Team Vikinger.png");
        ui->lbl_BlueCard->setPixmap(CardBlue);
        ui->lbl_BlueCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_BlueCard->show();
        QTimer::singleShot(3000, this,  &Gladiatormain::BlueCardHide);
        ui->lbl_Versus->setText("Versus");
        //ui->lbl_Versus->setStyleSheet("font.pixelSize: 70");
        ui->lbl_Versus->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_Versus->show();
        QTimer::singleShot(3000, this, &Gladiatormain::VersusHide);
        break;

    case 4:
        CardBlue.load(":/images/images/Blaues Team King Arthur.png");
        ui->lbl_BlueCard->setPixmap(CardBlue);
        ui->lbl_BlueCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_BlueCard->show();
        QTimer::singleShot(3000, this,  &Gladiatormain::BlueCardHide);
        ui->lbl_Versus->setText("Versus");
        //ui->lbl_Versus->setStyleSheet("font.pixelSize: 70");
        ui->lbl_Versus->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_Versus->show();
        QTimer::singleShot(3000, this, &Gladiatormain::VersusHide);
        break;

    case 5:
        CardBlue.load(":/images/images/Blaues Team God Of Nature.png");
        ui->lbl_BlueCard->setPixmap(CardBlue);
        ui->lbl_BlueCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_BlueCard->show();
        QTimer::singleShot(3000, this,  &Gladiatormain::BlueCardHide);
        ui->lbl_Versus->setText("Versus");
        //ui->lbl_Versus->setStyleSheet("font.pixelSize: 70");
        ui->lbl_Versus->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_Versus->show();
        QTimer::singleShot(3000, this, &Gladiatormain::VersusHide);
        break;

    case 6:
        CardBlue.load(":/images/images/Blaues Team Mechaknight.png");
        ui->lbl_BlueCard->setPixmap(CardBlue);
        ui->lbl_BlueCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_BlueCard->show();
        QTimer::singleShot(3000, this,  &Gladiatormain::BlueCardHide);
        ui->lbl_Versus->setText("Versus");
        //ui->lbl_Versus->setStyleSheet("font.pixelSize: 70");
        ui->lbl_Versus->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_Versus->show();
        QTimer::singleShot(3000, this, &Gladiatormain::VersusHide);
        break;

    case 7:
        CardBlue.load(":/images/images/Blaues Team Robin Hood.png");
        ui->lbl_BlueCard->setPixmap(CardBlue);
        ui->lbl_BlueCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_BlueCard->show();
        QTimer::singleShot(3000, this,  &Gladiatormain::BlueCardHide);
        ui->lbl_Versus->setText("Versus");
        //ui->lbl_Versus->setStyleSheet("font.pixelSize: 70");
        ui->lbl_Versus->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_Versus->show();
        QTimer::singleShot(3000, this, &Gladiatormain::VersusHide);
        break;

    }
}


void Gladiatormain::RedCardShow(int RedCard){
    QPixmap CardRed;

    switch (RedCard) {

    case 8:
        CardRed.load(":/images/images/Rotes Team Bounty Hunter.png");
        ui->lbl_RedCard->setPixmap(CardRed);
        ui->lbl_RedCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_RedCard->show();
        QTimer::singleShot(3000, this, &Gladiatormain::RedCardHide);
        break;

    case 9:
        CardRed.load(":/images/images/Rotes Team Guardian.png");
        ui->lbl_RedCard->setPixmap(CardRed);
        ui->lbl_RedCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_RedCard->show();
        QTimer::singleShot(3000, this, &Gladiatormain::RedCardHide);
        break;

    case 10:
        CardRed.load(":/images/images/Rotes Team Vikinger.png");
        ui->lbl_RedCard->setPixmap(CardRed);
        ui->lbl_RedCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_RedCard->show();
        QTimer::singleShot(3000, this, &Gladiatormain::RedCardHide);
        break;

    case 11:
        CardRed.load(":/images/images/Rotes Team King Arthur.png");
        ui->lbl_RedCard->setPixmap(CardRed);
        ui->lbl_RedCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_RedCard->show();
        QTimer::singleShot(3000, this, &Gladiatormain::RedCardHide);
        break;

    case 12:
        CardRed.load(":/images/images/Rotes Team God Of Nature.png");
        ui->lbl_RedCard->setPixmap(CardRed);
        ui->lbl_RedCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_RedCard->show();
        QTimer::singleShot(3000, this, &Gladiatormain::RedCardHide);
        break;

    case 13:
        CardRed.load(":/images/images/Rotes Team Mechaknight.png");
        ui->lbl_RedCard->setPixmap(CardRed);
        ui->lbl_RedCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_RedCard->show();
        QTimer::singleShot(3000, this, &Gladiatormain::RedCardHide);
        break;

    case 14:
        CardRed.load(":/images/images/Rotes Team Robin Hood.png");
        ui->lbl_RedCard->setPixmap(CardRed);
        ui->lbl_RedCard->setAttribute(Qt::WA_TranslucentBackground);
        ui->lbl_RedCard->show();
        QTimer::singleShot(3000, this, &Gladiatormain::RedCardHide);
        break;

    }
}


void Gladiatormain::BlueCardHide(){

    ui->lbl_BlueCard->hide();
}


void Gladiatormain::RedCardHide(){

    ui->lbl_RedCard->hide();
}


void Gladiatormain::VersusHide(){

    ui->lbl_Versus->hide();
}










