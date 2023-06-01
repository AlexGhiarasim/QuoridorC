#include <iostream>
#include "buttons.h"
#include "variables.h"
#include "play1v1.h"
#include "playvscalc.h"
#include "functionsforplay.h"
using namespace std;
int main()
{
    initwindow(1000,700, "Quoridor");
    readimagefile("background.jpg",0,0,1000,700);
    creeareMeniu();
    for(int i=1; i<=19; i++)
        bariera[19][i]=bariera[i][19]=1;
    int butonul_apasat=0;
    POINT CursorPosition;
    do
    {
        if(CursorPosition.x!=mousex() and CursorPosition.y!=mousey())
        {
            // buton1Vs1(12,15); ///buton1
            // butonVsComp(11,15);///buton2
            // butonReguli(1,15);///buton3
            CursorPosition.x=mousex();
            CursorPosition.y=mousey();
            if(CursorPosition.x>300 && CursorPosition.x<700 && CursorPosition.y>200 && CursorPosition.y<300)
                buton1Vs1(4,4);
            else
            {
                buton1Vs1(12,15);
                if(CursorPosition.x>300 && CursorPosition.x<700 && CursorPosition.y>375 && CursorPosition.y<475)
                    butonVsComp(4,4);
                else
                {
                    butonVsComp(11,15);
                    if(CursorPosition.x>300 && CursorPosition.x<700 && CursorPosition.y>550 && CursorPosition.y<650)
                        butonReguli(4,4);
                    else
                    {
                        butonReguli(1,15);
                        if(CursorPosition.x>1 && CursorPosition.x<71 && CursorPosition.y>220 && CursorPosition.y<380)
                            butonIesire(4,4);
                        else
                            butonIesire(2,15);
                    }
                }
            }
        }
        butonul_apasat=butonAles(); // alegere buton
        if (butonul_apasat==1)
        {
            s:
            cleardevice();
            readimagefile("background.jpg",0,0,1000,700);
            butonIesire(2,15);
             nrb1=nrb2=10;
            createtable(1);
            for(int i=1; i<=19; i++)
                bariera[19][i]=bariera[i][19]=bariera[1][i]=bariera[i][1]=1;
            for(int i=2; i<=18; i++)
                for(int j=2; j<=18; j++)
                    bariera[i][j]=0;
            for(int i=1; i<=9; i++)
                for(int j=1; j<=9; j++)
                    a[i][j]=0;
            REPLAY=0;
            play1v1();   // inceperea jocului de 1v1 in header-ul play1v1.h
            if(CLOSE==1)
            {
                cleardevice();
                closegraph();
                return 0;
            }
            if(REPLAY==1)
                goto s;
            readimagefile("background.jpg",0,0,1000,700);
            creeareMeniu();
        }
        else if(butonul_apasat==2)
        {
            k:
            cleardevice();
            readimagefile("background.jpg",0,0,1000,700);
            butonIesire(2,15);
            butonInapoi(14,15);
            nrb1=nrb2=10;
            createtable(2);
            for(int i=1; i<=19; i++)
                bariera[19][i]=bariera[i][19]=bariera[1][i]=bariera[i][1]=1;
            for(int i=2; i<=18; i++)
                for(int j=2; j<=18; j++)
                    bariera[i][j]=0;
            for(int i=1; i<=9; i++)
                for(int j=1; j<=9; j++)
                    a[i][j]=0;
            REPLAY=0;
            playvscalculator();
            if(CLOSE==1)
            {
                cleardevice();
                closegraph();
                return 0;
            }
            if(REPLAY==1)
                goto k;
            readimagefile("background.jpg",0,0,1000,700);
            creeareMeniu();
        }
        else if(butonul_apasat==3)
        {
            cleardevice();
            butonInapoi(14,15);
            butonIesire(2,15);
            afisareTitlu();
            writeRules(0);
            int pozscris=0;
            while(butonul_apasat!=5)
            {
                butonul_apasat=butonAles();
                if(butonul_apasat==4)
                {
                    closegraph();
                    return 0;
                }
                if(CursorPosition.x!=mousex() and CursorPosition.y!=mousey())
                {
                    CursorPosition.x=mousex();
                    CursorPosition.y=mousey();
                    if(CursorPosition.x>1 && CursorPosition.x<71 && CursorPosition.y>220 && CursorPosition.y<380)
                        butonIesire(4,4);
                    else
                    {
                        butonIesire(2,15);
                        if(CursorPosition.x>928 && CursorPosition.x<998 && CursorPosition.y>220 && CursorPosition.y<380)
                            butonInapoi(4,4);
                        else
                            butonInapoi(14,15);
                    }
                }
                if (GetAsyncKeyState(40) && pozscris <=300)
                {
                    pozscris+=20;
                    setcolor(RED);
                    rectangle(73,0,925,700);
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(400,400,RED);
                    setcolor(BLACK);
                    line(73,0,73,700);
                    setcolor(BLACK);
                    line(925,0,925,700);
                    writeRules(pozscris);
                    delay(150);
                }
                if (GetAsyncKeyState(38) && pozscris>=0)
                {
                    pozscris-=20;
                    setcolor(RED);
                    rectangle(73,0,925,700);
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(400,400,RED);
                    setcolor(BLACK);
                    line(925,0,925,700);
                    setcolor(BLACK);
                    line(73,0,73,700);
                    writeRules(pozscris);
                    delay(150);
                }
            }
            cleardevice();
            readimagefile("background.jpg",0,0,1000,700);
            creeareMeniu();
        }
    }
    while (butonul_apasat!=4);  //instructiunile se modifica in momentul apasarii butoanelor
    closegraph();
    return 0;
}
