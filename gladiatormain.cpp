#include "gladiatormain.h"
#include "ui_gladiatormain.h"
#include <QPixmap>

Gladiatormain::Gladiatormain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gladiatormain)
{
    ui->setupUi(this);
    this->sshgame = new FrmSSH;
    connect(sshgame,SIGNAL(on_FrmSSH_closed(int)),this,SLOT(on_sshclosed(int)));
    game->SetupGame();
    ui->btn_Close->hide();
    ui->btn_Rematch->hide();


    ui->lbl_Count->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_Round->setAttribute(Qt::WA_TranslucentBackground);

    ui->lbl_Username->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_Player->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_Wins->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_WinCount->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_Loses->setAttribute(Qt::WA_TranslucentBackground);
    ui->lbl_LoseCount->setAttribute(Qt::WA_TranslucentBackground);

    ui->lbl_WinCount->setNum(game->getBluePlayerWins());
    ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());

    ui->lbl_BlueHPBar->setScaledContents(true);
    ui->lbl_RedHPBar->setScaledContents(true);

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


    qDebug()<<"Karte 1 gespielt!";
    game->setBluePlayerAuswahl(1);
    game->KIauswahl();
    qDebug()<<"Auswahl durchgeführt";
    ui->listWidget_test->addItem(game->getKampfNamen());
    qDebug()<<"KampfName Ausgegeben";
    int winner = game->KampfAuswahl();
    qDebug()<<"Gewinner festgelegt";
    QString winnercard = game->getCardName(winner);
    qDebug()<<"Gewinner Name gespeichert";
    ui->listWidget_test->addItem(winnercard + " Wins!");
    qDebug()<<"gewinner Ausgabe";


    if(winner == 1){
        qDebug()<<"Blue Player Win";
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        qDebug()<<"Löschen gelungen";
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Label hide//
        //-----------------------------//
        this->RedLabelHide(Verlierer);
        //-----------------------------//

    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";

    }else if(winner == game->getRedPlayerAuswahl()){
        qDebug()<<"keine Karte gelöscht";
        ui->btn_card1->hide();
        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }
    qDebug()<<"Ende der Gewinner If-Else";

    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);
        ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        ui->lbl_WinCount->setNum(game->getBluePlayerWins());
        qDebug()<<"Winner funktion gestartet";
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
        this->RedLabelHide(Verlierer);
        //-----------------------------//


    }else if(winner == 0){

        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";

    }else if(winner == game->getRedPlayerAuswahl()){
        qDebug()<<"Keine Karte gelöscht";
        ui->btn_card2->hide();
        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }


    qDebug()<<"Ende der Gewinner If-Else";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);
        ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);
        ui->lbl_WinCount->setNum(game->getBluePlayerWins());
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
        this->RedLabelHide(Verlierer);
        //-----------------------------//

    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";


    }else if(winner == game->getRedPlayerAuswahl()){
        ui->btn_card3->hide();
        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }


    qDebug()<<"Ende der Gewinner If-Else";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);
        ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){

        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);
        ui->lbl_WinCount->setNum(game->getBluePlayerWins());
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
        this->RedLabelHide(Verlierer);
        //-----------------------------//

    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";

    }else if(winner == game->getRedPlayerAuswahl()){
        ui->btn_card4->hide();
        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }

    qDebug()<<"Ende der Gewinner If-Else";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);
        ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);
        ui->lbl_WinCount->setNum(game->getBluePlayerWins());
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
        this->RedLabelHide(Verlierer);
        //-----------------------------//

    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";

    }else if(winner == game->getRedPlayerAuswahl()){
        ui->btn_card5->hide();
        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }

    qDebug()<<"Ende der Gewinner If-Else";



    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);
        ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);
        ui->lbl_WinCount->setNum(game->getBluePlayerWins());
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
    ui->listWidget_test->addItem(game->getKampfNamen());
    int winner = game->KampfAuswahl();
    QString winnercard = game->getCardName(winner);
    ui->listWidget_test->addItem(winnercard + " Wins!");


    if(winner == 6){
        int Verlierer = game->getRedPlayerAuswahl();
        qDebug()<< Verlierer << "verliert";
        game->KICardsDelete(Verlierer);
        this->ChangeHeartsRed(game->getRedPlayerHP());

        //Label hide//
        //-----------------------------//
        this->RedLabelHide(Verlierer);
        //-----------------------------//


    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";



    }else if(winner == game->getRedPlayerAuswahl()){
        ui->btn_card6->hide();
        this->ChangeHeartsBlue(game->getBluePlayerHP());
        qDebug()<<"Ende der Gewinner If-Else";


    }if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);
        ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);
        ui->lbl_WinCount->setNum(game->getBluePlayerWins());
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

        //Label hide//
        //-----------------------------//
        this->RedLabelHide(Verlierer);
        //-----------------------------//


    }else if(winner == 0){
        qDebug()<<"Draw";
        ui->listWidget_test->addItem("Draw");
        sshgame->show();
        qDebug()<<"SSH gesatartet";


    }else if(winner == game->getRedPlayerAuswahl()){
        qDebug()<<"Ki Gewinnt";
        ui->btn_card7->hide();
        this->ChangeHeartsBlue(game->getBluePlayerHP());
    }


    qDebug()<<"Gewinner If-Else benndet";


    if(game->getBluePlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Red Wins !");
        game->setWinner(2);
        ui->lbl_LoseCount->setNum(game->getBluePlayerLoses());
        ui->btn_Close->show();
        ui->btn_Rematch->show();

    }else if(game->getRedPlayerHP() == 0){
        ui->listWidget_test->addItem("Game Over Blue Wins!");
        game->setWinner(1);
        ui->lbl_WinCount->setNum(game->getBluePlayerWins());
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
        int verlierer = game->getRedPlayerAuswahl();
        this->RedLabelHide(verlierer);


    }else if(SSHWinner==2) {
        qDebug()<<"Rot gewinnt SSH";
        ui->listWidget_test->addItem(game->getCardName(Card_Red) + "Wins");

        switch (Card_Blue) {

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

void Gladiatormain::RedLabelHide(int RedCardHide){

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






