#ifndef BUTTONS_H_INCLUDED
#define BUTTONS_H_INCLUDED
#include "variables.h"
using namespace std;
void mesajButon(int x,int y,char a[],int color)
{
    settextstyle(8,0,5);
    setcolor(color);
    outtextxy(x,y,a);
}
void buton1Vs1(int color,int colormess) //afisare buton 1v1
{
    b[1].D.sS= {300,200};
    b[1].D.dJ= {700,300};
    setcolor(color);
    rectangle(300,200,700,300);
    mesajButon(420,230,"1 VS 1",colormess);
}
void butonVsComp(int color, int colormess) //afisare buton vscomputer
{
    b[2].D.sS= {300,375};
    b[2].D.dJ= {700,475};
    setcolor(color);
    rectangle(300,375,700,475);
    mesajButon(350,405,"vs Computer",colormess);
}
void afisareTitlu() //afisare titlu
{
    setcolor(15);
    settextstyle(10,0,8);
    outtextxy(300,50,"Quoridor");
}
void butonReguli(int color, int colormess) // buton Regulament
{
    b[3].D.sS= {300,550};
    b[3].D.dJ= {700,650};
    setcolor(color);
    rectangle(300,550,700,650);
    mesajButon(380,580,"Regulament",colormess);
}
void butonIesire(int color, int colormess) // buton Iesire
{
    b[4].D.sS= {1,220};
    b[4].D.dJ= {71,380};
    setcolor(color);
    rectangle(1,220,71,380);
    setcolor(colormess);
    settextstyle(8,1,3);
    outtextxy(20,340,"Iesire");
}
void butonInapoi(int color, int colormess) // buton Acasa
{
    b[5].D.sS= {928,220};
    b[5].D.dJ= {998,380};
    setcolor(color);
    rectangle(928,220,998,380);
    setcolor(colormess);
    settextstyle(8,1,3);
    outtextxy(948,340,"Acasa");
}
void butonPlayAgain(int color,int colormess) // buton play again
{
    b[6].D.sS= {400,360};
    b[6].D.dJ= {600,440};
    setcolor(color);
    rectangle(400,360,600,440);
    setcolor(colormess);
    settextstyle(8,4,5);
    outtextxy(411,379,"Joc nou");
}
void creeareMeniu()  //creeaza meniul principal cu butoane
{
    afisareTitlu();
    buton1Vs1(12,15); ///buton1
    butonVsComp(11,15);///buton2
    butonReguli(1,15);///buton3
    butonIesire(2,15);///buton 4
}
void writeRules(int i) // scrie regulile jocului pe randuri diferite
{
    setcolor(15);
    settextstyle(10,0,8);
    outtextxy(300,50-i,"Quoridor");
    setcolor(13);
    settextstyle(8,0,3);
    outtextxy(130,150-i, "Prezentare");
    outtextxy(130,170-i, "- o tabla de joc;");
    outtextxy(130,190-i, "- 2 zone de stocaj;");
    outtextxy(130,210-i, "- 20 de bariere si 2 pioni.");
    outtextxy(130,230-i, "Scopul jocului");
    outtextxy(100,250-i, "De a ajunge primul pe linia opusa liniei de plecare");
    outtextxy(130,270-i, "Reguli pentru 2 jucatori:");
    outtextxy(100,290-i, "La inceputul jocului, barierele sunt asezate in zonele");
    outtextxy(100,310-i, "de stocaj (cate 10 pentru fiecare jucator).");
    outtextxy(100,330-i, "Fiecare jucator isi aseaza pionul in centrul liniei");
    outtextxy(100,350-i, "de plecare.Jucatorul care incepe, este player 1");
    outtextxy(130,370-i, "Derularea unei partide");
    outtextxy(100,390-i, "Pe rand, fiecare jucator alege intre a-si misca");
    outtextxy(100,410-i, "pionul sau a-si aseza una dintre bariere. Daca un");
    outtextxy(100,430-i, "jucator isi termina barierele este obligat sa-si");
    outtextxy(100,450-i, "deplaseze pionul.");
    outtextxy(130,470-i, "Deplasarea pionilor");
    outtextxy(100,490-i, "Pionii se deplaseaza orizontal, vertical, inainte sau");
    outtextxy(100,510-i, "inapoi cu o casuta, dar barierele trebuiesc ocolite.");
    outtextxy(130,530-i, "Asezarea barierelor");
    outtextxy(100,550-i, "O bariera trebuie asezata exact intre doua casute.");
    outtextxy(100,570-i, "Asezarea barierei are ca scop crearea propriului drum");
    outtextxy(100,590-i, "sau de a incetini avansarea adversarului, dar este");
    outtextxy(100,610-i, "interzis de a-i bloca toate caile de acces la linia");
    outtextxy(100,630-i, "de sosire;trebuie lasata intotdeauna o cale de iesire");
    outtextxy(130,650-i, "Fata in fata");
    outtextxy(100,670-i, "Cand doi pioni se afla fata in fata pe doua casute");
    outtextxy(100,690-i, "alaturate, neseparate de o bariera,jucatorul care");
    outtextxy(100,710-i, "trebuie sa mute,poate sari peste pionul adversarului,");
    outtextxy(100,730-i, "asezandu-se in spatele acestuia. Daca, in spatele");
    outtextxy(100,750-i, "pionului care trebuie sarit, se afla o bariera,");
    outtextxy(100,770-i, "jucatorul poate alege casuta din stanga sau dreapta");
    outtextxy(100,790-i, "acestui pion.");
    outtextxy(130,810-i, "Incheierea partidei");
    outtextxy(100,830-i, "Primul jucator care ajunge cu pionul intr-una dintre");
    outtextxy(100,850-i, "cele 9 casute de pe linia de sosire (opusa celei de");
    outtextxy(100,870-i, "plecare), castiga partida.");
    outtextxy(130,890-i, "Durata unei partide:");
    outtextxy(100,910-i, "Fiecare jucator va avea un timp de 500 sec, iar daca");
    outtextxy(100,930-i, "va expira timpul, jucatorul respectiv pierde.");
}
bool apartine(punct P, dreptunghi D)  // daca mouse-ul apartine de un anumit rectangle de coordonate fixe
{
    return D.sS.x<=P.x && P.x<=D.dJ.x && D.sS.y<=P.y && P.y<=D.dJ.y;
}
int butonAles() // reda butonul ales in momentul click-ului
{
    int i;
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        for (i=1; i<=6; i++)
            if (apartine(p,b[i].D))
            {
                if(i==2 && game!=0)
                {}
                else
                return i;
            }

    }
    return 0;
}
void createtable(int k) // creare tabla de joc
{
    setcolor(GREEN);
    rectangle(230,110,760,640);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(250,256,GREEN);
    for(int i=249; i<760; i=i+57)
    {
        for(int j=129; j<640; j=j+57)
        {
            setcolor(GREEN);
            rectangle(i,j,i+38,j+38);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(i+15,j+15,GREEN);
        }
    }
    settextstyle(3,0,1);
    setcolor(WHITE);
    if(k==1) //1v1
    {
        outtextxy(230,80,"Numar bariere jucator 2=");
        outtextxy(50,180,"Muta jucatorul: ");
        outtextxy(410,80, mesaj[nrb2]);
        outtextxy(580,650,"Numar bariere jucator 1=");
        outtextxy(758,650, mesaj[nrb1]);
        outtextxy(780,92,"Timp de joc player 2");
        outtextxy(780,570,"Timp de joc player 1");
    }
    else //playervscalculator
    {
        outtextxy(230,80,"Numar bariere calculator=");
        outtextxy(50,180,"Mult succes! ");
        outtextxy(410,80, mesaj[nrb2]);
        outtextxy(580,650,"Numar bariere jucator=");
        outtextxy(758,650, mesaj[nrb1]);
        outtextxy(785,570,"Timp de joc player");
    }
}
#endif // BUTTONS_H_INCLUDED
