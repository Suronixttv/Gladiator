#include "frmhighscore.h"
#include "ui_frmhighscore.h"

frmHighscore::frmHighscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmHighscore)
{
    ui->setupUi(this);
    this->loadHigscorelist();
}

frmHighscore::~frmHighscore()
{
    delete ui;
}

void frmHighscore::loadHigscorelist(){

    QSqlQueryModel  *modal =new QSqlQueryModel();

    this->gladiatordb.connOpen();

    QSqlQuery* qry = new QSqlQuery(this->gladiatordb.getMyDb());

    qry->prepare("Select Username,Wins,Loses from User Order By Wins");
    qry->exec();

    modal->setQuery(*qry);



    ui->tableView->setModel(modal);
    qDebug()<< (modal->rowCount());
    this->gladiatordb.connClose();


}
