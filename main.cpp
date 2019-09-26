#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int main()
{
    txCreateWindow(1000,800);

    MapObject a =  { 810,   0, 930, 200, txLoadImage ("Album/House/house1.bmp"), ""};
    a.drawMapObject();

    MapObject b1 = { 100 ,100, 600, 600, txLoadImage ("Album/House/house2.bmp"), ""};
    b1.drawMapObject();

    MapObject c =  { 810, 600, 930, 800, txLoadImage ("Album/House/house3.bmp"), ""};
    c.drawMapObject();

    MapObject d =  { 600, 550, 900,700, txLoadImage ("Album/Animals/DoG.bmp"), ""};
    d.drawMapObject();

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

        txRectangle(txGetExtentX() - 200, 0, txGetExtentX(), txGetExtentY());
        a.drawMapObject();
        b1.drawMapObject();
        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, " ŒÕ—“–” “Œ– ƒ≈–≈¬Õ»");


        d.drawMapObject();
        for (int nomer = 0; nomer < 7; nomer++)
        {
            b[nomer].drawButton();
            if (b[nomer].Click ())
            {
                txTextOut(100, 500, "dsfsdf");
                c.drawMapObject();
            }

        }
        txSelectFont("Comic Sans MS", 50);
        txTextOut(700,900, " ŒÕ—“–” “Œ– ƒ≈–≈¬Õ»");
        txSleep(10);
        txEnd();
    }


    txDeleteDC(a.picture);
    txDeleteDC(b1.picture);
    txDeleteDC(c.picture);
    txDeleteDC(d.picture);
    return 0;
}
