#ifndef FRMADMINPANEL_H
#define FRMADMINPANEL_H

#include <QDialog>
#include <QMessageBox>
#include "datenbank.h"

namespace Ui {
class FrmAdminPanel;
}

class FrmAdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit FrmAdminPanel(QWidget *parent = nullptr);
    ~FrmAdminPanel();

private slots:

    void on_btn_addUser_clicked();

private:
    Ui::FrmAdminPanel *ui;
    Datenbank gladiatordb;
};

#endif // FRMADMINPANEL_H
