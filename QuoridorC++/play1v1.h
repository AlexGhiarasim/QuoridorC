#ifndef PLAY1V1_H_INCLUDED
#define PLAY1V1_H_INCLUDED
#include "variables.h"
#include "functionsforplay.h"
#include<time.h>
#include<stdio.h>
void Cronometru(int x,int y,int nrs) //deseneaza nr de secunde ramase pentru fiecare jucator
{
    for(i=x+1;i<100;i++)
        for(j=y+1;j<30;j++)
        putpixel(i,j,BLACK);
    int i,j;
    setcolor(RED);
    rectangle(x,y,x+80,y+25);
    char a[50];
    sprintf(a,"%d",nrs);
    setcolor(WHITE);
    settextstyle(1,0,1);
    outtextxy(x+10,y+5,a);

}
void play1v1()
{
    s:
    butonInapoi(14,15);
    //initialise
    player player1, player2;
    player1.line=9;
    player1.column=5;
    P1.y=9;
    P1.x=5;
    a[player1.line][player1.column]=1;
    player2.line=1;
    player2.column=5;
    P2.y=1;
    P2.x=5;
    a[player2.line][player2.column]=1;
    setcolor(BLACK);
    positionplayer1(9,5);
    positionplayer2(1,5);
    nrb1=10;
    nrb2=10;
    int turnplay=1; //player 1
    bool mutat;
    punct p; // p - poz.click
    POINT CursorPosition;
    int sec1=500, sec2=500;
    Cronometru(800,600,sec1);
    Cronometru(800,120,sec2);
    do
    {
        settextstyle(3,0,1);
        setcolor(WHITE);
        outtextxy(160,180,juc[turnplay]);
        mutat=FALSE;
        if(turnplay==1) // player 1
        {
        int csec;
        time_t tt;
        tm *ti;
        time(&tt);
        ti=localtime(&tt);
        csec=ti->tm_sec;
            while(mutat==FALSE&&sec1>0)
            {
                time(&tt);
                ti=localtime(&tt);
                if(csec!=ti->tm_sec)
                {
                    sec1--;
                    csec=ti->tm_sec;
                    Cronometru(800,600,sec1);
                }
                if((mousex()< 230 || mousex() >760) || (mousey() <110 || mousey() > 640))  //230,110,760,640 coord table
                {
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
                    int b=butonAles();
                    if(b==4)
                    {
                        CLOSE=1;
                        goto e;
                    }
                    else if (b==5)
                    {
                        cleardevice();
                        creeareMeniu();
                        goto e;
                    }
                }
                else
                {
                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        p.x=mousex();
                        p.y=mousey();
                    }
                    if((CursorPosition.x!=mousex() || CursorPosition.y!=mousey()) && nrb1>0)
                    {
                        redesignbariera(CursorPosition.x,CursorPosition.y);
                        CursorPosition.x=mousex();
                        CursorPosition.y=mousey();
                        designbariera(CursorPosition.x,CursorPosition.y);
                    }
                    if(selecttomove(player1,p)==1) // daca dorim sa mutam cerculetul
                    {
                        designmutare(player1);
                        if (ismouseclick(WM_LBUTTONDOWN))
                        {
                            clearmouseclick(WM_LBUTTONDOWN);
                            p.x=mousex();
                            p.y=mousey();
                            redesignmutare(player1);
                        }
                        switch(selectnewposition(player1,p))
                        {
                        case 1:
                        {
                            a[player1.line][player1.column]=0;
                            player1.line--;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;

                        }
                        case 2:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column++;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 3:
                        {
                            a[player1.line][player1.column]=0;
                            player1.line++;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 4:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column--;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 5:
                        {
                            a[player1.line][player1.column]=0;
                            player1.line-=2;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 6:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column+=2;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 7:
                        {
                            a[player1.line][player1.column]=0;
                            player1.line+=2;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 8:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column-=2;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 9:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column--;
                            player1.line--;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 10:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column++;
                            player1.line--;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 11:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column++;
                            player1.line++;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        case 12:
                        {
                            a[player1.line][player1.column]=0;
                            player1.column--;
                            player1.line++;
                            a[player1.line][player1.column]=1;
                            P1.x=player1.column;
                            P1.y=player1.line;
                            positionplayer1(player1.line,player1.column);
                            redesignmutare(player1);
                            mutat=TRUE;
                            break;
                        }
                        }
                    }
                    else if(nrb1>0&&plasareBariera(p.x,p.y)==1)
                    {
                        mutat=TRUE;
                        if(nrb1==10)
                        {
                            for(int i=650; i<=670; i++)
                                for(int j=765; j<=800; j++)
                                    putpixel(j,i,BLACK);
                        }
                        nrb1--;
                        settextstyle(3,0,1);
                        setcolor(WHITE);
                        outtextxy(758,650, mesaj[nrb1]);
                    }
                }
            }
            if(sec1==0)
            {
                redesignmutare(player1);
                goto p1l;
            }
            turnplay=0;
        }
        else
        {
            int csec;
            time_t tt;
            tm *ti;
            time(&tt);
            ti=localtime(&tt);
            csec=ti->tm_sec;
            while(mutat==FALSE&&sec2>0)
            {
                time(&tt);
                ti=localtime(&tt);
                if(csec!=ti->tm_sec)
                {
                    sec2--;
                    csec=ti->tm_sec;
                    Cronometru(800,120,sec2);
                }
                if((mousex()< 230 || mousex() >760) || (mousey() <110 || mousey() > 640))  //230,110,760,640 coord table
                {
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
                    int b=butonAles();
                    if(b==4)
                    {
                        CLOSE=1;
                        goto e;
                    }
                    else if (b==5)
                    {
                        cleardevice();
                        creeareMeniu();
                        goto e;
                    }
                }
                else
                {
                    if((CursorPosition.x!=mousex() || CursorPosition.y!=mousey()) && nrb2>0)
                    {
                        redesignbariera(CursorPosition.x,CursorPosition.y);
                        CursorPosition.x=mousex();
                        CursorPosition.y=mousey();
                        designbariera(CursorPosition.x,CursorPosition.y);
                    }
                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        p.x=mousex();
                        p.y=mousey();
                    }
                    if(selecttomove(player2,p)==1) // daca dorim sa mutam cerculetul
                    {
                        designmutare(player2);
                        if (ismouseclick(WM_LBUTTONDOWN))
                        {
                            clearmouseclick(WM_LBUTTONDOWN);
                            p.x=mousex();
                            p.y=mousey();
                            redesignmutare(player2);
                        }
                        switch(selectnewposition(player2,p))
                        {
                        case 1:
                        {
                            redesignmutare(player2);
                            a[player2.line][player2.column]=0;
                            player2.line--;
                            a[player2.line][player2.column]=1;
                            P2.x=player2.column;
                            P2.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;

                        }
                        case 2:
                        {
                            redesignmutare(player2);
                            a[player2.line][player2.column]=0;
                            player2.column++;
                            a[player2.line][player2.column]=1;
                            P2.x=player2.column;
                            P2.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 3:
                        {
                            redesignmutare(player2);
                            a[player2.line][player2.column]=0;
                            player2.line++;
                            a[player2.line][player2.column]=1;
                            P2.x=player2.column;
                            P2.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 4:
                        {
                            redesignmutare(player2);
                            a[player2.line][player2.column]=0;
                            player2.column--;
                            a[player2.line][player2.column]=1;
                            P2.x=player2.column;
                            P2.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 5:
                        {
                            a[player2.line][player2.column]=0;
                            player2.line-=2;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 6:
                        {
                            a[player2.line][player2.column]=0;
                            player2.column+=2;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 7:
                        {
                            a[player2.line][player2.column]=0;
                            player2.line+=2;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 8:
                        {
                            a[player2.line][player2.column]=0;
                            player2.column-=2;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 9:
                        {
                            a[player2.line][player2.column]=0;
                            player2.column--;
                            player2.line--;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 10:
                        {
                            a[player2.line][player2.column]=0;
                            player2.column++;
                            player2.line--;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 11:
                        {
                            a[player2.line][player2.column]=0;
                            player2.column++;
                            player2.line++;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        case 12:
                        {
                            a[player2.line][player2.column]=0;
                            player2.column--;
                            player2.line++;
                            a[player2.line][player2.column]=1;
                            P1.x=player2.column;
                            P1.y=player2.line;
                            positionplayer2(player2.line,player2.column);
                            redesignmutare(player2);
                            mutat=TRUE;
                            break;
                        }
                        }
                    }
                    else if(nrb2>0&&plasareBariera(p.x,p.y)==1)
                    {
                        mutat=TRUE;
                        if(nrb2==10)
                        {
                            for(int i=80; i<=100; i++)
                                for(int j=417; j<=430; j++)
                                    putpixel(j,i,BLACK);
                        }
                        nrb2--;
                        settextstyle(3,0,1);
                        setcolor(WHITE);
                        outtextxy(410,80, mesaj[nrb2]);
                    }
                }
            }
             if(sec2==0)
            {
                redesignmutare(player1);
                goto p2l;
            }
            turnplay=1;
        }
    }
    while(player1.line!=1 && player2.line!=9);
    int butonAp;
    if(player1.line==1)
    {
        p2l:
        cleardevice();
        readimagefile("juc1win.jpg",0,0,1000,700);
        butonInapoi(14,15);
        butonIesire(2,15);
        butonPlayAgain(11,15);
    }
    else
    {
        p1l:
        cleardevice();
        readimagefile("juc2win.jpg",0,0,1000,700);
        butonPlayAgain(11,15);
        butonInapoi(14,15);
        butonIesire(2,15);
    }
    game=1;
    afisareTitlu();
    while(butonAp !=5 && butonAp!=4 && butonAp!=6)
    {
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
                {
                    butonInapoi(14,15);
                    if(CursorPosition.x>400 && CursorPosition.x<600 && CursorPosition.y>360 && CursorPosition.y<440)
                      butonPlayAgain(4,4);
                    else
                      butonPlayAgain(11,15);
                }

            }
        }
        butonAp=butonAles();
        if(butonAp == 4)
            CLOSE=1;
        if(butonAp==6)
        {
            cleardevice();
            REPLAY=1;
        }

    }
    cleardevice();
    game=0;
e:
    ;
}
#endif // PLAY1V1_H_INCLUDED
