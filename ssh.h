#ifndef SSH_H
#define SSH_H
#include <QString>

class SSH
{
public:
    SSH();
    int SSHGame();
    int PSchwert();
    int PSchild();
    int PHammer();
    int getWinner();
    void setWinner(int w);
    void setSpielerWahl(int Sp);



private:
    int SSHKI = 0;
    int SpielerWahl = 0;
    int Winner = 0;



};

#endif // SSH_H
