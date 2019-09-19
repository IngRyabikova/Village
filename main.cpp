#include "TXLib.h"

struct house
{
 int x;
 int y;
 int x2;
 int y2;
 const char* text;
 HDC baton;
 HDC  izba;
 };


void drawButton(house b)
{
    txBitBlt(txDC(), b.x,  b.y, b.x2 - b.x, b.y2 - b.y, b.baton);
    txDrawText(      b.x,  b.y,b.x2,b.y2,b.text);
}

int main()
{
    txCreateWindow(1000,800);

    HDC  baton = txLoadImage ("house1.bmp");
    HDC  izba  = txLoadImage ("house2.bmp");
    HDC  dacha = txLoadImage ("house3.bmp");
    house b = { 0,   210, 530, 650, "", baton};
    drawButton(b);

    house a = { 0,   10, 530, 150, "", izba};
    drawButton(a);

    house c = { 0,   450, 530, 800, "", dacha};
    drawButton(c);

        txDeleteDC(baton);

      /*
       drawButton(0,0, "ÄÎÌ");
       drawButton(100,0, "ÑÎÁÀÊÀ");
       drawButton(200,0, "ÊÎÇÀ");
       drawButton(300,0, "ÑÎËÍÖÅ");
       drawButton(400,0, "ÎÁËÀÊÀ");
       drawButton(500,0, "ÄßÄß\nÏÅÒß");
                      */

 
    HDC pic = txLoadImage("C:\\Users\\user\\Pictures\\house5.bmp");
    txSetColor(TX_BLACK);

    while(true)
    {
        txClear();
        txBitBlt(txDC(), 0,0,1700,1600,pic);
        txRectangle(50,50,100,200);

        if (txMouseButtons() == 1 &&
            txMouseX() >  50 &&
            txMouseX() < 100 &&
            txMouseY() <  200)
        {
            txTextOut(100, 500, "dsfsdf");
        }
        if (txMouseX() >  50 &&
            txMouseX() < 100 &&
            txMouseY() <  200)
        {
            txTextOut(100, 500, "âàðâàð");
        }

        txSleep(10);
    }
    txDeleteDC(pic);


    return 0;
}