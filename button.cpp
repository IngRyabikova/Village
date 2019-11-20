#include "TXLib.h"

int KOLICH_KNOPOK = 7;

struct Button
{
    int x;
    int y;
    const char* text;
    char* category;
    bool visible;
    int countPics;

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

void drawButtons (Button buttons[], int count)
{
    for (int nomer_knopki = 0; nomer_knopki < count; nomer_knopki++)
    {
        buttons[nomer_knopki].drawButton();
    }
}
