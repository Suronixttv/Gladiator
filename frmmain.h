#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "gladiatormain.h"
#include "wip.h"
#include "frmlogin.h"
#include "frmhighscore.h"

namespace Ui {
class FrmMain;
}

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_btn_close_clicked();

    void on_btn_Help_clicked();

    void on_btn_Singleplayer_clicked();

    void on_btn_Multiplayer_clicked();

    void on_btn_Login_clicked();

    void on_btn_Highscore_clicked();

private:
    Ui::FrmMain *ui;
    Gladiatormain *maingame = new Gladiatormain;
    Wip *wip = new Wip;
    frmLogin *login = new frmLogin;
    frmHighscore *highscore = new frmHighscore;
};

#endif // FRMMAIN_H
