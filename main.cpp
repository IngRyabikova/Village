#include "TXLib.h"

struct MapObject
{
    int x;
    int y;
    int x2;
    int y2;
    HDC picture;
    const char* text;
};


void drawMapObject(MapObject b)
{
    txBitBlt(txDC(), b.x,  b.y, b.x2 - b.x, b.y2 - b.y, b.picture);
    txDrawText(      b.x,  b.y, b.x2, b.y2, b.text);
}

void drawButton(int x, int y, const char* text)
{
    txSetColor(TX_BLACK);
    txSetFillColor(TX_MAGENTA);
    txRectangle(x,y, x + 100, y + 70);
    txSelectFont("Comic Sans MS", 30);
    txDrawText(x,y, x +100, y +70, text) ;
}

int main()
{
    txCreateWindow(1000,800);

    MapObject a = { 0,   10, 530, 150, txLoadImage ("Album/House/house1.bmp"), ""};
    drawMapObject(a);

    MapObject b = { 0,   210, 530, 650, txLoadImage ("Album/House/house2.bmp"), ""};
    drawMapObject(b);

    MapObject c = { 0,   450, 530, 800, txLoadImage ("Album/House/house3.bmp"), ""};
    drawMapObject(c);

    txDeleteDC(a.picture);
    txDeleteDC(b.picture);
    txDeleteDC(c.picture);
        txSleep(1000);


    while(true)
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();

        drawButton(0,0, "���");
        drawButton(100,0, "������");
        drawButton(200,0, "����");
        drawButton(300,0, "������");
        drawButton(400,0, "������");
        drawButton(500,0, "����\n����");

        //click on 2 button
        if (txMouseButtons() == 1 &&
            txMouseX() > 100 &&
            txMouseX() < 200 &&
            txMouseY() >   0 &&
            txMouseY() <  70)
        {
            txTextOut(100, 500, "dsfsdf");
        }

        //focus on 2 button
        if (txMouseX() > 100 &&
            txMouseX() < 200 &&
            txMouseY() >   0 &&
            txMouseY() <  70)
        {
            txTextOut(100, 500, "lkhlh");
        }

        txSleep(10);
        txEnd();
    }


    return 0;
}
