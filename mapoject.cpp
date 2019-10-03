#include "TXLib.h"

struct MapObject
{
    int x;
    int y;
    int x2;
    int y2;
    HDC picture;
    const char* text;
    bool visible;

    void drawMapObject()
    {
        if (visible)
        {
            txBitBlt(txDC(), x,  y, x2 - x, y2 - y, picture);
            txDrawText(      x,  y, x2, y2, text);
        }
    }

};

struct MapObject2
{
    int x;
    int y;
    int x2;
    int y2;
    HDC picture;
    const char* text;

    void drawMapObject()
    {
        txBitBlt(txDC(), x,  y, x2 - x, y2 - y, picture);
        txDrawText(      x,  y, x2, y2, text);
    }
};
