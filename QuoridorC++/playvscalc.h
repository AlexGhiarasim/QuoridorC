#ifndef PLAYVSCALC_H_INCLUDED
#define PLAYVSCALC_H_INCLUDED
#include "variables.h"
#include "functionsforplay.h"

void playvscalculator()
{
    butonInapoi(14,15);
    //initialise
    player player1, calculator;
    player1.line=9;
    player1.column=5;
    P1.y=9;
    P1.x=5;
    a[player1.line][player1.column]=1;
    calculator.line=1;
    calculator.column=5;
    P2.y=1;
    P2.x=5;
    a[calculator.line][calculator.column]=1;
    setcolor(BLACK);
    positionplayer1(9,5);
    positioncalculator(1,5);
    nrb1=10;
    nrb2=10;
    int turnplay=1; //player 1
    bool mutat;
    punct p;
    int elem[20][20]= {-1};
    POINT CursorPosition;
    int sec1=500;
    Cronometru(800,600,sec1);
    do
    {
        mutat=FALSE;

        if(turnplay==1)
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
                        goto a;
                    }
                    else if (b==5)
                    {
                        cleardevice();
                        creeareMeniu();
                        goto a;
                    }
                }
                else
                {
                    if((CursorPosition.x!=mousex() || CursorPosition.y!=mousey()) && nrb1>0)
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
            int cm=0;
            int m[20][20]={0};
            for(i=0; i<=19; i++)
                m[i][1]=m[i][19]=m[19][i]=m[1][i]=-1;
            for(i=2; i<=18; i++)
                for(j=2; j<=18; j++)
                    if(bariera[i][j]==1)
                        m[i][j]=-1;
                    else
                        m[i][j]=0;
            Lee(P1.x,P1.y,m,1);
            int mini=200;
            for(i=2; i<=18; i=i+2)
                if(m[2][i]<mini&&m[2][i]!=0)
                    mini=m[2][i];
            int minimC=200;
            for(i=0; i<=19; i++)
                m[i][1]=m[i][19]=m[19][i]=m[1][i]=-1;
            for(i=2; i<=18; i++)
                for(j=2; j<=18; j++)
                    if(bariera[i][j]==1)
                        m[i][j]=-1;
                    else
                        m[i][j]=0;
            Lee(P2.x,P2.y,m,1);
            for(i=2; i<=18; i=i+2)
                if(m[18][i]<minimC&&m[18][i]!=0)
                    minimC=m[18][i];
            if(minimC<=mini)
                cm=1;
            else
                cm=0;
            if(cm==0 && nrb2>0) ///pun bariera(blocheaza doar unul din cele mai bune drumuri posibile)
            {
                cout<<"se pune bariera";
                int m[20][20];
                for(i=0; i<=19; i++)
                    m[i][1]=m[i][19]=m[19][i]=m[1][i]=-1;
                for(i=2; i<=18; i++)
                    for(j=2; j<=18; j++)
                        if(bariera[i][j]==1)
                            m[i][j]=-1;
                        else
                            m[i][j]=0;
                Lee(P1.x,P1.y,m,1);
                int mini=100,im;
                for(i=2; i<=18; i=i+2)
                    if(m[2][i]<mini&&m[2][i]!=0)
                        mini=m[2][i],im=i;
                ok=0;
                PuneBariera(2,im,m);
                if(ok==1)
                {
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
                    turnplay=1;
                }
            }
            else if(cm==1 || nrb2==0)
            {
                mCalc=-1;
                for(i=0; i<=19; i++)
                    elem[i][1]=elem[i][19]=elem[19][i]=elem[1][i]=-1;
                for(i=2; i<=18; i++)
                    for(j=2; j<=18; j++)
                        if(bariera[i][j]==1)
                            elem[i][j]=-1;
                        else
                            elem[i][j]=0;
                verif=0;
                cout<<"matrice inainte de Lee"<<endl;
                for(int i=1; i<=19; i++)
                    {
                        for(j=1; j<=19; j++)
                            cout<<elem[i][j]<<' ';
                        cout<<endl;
                    }
                Lee(P2.x,P2.y,elem,1);
                cout<<"matrice Lee"<<endl;
                for(int i=1; i<=19; i++)
                    {
                        for(j=1; j<=19; j++)
                            cout<<elem[i][j]<<' ';
                        cout<<endl;
                    }
                int nrmutarimin=200;
                int pozy;
                for(i=2; i<=18; i=i+2)
                    if(elem[18][i]<nrmutarimin&&elem[18][i]!=0)
                    {
                        nrmutarimin=elem[18][i];
                        pozy=i;
                    }
                cout<<"pozitia minima este "<<pozy<<endl;
                Traseu(elem,18,pozy);
                cout<<"calc muta spre "<<mCalc<<endl;
                if(verif==1)
                {
                    a[calculator.line][calculator.column]=0;
                    calculator.line+=dy[mCalc];
                    calculator.column+=dx[mCalc];
                    redesignmutare(calculator);
                    if(a[calculator.line][calculator.column]==1)
                    {
                        ///daca nu e bariera dupa piesa
                        if(bariera[2*calculator.line+dy[mCalc]][2*calculator.column+dx[mCalc]]==0&&elem[2*calculator.line+dy[mCalc]][2*calculator.column+dx[mCalc]]==0)
                        {
                            cout<<"nu e bariera in spate"<<endl;
                            calculator.line+=dy[mCalc];
                            calculator.column+=dx[mCalc];
                            a[calculator.line][calculator.column]=1;
                            P2.x=calculator.column;
                            P2.y=calculator.line;
                        }
                        else
                        {
                            cout<<"este bariera"<<endl;
                            for(i=0; i<=19; i++)
                                elem[i][1]=elem[i][19]=elem[19][i]=elem[1][i]=-1;
                            for(i=1; i<=19; i++)
                                for(j=1; j<=19; j++)
                                    if(bariera[i][j]==1)
                                        elem[i][j]=-1;
                                    else
                                        elem[i][j]=0;
                            Lee(calculator.column,calculator.line,elem,1);
                            int nrmutarimin=100;
                            int pozy;
                            for(i=2; i<=18; i=i+2)
                                if(elem[18][i]<nrmutarimin&&elem[18][i]>0)
                                {
                                    nrmutarimin=elem[18][i];
                                    pozy=i;
                                }
                            mCalc=0,verif=0;
                            Traseu(elem,18,pozy);
                            calculator.line+=dy[mCalc];
                            calculator.column+=dx[mCalc];
                            cout<<"Linia este "<<calculator.line<<endl;
                            if(calculator.line==8)
                                {
                                    if(elem[2*calculator.line+2][2*calculator.column-1]==0&&calculator.column>1)
                                    calculator.column--,calculator.line++;
                                else
                                    if(elem[2*calculator.line+2][2*calculator.column+1]==0&&calculator.column<9)
                                        calculator.column++,calculator.line++;
                                    else if(elem[2*calculator.line+2][2*calculator.column-1]!=0&&elem[2*calculator.line+2][2*calculator.column+1]!=0)
                                        calculator.line--;
                                }
                            a[calculator.line][calculator.column]=1;
                        }
                    }
                    cout<<"Calculator line si column "<<calculator.line<<' '<<calculator.column<<endl;
                    positioncalculator(calculator.line,calculator.column);
                    a[calculator.line][calculator.column]=1;
                    P2.x=calculator.column;
                    P2.y=calculator.line;
                    cout<<P2.y<< ' '<<P2.x<<endl;
                }
                cout<<"matrice"<<endl;
                for(int i=1; i<=19; i++)
                    {
                        for(j=1; j<=19; j++)
                            cout<<elem[i][j]<<' ';
                        cout<<endl;
                    }
                turnplay=1;
            }
        }
        p.x=0;
        p.y=0;
    }
    while(player1.line!=1 && calculator.line!=9);
    cout<<"matrice final"<<endl;
    for(int i=1; i<=19; i++)
    {
        for(j=1; j<=19; j++)
            cout<<elem[i][j]<<' ';
        cout<<endl;
    }
    int butonAp;
    if(player1.line==1)
    {
        cleardevice();
        readimagefile("winvscalc.jpg",0,0,1000,700);
        butonPlayAgain(11,15);
        butonInapoi(14,15);
        butonIesire(2,15);
    }
    else
    {
        p1l:
        cleardevice();
        readimagefile("losevscalc.jpg",0,0,1000,700);
        butonPlayAgain(11,15);
        butonInapoi(14,15);
        butonIesire(2,15);
    }
    afisareTitlu();
    game=1;
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
a:
    ;
}

#endif // PLAYVSCALC_H_INCLUDED
