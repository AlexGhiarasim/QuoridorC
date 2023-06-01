#ifndef FUNCTIONSFORPLAY_H_INCLUDED
#define FUNCTIONSFORPLAY_H_INCLUDED
#include "variables.h"
#include "play1v1.h"
int apartinepatrat(punct p, int pozx,int pozy) // daca pozitia mouse-ului se afla intr-un patrat din tabla de joc
{
    return p.x>=pozx && p.x<=pozx+38 && p.y>=pozy && p.y<=pozy+38;
}
int Lee(int x,int y,int m[20][20], int nr) //Alg lui Lee pentru labirintul de bariere
{
    queue<punct>q;
    punct el,aux;
    m[2*y][2*x]=1;
    el.x=2*x,el.y=2*y;
    q.push(el);
    while(!q.empty())
    {
        el=q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            aux.x=el.x+dx[k];
            aux.y=el.y+dy[k];
            if(m[aux.y][aux.x]==0 && m[aux.y+dy[k]][aux.x+dx[k]]==0)
            {
                aux.x=el.x+2*dx[k];
                aux.y=el.y+2*dy[k];
                m[aux.y][aux.x]=m[el.y][el.x]+1;
                q.push(aux);
            }
        }
    }
    for(j=2; j<=18; j=j+2)
        if(nr==2)
        {
            if(m[18][j]>0)
                return 0;///nu se blocheaza
        }
        else if(m[2][j]>0)
            return 0;
    return 1;
}

