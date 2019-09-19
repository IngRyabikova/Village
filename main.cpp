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
       drawButton(0,0, "ƒŒÃ");
       drawButton(100,0, "—Œ¡¿ ¿");
       drawButton(200,0, " Œ«¿");
       drawButton(300,0, "—ŒÀÕ÷≈");
       drawButton(400,0, "Œ¡À¿ ¿");
       drawButton(500,0, "ƒﬂƒﬂ\nœ≈“ﬂ");
                      */

    }

