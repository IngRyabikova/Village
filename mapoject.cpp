#include "TXLib.h"

struct MapObject
{
    string adress;
    int x;
    int y;
    int x2;
    int y2;
    string category;
    HDC picture;
    int width;
    int hight;
    const char* text;
    bool visible;
    bool clicked;

    void drawMapObject(int current_x)
    {
        if (visible)
        {
            Win32::TransparentBlt(txDC(), x + current_x,  y, x2 - x, y2 - y, picture, 0, 0, width, hight, TX_WHITE);
            txDrawText(      x,  y, x2, y2, text);
        }
    }

    bool Click(int current_x)
    {
        if (txMouseButtons() == 1 &&
                txMouseX() > x + current_x &&   //äîëæíà áûòü ñîòêà
                txMouseX() < x2 + current_x &&   //äîëæíà áûòü ñîòêà
                txMouseY() > y    &&   //äîëæåí áûòü íîëü
                txMouseY() < y2 )         //äîëæíî áûòü 70
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

