#include "wip.h"
#include "ui_wip.h"

Wip::Wip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wip)
{
    ui->setupUi(this);
}

Wip::~Wip()
{
    delete ui;
}

void Wip::on_pushButton_clicked()
{
    Wip::close();
}

