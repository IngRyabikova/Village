#include "TXLib.h"
#include "button.cpp"

#include "mapoject.cpp"

int main()
{
    txCreateWindow(1000,800);

    MapObject a = { 0,   10, 530, 150, txLoadImage ("Album/House/house1.bmp"), ""};
    a.drawMapObject();

    MapObject b1 = { 0,   210, 530, 650, txLoadImage ("Album/House/house2.bmp"), ""};
    b1.drawMapObject();

    MapObject c = { 0,   450, 530, 800, txLoadImage ("Album/House/house3.bmp"), ""};
    c.drawMapObject();

    txDeleteDC(a.picture);
    txDeleteDC(b1.picture);
    txDeleteDC(c.picture);
        txSleep(1000);

    Button b[7];
    b[0] = {0,0, "ƒŒÃ"};
    b[1] = {100,0, "—Œ¡¿ ¿"};
    b[2] = {200,0, "œ≈“”’"};
    b[3] = {300,0, "’–ﬁÿ ¿"};
    b[4] = {400,0, "ƒﬂƒﬂ\nœ≈“ﬂ"};
    b[5] = {500,0, "—“¿—"};
    b[6] = {600,0, "Ã¿–»Õ¿"};

    while(true)
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();

        for (int nomer = 0; nomer < 7; nomer++)
        {
            b[nomer].drawButton();
            if (b[nomer].Click ())
            {
                txTextOut(100, 500, "dsfsdf");
            }
        }


        txSleep(10);
        txEnd();
    }


    return 0;
}