int Blocheaza() //verifica prin alg lui Lee daca intr-un labirint exista o iesire in cazul punerii unei bariere
{
    int i,j;
    int drum[20][20];
    ///bordare
    for(i=1; i<=19; i++)
        drum[i][1]=drum[i][19]=drum[19][i]=drum[1][i]=-1;
    for(i=2; i<=18; i++)
        for(j=2; j<=18; j++)
            if(bariera[i][j]==1)
                drum[i][j]=-1;
            else
                drum[i][j]=0;
    int ok1=Lee(P1.x,P1.y,drum,1);
    for(i=2; i<=18; i++)
        for(j=2; j<=18; j++)
            if(bariera[i][j]==1)
                drum[i][j]=-1;
            else
                drum[i][j]=0;
    int ok2=Lee(P2.x,P2.y,drum,2);
    if(ok1==1)
        return 1;
    if(ok2==1)
        return 1;
    return 0;
}
int plasareBariera(int x, int y)  //functie ce afiseaza grafic o bariera in functie de regulile de plasare a barierelor
{
    int pozx,pozy;
    pozx=(x-230)/57+1;
    pozy=(y-110)/57+1;
    if(x>249&&x<760&&y>129&&y<640)
    {
        if((x<pozx*57+230&&x>230+pozx*57-57+19)&&(y>pozy*57-57+110&&y<pozy*57+110-57+19)) ///bariera orizontala
        {
            if(bariera[2*pozy-1][2*pozx]==0&&bariera[2*pozy-1][2*pozx+1]==0&&bariera[2*pozy-1][2*pozx+2]==0)///verific daca nu se suprapune cu o alta bariera
            {
                bariera[2*pozy-1][2*pozx]=bariera[2*pozy-1][2*pozx+1]=bariera[2*pozy-1][2*pozx+2]=1;
                if(Blocheaza()==0)
                {
                    setcolor(BROWN);
                    rectangle(230+pozx*57-57+19,110+57*pozy-57+1,230+pozx*57+38+19,110+57*pozy-57+19-1);
                    setfillstyle(SOLID_LINE, BROWN);
                    floodfill(230+pozx*57-57+19+1,110+57*pozy-57+1+1,BROWN);
                    return 1;
                }
                else
                    bariera[2*pozy-1][2*pozx]=bariera[2*pozy-1][2*pozx+1]=bariera[2*pozy-1][2*pozx+2]=0;
            }
        }
        else ///bara verticala
        {
            if((x>230+pozx*57-57&&x<230+pozx*57-57+19)&&(y>pozy*57+110-57+19&&y<pozy*57+110))
                if(bariera[2*pozy][2*pozx-1]==0&&bariera[2*pozy+1][2*pozx-1]==0&&bariera[2*pozy+2][2*pozx-1]==0)
                {
                    bariera[2*pozy][2*pozx-1]=bariera[2*pozy+1][2*pozx-1]=bariera[2*pozy+2][2*pozx-1]=1;
                    if(Blocheaza()==0)
                    {
                        setcolor(BROWN);
                        rectangle(230+pozx*57-57,pozy*57+110-57+19,230+pozx*57-57+19,pozy*57+110+57);
                        setfillstyle(SOLID_LINE, BROWN);
                        floodfill(230+pozx*57-57+1,pozy*57+110-57+19+1,BROWN);
                        return 1;
                    }
                    else
                        bariera[2*pozy][2*pozx-1]=bariera[2*pozy+1][2*pozx-1]=bariera[2*pozy+2][2*pozx-1]=0;
                }
        }
    }
    return 0;
}
int selecttomove(player curent,punct p) //daca se apasa intr-o anumita zona
{
    int pozx=249;
    pozx+=(curent.column-1)*38+19*(curent.column-1);
    int pozy=129;
    pozy+=(curent.line-1)*38+19*(curent.line-1);
    if(apartinepatrat(p,pozx,pozy))
        return 1;
    return 0;
}
int selectnewposition(player curent,punct p) //reda pozitia pe care se muta
{
    int pozx=249;
    pozx+=(curent.column-1)*38+19*(curent.column-1);
    int pozy=129;
    pozy+=(curent.line-1)*38+19*(curent.line-1);
    if(curent.line>1&&bariera[2*(curent.line-1)+1][2*curent.column]==0&& apartinepatrat(p,pozx,pozy-57)&&a[curent.line-1][curent.column]!=1)///nord
        return 1;
    if(curent.column<9 &&apartinepatrat(p,pozx+57,pozy)&&bariera[2*curent.line][2*curent.column+1]==0&&a[curent.line][curent.column+1]!=1)  ///est
        return 2;
    if(curent.line<9 && apartinepatrat(p,pozx,pozy+57)&&bariera[2*(curent.line)+1][2*curent.column]==0&&a[curent.line+1][curent.column]!=1)///sud
        return 3;
    if(curent.column>1&& apartinepatrat(p,pozx-57,pozy)&&bariera[2*curent.line][2*curent.column-1]==0&&a[curent.line][curent.column-1]!=1) ///vest
        return 4;
    if(curent.line>2&& bariera[2*(curent.line-1)+1][2*curent.column]==0 && bariera[2*(curent.line-1)-1][2*curent.column]==0 && apartinepatrat(p,pozx,pozy-114) && a[curent.line-1][curent.column]==1)///nord 2x
        return 5;
    if(curent.column<8 && apartinepatrat(p,pozx+114,pozy)&& bariera[2*curent.line][2*curent.column+1]==0 && bariera[2*curent.line][2*curent.column+3]==0 && a[curent.line][curent.column+1]==1)  ///est 2x
        return 6;
    if(curent.line<8 && apartinepatrat(p,pozx,pozy+114)&& bariera[2*(curent.line)+1][2*curent.column]==0 && bariera[2*(curent.line)+3][2*curent.column]==0&& a[curent.line+1][curent.column]==1)///sud 2x
        return 7;
    if(curent.column>2 && apartinepatrat(p,pozx-114,pozy)&& bariera[2*curent.line][2*curent.column-1]==0 && bariera[2*curent.line][2*curent.column-3]==0 && a[curent.line][curent.column-1]==1) ///vest 2x
        return 8;
    if(curent.line>1 && bariera[2*(curent.line-1)+1][2*curent.column]==0 && bariera[2*(curent.line-1)-1][2*curent.column]==1 && a[curent.line-1][curent.column]==1) ///nord bariera
    {
        if(apartinepatrat(p,pozx-57,pozy-57) && bariera[2*(curent.line-1)][2*curent.column-1]==0 )
            return 9; //diagonala stanga sus
        if(apartinepatrat(p,pozx+57,pozy-57) && bariera[2*(curent.line-1)][2*curent.column+1]==0)
            return 10; //diagonala dreapta sus
    }
    if(curent.column<9 && bariera[2*curent.line][2*curent.column+1]==0 && bariera[2*curent.line][2*curent.column+3]==1 && a[curent.line][curent.column+1]==1) ///est bariera
    {
        if(apartinepatrat(p,pozx+57,pozy-57) && bariera[2*curent.line-1][2*curent.column+2]==0)
            return 10; //diagonala dreapta sus
        if(apartinepatrat(p,pozx+57,pozy+57) && bariera[2*curent.line+1][2*curent.column+2]==0)
            return 11; //diagonala dreapta jos
    }
    if(curent.line<9 && bariera[2*(curent.line)+1][2*curent.column]==0 && bariera[2*(curent.line)+3][2*curent.column]==1 && a[curent.line+1][curent.column]==1) ///sud bariera
    {
        if(apartinepatrat(p,pozx+57,pozy+57) && bariera[2*(curent.line)+2][2*curent.column+1]==0)
            return 11; //diagonala dreapta jos
        if(apartinepatrat(p,pozx-57,pozy+57) && bariera[2*(curent.line)+2][2*curent.column-1]==0)
            return 12;  //diagonala stanga jos
    }
    if(curent.column>1 && bariera[2*curent.line][2*curent.column-1]==0 && bariera[2*curent.line][2*curent.column-3]==1 && a[curent.line][curent.column-1]==1) ///vest bariera
    {
        if(apartinepatrat(p,pozx-57,pozy-57) && bariera[2*curent.line-1][2*curent.column-2]==0)
            return 9;
        if(apartinepatrat(p,pozx-57,pozy+57) && bariera[2*curent.line+1][2*curent.column-2]==0)
            return 12;
    }
    return 0;
}
void positionplayer1(int line,int column) //deseneaza pozitia player-ului 1
{
    int pozx=249;
    pozx+=(column-1)*38+19*(column-1);
    int pozy=129;
    pozy+=(line-1)*38+19*(line-1);
    setcolor(BLACK);
    circle(pozx+19,pozy+19,14);
    setfillstyle(SOLID_FILL,RED);
    floodfill(pozx+20,pozy+20,BLACK);
}
void positionplayer2(int line, int column) //deseneaza pozitia player-ului 2
{
    int pozx=249;
    pozx+=(column-1)*38+19*(column-1);
    int pozy=129;
    pozy+=(line-1)*38+19*(line-1);
    setcolor(BLACK);
    circle(pozx+19,pozy+19,14);
    setfillstyle(SOLID_FILL,3);
    floodfill(pozx+20,pozy+20,BLACK);
}
void positioncalculator(int line, int column)  //deseaza pozitia cerculetului calculatorului
{
    int pozx=249;
    pozx+=(column-1)*38+19*(column-1);
    int pozy=129;
    pozy+=(line-1)*38+19*(line-1);
    setcolor(BLACK);
    circle(pozx+19,pozy+19,14);
    setfillstyle(SOLID_FILL,3);
    floodfill(pozx+20,pozy+20,BLACK);
}
void designmutare(player curent) //deseneaza mutarile posibile pentru jucatorul care muta
{
    if(curent.line>1&&bariera[2*(curent.line-1)+1][2*curent.column]==0&& a[curent.line-1][curent.column]!=1) ///nord
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line-2),249+57*(curent.column-1)+38,129+57*(curent.line-2)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line-2)+14,GREEN);
    }
    if(curent.column<9 && a[curent.line][curent.column+1]!=1 &&bariera[2*curent.line][2*curent.column+1]==0) ///est
    {
        setcolor(GREEN);
        rectangle(249+57*curent.column,129+57*(curent.line-1),249+57*(curent.column)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.line<9 && a[curent.line+1][curent.column]!=1&&bariera[2*(curent.line)+1][2*curent.column]==0)  ///sud
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line),249+57*(curent.column-1)+38,129+57*(curent.line)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line)+14,GREEN);
    }
    if(curent.column>1 && a[curent.line][curent.column-1]!=1&&bariera[2*curent.line][2*curent.column-1]==0) ///vest
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-2),129+57*(curent.line-1),249+57*(curent.column-2)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column-2)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.line>2 && bariera[2*(curent.line-1)+1][2*curent.column]==0 && bariera[2*(curent.line-1)-1][2*curent.column]==0 && a[curent.line-1][curent.column]==1) ///nord 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line-3),249+57*(curent.column-1)+38,129+57*(curent.line-3)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line-3)+14,GREEN);
    }
    if(curent.column<8 && a[curent.line][curent.column+1] == 1 && bariera[2*curent.line][2*curent.column+1]== 0 && bariera[2*curent.line][2*(curent.column)+3]==0) ///est 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column+1),129+57*(curent.line-1),249+57*(curent.column+1)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column+1)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.line<8 && a[curent.line+1][curent.column]==1 && bariera[2*(curent.line)+1][2*curent.column]==0 && bariera[2*(curent.line)+3][2*curent.column]==0)  ///sud 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line+1),249+57*(curent.column-1)+38,129+57*(curent.line+1)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line+1)+14,GREEN);
    }
    if(curent.column>2 && a[curent.line][curent.column-1]==1 && bariera[2*curent.line][2*curent.column-1]==0 && bariera[2*curent.line][2*curent.column-3]==0) ///vest 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-3),129+57*(curent.line-1),249+57*(curent.column-3)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(249+57*(curent.column-3)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.line>1 && bariera[2*(curent.line-1)+1][2*curent.column]==0 && bariera[2*(curent.line-1)-1][2*curent.column]==1 && a[curent.line-1][curent.column]==1)  /// nord bariera
    {
        if(bariera[2*(curent.line-1)][2*curent.column-1]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column-2),129+57*(curent.line-2),249+57*(curent.column-2)+38,129+57*(curent.line-2)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column-2)+14,129+57*(curent.line-2)+14,GREEN);
        }
        if(bariera[2*(curent.line-1)][2*curent.column+1]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column),129+57*(curent.line-2),249+57*(curent.column)+38,129+57*(curent.line-2)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column)+14,129+57*(curent.line-2)+14,GREEN);
        }
    }
    if(curent.column<9 && a[curent.line][curent.column+1] == 1 && bariera[2*curent.line][2*curent.column+1] == 0 && bariera[2*curent.line][2*curent.column+3]==1) ///est bariera
    {
        if(bariera[2*curent.line-1][2*curent.column+2]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column),129+57*(curent.line-2),249+57*(curent.column)+38,129+57*(curent.line-2)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column)+14,129+57*(curent.line-2)+14,GREEN);
        }
        if(bariera[2*curent.line+1][2*curent.column+2]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column),129+57*(curent.line),249+57*(curent.column)+38,129+57*(curent.line)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column)+14,129+57*(curent.line)+14,GREEN);
        }
    }
    if(curent.line<9 && a[curent.line+1][curent.column]==1 && bariera[2*(curent.line)+1][2*curent.column]==0 && bariera[2*(curent.line)+3][2*curent.column]==1)  ///sud bariera
    {
        if(bariera[2*(curent.line)+2][2*curent.column+1]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column),129+57*(curent.line),249+57*(curent.column)+38,129+57*(curent.line)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column)+14,129+57*(curent.line)+14,GREEN);
        }
        if(bariera[2*(curent.line)+2][2*curent.column-1]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column-2),129+57*(curent.line),249+57*(curent.column-2)+38,129+57*(curent.line)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column-2)+14,129+57*(curent.line)+14,GREEN);
        }
    }
    if(curent.column>1 && a[curent.line][curent.column-1]==1 && bariera[2*curent.line][2*curent.column-1]==0 && bariera[2*curent.line][2*curent.column-3]==1) ///vest 2x
    {
        if(bariera[2*curent.line-1][2*curent.column-2]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column-2),129+57*(curent.line-2),249+57*(curent.column-2)+38,129+57*(curent.line-2)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column-2)+14,129+57*(curent.line-2)+14,GREEN);
        }
        if(bariera[2*curent.line+1][2*curent.column-2]==0)
        {
            setcolor(GREEN);
            rectangle(249+57*(curent.column-2),129+57*(curent.line),249+57*(curent.column-2)+38,129+57*(curent.line)+38);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(249+57*(curent.column-2)+14,129+57*(curent.line)+14,GREEN);
        }
    }
}
void redesignmutare(player curent) //actualizeaza patratelele la starea initiala
{
    if(curent.line>1 && a[curent.line-1][curent.column]!=1) ///nord
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line-2),249+57*(curent.column-1)+38,129+57*(curent.line-2)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line-2)+14,GREEN);
    }
    if(curent.column<9 && a[curent.line][curent.column+1]!=1)  ///est
    {
        setcolor(GREEN);
        rectangle(249+57*curent.column,129+57*(curent.line-1),249+57*(curent.column)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.line<9 && a[curent.line+1][curent.column]!=1) ///sud
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line),249+57*(curent.column-1)+38,129+57*(curent.line)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line)+14,GREEN);
    }
    if(curent.column>1 && a[curent.line][curent.column-1]!=1) ///vest
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-2),129+57*(curent.line-1),249+57*(curent.column-2)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-2)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.line>2 && a[curent.line-2][curent.column]==0) ///nord 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line-3),249+57*(curent.column-1)+38,129+57*(curent.line-3)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line-3)+14,GREEN);
    }
    if(curent.column<8 && a[curent.line][curent.column+2]!=1)  ///est 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column+1),129+57*(curent.line-1),249+57*(curent.column+1)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column+1)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.line<8 && a[curent.line+2][curent.column]!=1) ///sud 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-1),129+57*(curent.line+1),249+57*(curent.column-1)+38,129+57*(curent.line+1)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-1)+14,129+57*(curent.line+1)+14,GREEN);
    }
    if(curent.column>2 && a[curent.line][curent.column-2]!=1) ///vest 2x
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-3),129+57*(curent.line-1),249+57*(curent.column-3)+38,129+57*(curent.line-1)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-3)+14,129+57*(curent.line-1)+14,GREEN);
    }
    if(curent.column>1 and curent.line>1 && a[curent.line-1][curent.column-1]!=1) ///nord vest-stanga sus
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-2),129+57*(curent.line-2),249+57*(curent.column-2)+38,129+57*(curent.line-2)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-2)+14,129+57*(curent.line-2)+14,GREEN);
    }
    if(curent.column<9 and curent.line>1 && a[curent.line-1][curent.column+1]!=1) ///nord est-dreapta sus
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column),129+57*(curent.line-2),249+57*(curent.column)+38,129+57*(curent.line-2)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column)+14,129+57*(curent.line-2)+14,GREEN);
    }
    if(curent.line<9 and curent.column<9 && a[curent.line+1][curent.column+1]!=1) ///sud est-dreapta jos
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column),129+57*(curent.line),249+57*(curent.column)+38,129+57*(curent.line)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column)+14,129+57*(curent.line)+14,GREEN);
    }
    if(curent.line<9 && curent.column>1 && a[curent.line+1][curent.column-1]!=1) ///sud vest-stanga jos
    {
        setcolor(GREEN);
        rectangle(249+57*(curent.column-2),129+57*(curent.line),249+57*(curent.column-2)+38,129+57*(curent.line)+38);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(249+57*(curent.column-2)+14,129+57*(curent.line)+14,GREEN);
    }
}
void designbariera(int x, int y) //reda o posibila bariera care poate fi plasata
{
     if((x>249 && x<749) && (y>129  && y<621))
       {
    int pozx,pozy;
    pozx=( x-230)/57+1;
    pozy=( y-110)/57+1;
    if((x<pozx*57+230&&x>230+pozx*57-57+19)&&(y>pozy*57-57+110&&y<pozy*57+110-57+19)) ///bariera orizontala
    {
        if(bariera[2*pozy-1][2*pozx]==0&&bariera[2*pozy-1][2*pozx+1]==0&&bariera[2*pozy-1][2*pozx+2]==0)///verific daca nu se suprapune cu o alta bariera
        {
            bariera[2*pozy-1][2*pozx]=bariera[2*pozy-1][2*pozx+1]=bariera[2*pozy-1][2*pozx+2]=1;
            if(Blocheaza()==0)
            {
                setcolor(YELLOW);
                rectangle(230+pozx*57-57+19,110+57*pozy-57+1,230+pozx*57+38+19,110+57*pozy-57+19-1);
            }
            bariera[2*pozy-1][2*pozx]=bariera[2*pozy-1][2*pozx+1]=bariera[2*pozy-1][2*pozx+2]=0;
        }
    }
    else ///bara verticala
    {
        if((x>230+pozx*57-57&&x<230+pozx*57-57+19)&&(y>pozy*57+110-57+19&&y<pozy*57+110))
            if(bariera[2*pozy][2*pozx-1]==0&&bariera[2*pozy+1][2*pozx-1]==0&&bariera[2*pozy+2][2*pozx-1]==0)
            {
                bariera[2*pozy][2*pozx-1]=bariera[2*pozy+1][2*pozx-1]=bariera[2*pozy+2][2*pozx-1]=1;
                if(Blocheaza()==0)
                {
                    setcolor(YELLOW);
                    rectangle(230+pozx*57-57,pozy*57+110-57+19,230+pozx*57-57+19,pozy*57+110+57);
                }
                bariera[2*pozy][2*pozx-1]=bariera[2*pozy+1][2*pozx-1]=bariera[2*pozy+2][2*pozx-1]=0;
            }
    }
       }
}
void redesignbariera(int x,int y) //sterge posibila bariera
{
    if((x>249 && x<749) && (y>129  && y<621))
       {
    int pozx=( x-230)/57+1;
    int pozy=( y-110)/57+1;
    if((x<pozx*57+230&&x>230+pozx*57-57+19)&&(y>pozy*57-57+110&&y<pozy*57+110-57+19)) ///bariera orizontala
    {
        if(bariera[2*pozy-1][2*pozx]==0&&bariera[2*pozy-1][2*pozx+1]==0&&bariera[2*pozy-1][2*pozx+2]==0)///verific daca nu se suprapune cu o alta bariera
        {
            if(Blocheaza()==0)
            {
                setcolor(BLUE);
                rectangle(230+pozx*57-57+19,110+57*pozy-57+1,230+pozx*57+38+19,110+57*pozy-57+19-1);
            }
        }
    }
    else ///bara verticala
    {
        if((x>230+pozx*57-57&&x<230+pozx*57-57+19)&&(y>pozy*57+110-57+19&&y<pozy*57+110))
            if(bariera[2*pozy][2*pozx-1]==0&&bariera[2*pozy+1][2*pozx-1]==0&&bariera[2*pozy+2][2*pozx-1]==0)
            {
                if(Blocheaza()==0)
                {
                    setcolor(BLUE);
                    rectangle(230+pozx*57-57,pozy*57+110-57+19,230+pozx*57-57+19,pozy*57+110+57);
                }
            }
    }
    }

}

