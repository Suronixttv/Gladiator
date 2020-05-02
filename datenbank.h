#ifndef DATENBANK_H
#define DATENBANK_H
#include<QtSql>


class Datenbank
{
public:
    Datenbank();
    bool connOpen();
    void connClose();
    void addUser(QString Username, QString Name,QString Passwort,bool Admin);
    bool Login(QString User,QString Passwort);
    bool checkAdmin();
    void Logout();
    void setUsername(QString Username);
    void setWins(int W, QString Name);
    void setLoses(int L, QString Name);

    QSqlDatabase getMyDb();
    QString getUsername();
    int getWins(QString Name);
    int getLoses(QString Name);


private:
    QString Username = "no";
    QSqlDatabase mydb;
};

#endif // DATENBANK_H
