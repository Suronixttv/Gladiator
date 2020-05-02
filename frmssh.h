#ifndef FRMSSH_H
#define FRMSSH_H

#include <QString>
#include <ssh.h>
#include <QDialog>

namespace Ui {
class FrmSSH;
}

class FrmSSH : public QDialog
{
    Q_OBJECT

public:
    explicit FrmSSH(QWidget *parent = nullptr);
    ~FrmSSH();


private slots:
    void on_Schwert_btn_clicked();

    void on_Schild_btn_clicked();

    void on_Hammer_btn_clicked();

    void closeEvent(QCloseEvent *event);

signals:

    void on_FrmSSH_closed(int Winner);

private:
    int Winner = 0;
    Ui::FrmSSH *ui;
    SSH *GameObj = new SSH;

};

#endif // FRMSSH_H