void Traseu(int elem[20][20],int i, int j) // reconstituirea traseului minim dupa aplicarea alg lui Lee
{
    if(elem[i][j]!=1)
    {
        int p = -1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(elem[i][j] == elem[i+2*dy[k]][j+2*dx[k]]+1&&bariera[i+dy[k]][j+dx[k]]==0)
                p = k;

        Traseu(elem,i+2*dy[p],j+2*dx[p]);
        if(verif==0)
        {
            verif=1;
            if(p==0)
            {
                mCalc=2;
            }
            else if(p==1)
                mCalc=3;
            else if(p==2)
                mCalc=0;
            else if(p==3)
                mCalc=1;
        }
    }
}
void PuneBariera(int  i,int j,int A[20][20])
{

    int xe=0,ye=0;
    if(A[i][j]!=1)
    {
        int p=-1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(A[i][j] == A[i+2*dy[k]][j+2*dx[k]]+1)
                p = k;
        PuneBariera(i + 2*dy[p], j + 2*dx[p],A);
        if(ok==0)
        {
            if(p==0)
            {
                xe=j/2*57+230-10;
                ye=i/2*57+110+8;
                if(plasareBariera(xe,ye)==1)
                    ok=1;
                else
                {
                    xe=(j-1)/2*57+230-5;
                    ye=i*57/2+110+8;
                    if(plasareBariera(xe,ye)==1)
                        ok=1;
                }
            }
            else if(p==1)
            {
                xe=j/2*57+230+12;
                ye=i*57/2+110-19;
                if(plasareBariera(xe,ye)==1)
                    ok=1;
                else
                {
                    xe=j/2*57+230+12;
                    ye=(i-1)/2*57+110-19;
                    if(plasareBariera(xe,ye)==1)
                        ok=1;
                }
            }
            else if(p==2)
            {
                xe=j/2*57+230-10;
                ye=i/2*57+110+10;
                if(plasareBariera(xe,ye)==1)
                    ok=1;
                else
                {
                    xe=(j-1)/2*57+230-10;
                    ye=i*57/2+110+10;
                    if(plasareBariera(xe,ye)==1)
                        ok=1;
                }
            }
            else if(p==3)
            {
                xe=(j-1)/2*57+230+12;
                ye=i/2*57+110-10;
                if(plasareBariera(xe,ye)==1)
                    ok=1;
                else
                {
                    xe=(j-1)/2*57+230+12;
                    ye=(i-1)/2*57+110+30;
                    if(plasareBariera(xe,ye)==1)
                        ok=1;
                }
            }
        }
    }
}
#endif // FUNCTIONSFORPLAY_H_INCLUDED
