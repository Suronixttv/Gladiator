#ifndef FRMHIGHSCORE_H
#define FRMHIGHSCORE_H

#include <QDialog>
#include"datenbank.h"

namespace Ui {
class frmHighscore;
}

class frmHighscore : public QDialog
{
    Q_OBJECT

public:
    explicit frmHighscore(QWidget *parent = nullptr);
    ~frmHighscore();
    void loadHigscorelist();

private:
    Ui::frmHighscore *ui;
    Datenbank gladiatordb;
};

#endif // FRMHIGHSCORE_H
