#ifndef GLADIATORMAIN_H
#define GLADIATORMAIN_H

#include <QDialog>
#include <windows.h>
#include "frmssh.h"
#include "gladiatorgame.h"
#include "cardsfrm.h"
#include <qtimer.h>



namespace Ui {
class Gladiatormain;
}

class Gladiatormain : public QDialog
{
    Q_OBJECT

public:
    explicit Gladiatormain(QWidget *parent = nullptr);
    ~Gladiatormain();
    //void RedLabelHide(int RedCardHide);
    void Counter();
    void ChangeHeartsRed(int redHearts);
    void ChangeHeartsBlue(int blueHearts);
    void setUsername(QString User);
    void BlueCardShow(int BlueCard);
    void RedCardShow(int RedCard);
    void BlueCardHide();
    void RedCardHide();
    void VersusHide();

private slots:
    void on_btn_card1_rightClicked();

    void on_btn_card1_clicked();

    void on_btn_card2_clicked();

    void on_btn_card2_rightClicked();

    void on_btn_card3_clicked();

    void on_btn_card3_rightClicked();

    void on_btn_card4_clicked();

    void on_btn_card4_rightClicked();

    void on_btn_card5_clicked();

    void on_btn_card5_rightClicked();

    void on_btn_card6_clicked();

    void on_btn_card6_rightClicked();

    void on_btn_card7_clicked();

    void on_btn_card7_rightClicked();

    void on_sshclosed(int SSHWinner);

    void on_btn_Rematch_clicked();

    void on_btn_Close_clicked();

    void RedLabelHide();

    void BlueButtonHide();


private:
    Ui::Gladiatormain *ui;
    gladiatorgame *game = new gladiatorgame;
    FrmSSH *sshgame;
    Cardsfrm *CardsFrm = new Cardsfrm;
    QString Username;

 };

#endif // GLADIATORMAIN_H
