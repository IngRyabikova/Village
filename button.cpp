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


