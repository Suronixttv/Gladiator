#include "datenbank.h"

Datenbank::Datenbank()
{

}

bool Datenbank::connOpen(){

    this->mydb = QSqlDatabase::addDatabase("QSQLITE");
    this->mydb.setDatabaseName("debug/GladiatorDB.db");

    if(this->mydb.open()){

        return(true);
        qDebug()<<"Datenbank geöffnet!";

    }else{

        return(false);
        qDebug()<<"Datenbank nicht geöffnet!";
    }
}

void Datenbank::connClose(){

    this->mydb.close();
    this->mydb.removeDatabase(QSqlDatabase::defaultConnection);

}

bool Datenbank::Login(QString User, QString Passwort){

    this->connOpen();

    QSqlQuery qry;
    qry.prepare("SELECT * from User where Username = '"+User +"' and Passwort='"+Passwort+"' ");
    if(qry.exec()){

        int count = 0;
        while(qry.next()){

            count++;
        }

        if(count==1){

            this->setUsername(User);
            return(true);

        }else {

            return(false);
        }

    }
    this->connClose();
}

void Datenbank::addUser(QString Username, QString Name, QString Passwort, bool Admin){

    qDebug()<<"addUser gestartet";
    this->connOpen();
    QString adminstr;

    if(Admin == true){
       qDebug()<<"Admin true";
        adminstr = QString::number(1);

    }else if(Admin == false){
        qDebug()<<"Admin false";
        adminstr = QString::number(0);
    }

    qDebug()<<"qry erstellt";
    QSqlQuery qry;
    qry.prepare("INSERT INTO User (Username,Name,Passwort,Wins,Loses,Admin) VALUES(:Username, :Name, :Passwort, :Wins, :Loses, :Admin)");
    qry.bindValue(":Username", Username);
    qry.bindValue(":Name", Name);
    qry.bindValue(":Passwort", Passwort);
    qry.bindValue(":Wins", 0);
    qry.bindValue(":Loses", 0);
    qry.bindValue(":Admin", adminstr);

    if(qry.exec()){

        qDebug()<<"User hinzugefügt!";
        this->connClose();

    }else{

        qDebug()<<"Querry fehlgeschlagen";
        qDebug()<<qry.lastError().text();
        this->connClose();
    }

this->connClose();

}

bool Datenbank::checkAdmin(){

    qDebug()<<"CheckAdmin gestartet";
    this->connOpen();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM User WHERE Username = '"+this->Username +"' AND admin = 1");
    if(qry.exec()){

        int count = 0;
        while(qry.next()){

            count++;

        }

        if(count==1){

            return(true);

        }else {

            return(false);
        }


    }
  this->connClose();


}

QSqlDatabase Datenbank::getMyDb(){

    return(this->mydb);

}

QString Datenbank::getUsername(){

    return(this->Username);

}

int Datenbank::getWins(QString Name){

    qDebug()<<"In DB::getwins";
    int Wins;
    this->connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT Wins FROM User WHERE Username = '"+Name+"'");

    if(qry.exec()){

            int W = qry.record().indexOf("Wins");
            Wins = qry.value(W).toInt();
            qDebug()<<"Wins i DB: " + qry.value(W).toString();
            qDebug()<<"int Wins =" + QString::number(Wins);
            this->connClose();
            qDebug()<<"Wins ausgelesen";
            qDebug()<<"Wins:" + QString::number(Wins);
            return(Wins);

    }else{
        qDebug()<<"Fehler";
       return(0);
    }

    this->connClose();

}


int Datenbank::getLoses(QString Name){

    qDebug()<<"Inside Db getLoses";
    int Loses;
    this->connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT Loses FROM User WHERE Username = '"+Name+"'");
    qry.exec();

    if(qry.exec()){
            int L = qry.record().indexOf("Loses");
            Loses = qry.value(L).toInt();
            qDebug()<<"Loses in DB:" + qry.value(L).toString();
            qDebug()<<"int Loses =" + QString::number(Loses);
            this->connClose();
            qDebug()<<"Loses ausgelesen";
            return(Loses);

    }else{
        qDebug()<<"Fehler";
       return(0);
    }


}

void Datenbank::Logout(){

    this->Username = "no";
}

void Datenbank::setUsername(QString Username){

    this->Username = Username;

}

void Datenbank::setWins(int W, QString Name){

    QString wins = QString::number(W);

    this->connOpen();
    QSqlQuery qry;
    qry.prepare("UPDATE User SET Wins = '"+QString::number(W)+"' WHERE Username = '"+Name+"'");
   // qry.bindValue(":win", wins);
    qry.exec();
    if(qry.exec()){

        qDebug()<<"Updaten der Wins:" + wins + "Bei: " + Name;

    }else if (!qry.exec()) {
        qDebug()<<"Fehler beim Updaten der Wins";
}

    this->connClose();

}

void Datenbank::setLoses(int L, QString Name){

    QString loses = QString::number(L);

    this->connOpen();
    QSqlQuery qry;
    qry.prepare("UPDATE User SET Loses = '"+QString::number(L)+"' WHERE Username = '"+Name+"'");
   // qry.bindValue(":win", loses);
    qry.exec();
    if(qry.exec()){

        qDebug()<<"Updaten der Loses: " + loses + "Bei: " + Name;

    }else if (!qry.exec()) {

        qDebug()<<"Fehler beim Updaten der Wins";
}

    this->connClose();

}

