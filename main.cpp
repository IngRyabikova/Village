#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int main()
{
    txCreateWindow(1000,800);


    MapObject b1 = { 100 ,100, 600, 600, txLoadImage ("Album/House/house2.bmp"), ""};
    b1.drawMapObject();
  MapObject a[4];


    a[0] =  { 810,   0, 930, 200, txLoadImage ("Album/House/house1.bmp"), ""};
    a[1] = { 810, 300, 930, 500, txLoadImage ("Album/House/house2.bmp"), ""};
    a[2] =  { 810, 600, 930, 800, txLoadImage ("Album/House/house3.bmp"), ""};
    a[3] =  { 810, 200, 930, 300, txLoadImage ("Album/House/House4.bmp"), ""};

  MapObject d =  { 600, 550, 900,700, txLoadImage ("Album/Animals/DoG.bmp"), ""};
    d.drawMapObject();

    Button b[7];
    b[0] = {0,0, "ÄÎÌ"};
    b[1] = {100,0, "ÑÎÁÀÊÀ"};
    b[2] = {200,0, "ÏÅÒÓÕ"};
    b[3] = {300,0, "ÕÐÞØÊÀ"};
    b[4] = {400,0, "ÄßÄß\nÏÅÒß"};
    b[5] = {500,0, "ÑÒÀÑ"};
    b[6] = {600,0, "ÌÀÐÈÍÀ"};

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txRectangle(txGetExtentX() - 200, 0, txGetExtentX(), txGetExtentY());

        b1.drawMapObject();
        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, "ÊÎÍÑÒÐÓÊÒÎÐ ÄÅÐÅÂÍÈ");


        for (int nomer_kartinki = 0; nomer_kartinki <= 3 ; nomer_kartinki ++)
        {
            a[nomer_kartinki].drawMapObject();
        }


        d.drawMapObject();
        for (int nomer = 0; nomer < 7; nomer++)
        {
            b[nomer].drawButton();
            if (b[nomer].Click ())
            {
                txTextOut(100, 500, "dsfsdf");
                c.drawMapObject();
            }

        }
        txSelectFont("Comic Sans MS", 50);
        txTextOut(700,900, "ÊÎÍÑÒÐÓÊÒÎÐ ÄÅÐÅÂÍÈ");
        txSleep(10);
        txEnd();
    }


    txDeleteDC(a.picture);
    txDeleteDC(b1.picture);
    txDeleteDC(c.picture);
    txDeleteDC(d.picture);
    txDeleteDC(a[0].picture);
    txDeleteDC(a[1].picture);
    txDeleteDC(a[2].picture);

    return 0;
}