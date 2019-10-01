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
        txSetColor(TX_BLACK, 3);
        txSelectFont("Comic Sans MS", 25);
        txDrawText(x,y, x + (txGetExtentX() - 300) / KOLICH_KNOPOK, y + 70, text) ;
    }

    bool Click()
    {
        if (txMouseButtons() == 1 &&
                txMouseX() > x &&   //������ ���� �����
                txMouseX() < x + 100 &&   //������ ���� �����
                txMouseY() > y    &&   //������ ���� ����
                txMouseY() < y + 70)         //������ ���� 70
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};


