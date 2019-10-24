#include "TXLib.h"

struct MapObject
{
    int x;
    int y;
    int x2;
    int y2;
    HDC picture;
    const char* text;
    int width;
    int hight;
    bool visible;
    const char* category;
    bool clicked;

    void drawMapObject(int current_x)
    {
        if (visible)
        {
            Win32::TransparentBlt(txDC(), x + current_x,  y, x2 - x, y2 - y, picture, 0, 0, width, hight, TX_WHITE);
            txDrawText(      x,  y, x2, y2, text);
        }
    }

    bool Click()
    {
        if (txMouseButtons() == 1 &&
                txMouseX() > x &&   //äîëæíà áûòü ñîòêà
                txMouseX() < x2 &&   //äîëæíà áûòü ñîòêà
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

