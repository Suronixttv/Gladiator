#include "ssh.h"



SSH::SSH()
{

}

int SSH::SSHGame()
{

SSHKI = rand() % 3 + 1;


switch (SpielerWahl)
{
case 1: if(SSHKI == 1){return(0);}
    else if(SSHKI == 2){return(1);}
    else if(SSHKI == 3){return(2);}
    break;
case 2: if(SSHKI == 1){return(2);}
    else if(SSHKI == 2){return(0);}
    else if(SSHKI == 3){return(1);}
    break;
case 3: if(SSHKI == 1){return(1);}
    else if(SSHKI == 2){return(2);}
    else if(SSHKI == 3){return(0);}
    break;
}
}

int SSH::PSchwert()
{
   setSpielerWahl(1);
   return(SSHGame());
}

int SSH::PSchild()
{
    setSpielerWahl(2);
    return(SSHGame());
}

int SSH::PHammer()
{
    setSpielerWahl(3);
    return(SSHGame());
}

void SSH::setSpielerWahl(int Sp)
{
    this->SpielerWahl = Sp;
}













