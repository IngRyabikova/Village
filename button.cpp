#include "TXLib.h"

struct Button
{
    int x;
    int y;
    const char* text;

    void drawButton()
    {
        txSetColor(TX_BLACK);
        txSetFillColor(TX_YELLOW);
        txRectangle(x,y, x + 100, y + 70);
        txSelectFont("Comic Sans MS", 30);
        txDrawText(x,y, x +100, y +70, text) ;
    }

    bool Click()
    {
        if (txMouseButtons() == 1 &&
                txMouseX() > x &&   //должна быть сотка
                txMouseX() < x + 100 &&   //должна быть сотка
                txMouseY() > y    &&   //должен быть ноль
                txMouseY() < y + 70)         //должно быть 70
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};


