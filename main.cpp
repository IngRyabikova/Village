#include "TXLib.h"
#include "button.cpp"

#include "mapoject.cpp"

int main()
{
    txCreateWindow(1000,800);


        txSleep(1000);

  MapObject a[4];


    a[0] =  { 810,   0, 930, 200, txLoadImage ("Album/House/house1.bmp"), ""};

    a[1] = { 810, 300, 930, 500, txLoadImage ("Album/House/house2.bmp"), ""};

    a[2] =  { 810, 600, 930, 800, txLoadImage ("Album/House/house3.bmp"), ""};

    a[3] =  { 810, 200, 930, 300, txLoadImage ("Album/House/House4.bmp"), ""};



    Button b[7];
    b[0] = {0,0, "ƒŒÃ"};
    b[1] = {100,0, "—Œ¡¿ ¿"};
    b[2] = {200,0, "œ≈“”’"};
    b[3] = {300,0, "’–ﬁÿ ¿"};
    b[4] = {400,0, "ƒﬂƒﬂ\nœ≈“ﬂ"};
    b[5] = {500,0, "—“¿—"};
    b[6] = {600,0, "Ã¿–»Õ¿"};

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txRectangle(txGetExtentX() - 200, 0, txGetExtentX(), txGetExtentY());


        for (int nomer_kartinki = 0; nomer_kartinki <= 3 ; nomer_kartinki ++)
        {
            a[nomer_kartinki].drawMapObject();
        }

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


    txDeleteDC(a[0].picture);
    txDeleteDC(a[1].picture);
    txDeleteDC(a[2].picture);

    return 0;
}
