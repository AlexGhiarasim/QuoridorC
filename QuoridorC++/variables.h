#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
#include <graphics.h>
#include <winbgim.h>
#include <cmath>
#include <cstring>
#include<string>
#include<queue>
#include<cstdlib>
#include<time.h>
#include <windows.h>
// declararile globale/ variabile utilizate in mai multe functii si/sau in int main()
struct punct
{
    int x,y;
};
struct player
{
    int line,column;
};
struct dreptunghi
{
    punct sS,dJ;
};
struct buton
{
    dreptunghi D;
} b[5];
int nrb1=10,nrb2=10,a[10][10],bariera[20][20],ok, verif=0,mCalc,CLOSE=0,REPLAY=0,game=0;
int dy[4]= {-1,0,1,0},dx[4]= {0,1,0,-1},i,j; ///0-nord,1-est,2-sud,3-vest
char mesaj [12][3]= {"0","1","2","3","4","5","6","7","8","9","10"},juc[3][3]= {"2","1"};
punct P1, P2;

#endif // VARIABLES_H_INCLUDED
