#include "TXLib.h"

int KOLICH_KNOPOK = 7;

struct Button
{
    int x;
    int y;
    const char* text;
    HDC f_button;

    void drawButton()
    {
        txSetColor(TX_WHITE);
        Win32 :: TransparentBlt(txDC(),x,y, (txGetExtentX() - 300) / KOLICH_KNOPOK, 70, f_button, 0, 0 , 300, 168, TX_WHITE);
        txSelectFont("Comic Sans MS", 25);
        txSetColor(TX_WHITE);
        txDrawText(x,y, x + (txGetExtentX() - 300) / KOLICH_KNOPOK, y + 70, text) ;
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


