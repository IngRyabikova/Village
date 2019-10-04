#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int main()
{
    txCreateWindow(1200,800);

    HDC background = txLoadImage("Album/background.bmp");

    MapObject houseVariants[4];
    houseVariants[0] = { 1030,   0, 1130, 150, txLoadImage ("Album/House/house1.bmp"), "", 500, 366};
    houseVariants[1] = { 1010, 200, 1180, 350, txLoadImage ("Album/House/house2.bmp"), "", 799, 491};
    houseVariants[2] = { 1010, 400, 1200, 600, txLoadImage ("Album/House/house3.bmp"), "", 800, 518};
    houseVariants[3] = { 1010, 600, 1150, 800, txLoadImage ("Album/House/House4.bmp"), "", 500, 561};
  
    MapObject animals[3];
    animals[0] = { 1010,   0, 1170, 120, txLoadImage ("Album/Animals/DoG.bmp"), "",160 , 120};
    animals[1] = { 1010, 200, 1130, 400, txLoadImage ("Album/Animals/DoG.bmp"), "",160 , 120};
    animals[2] = { 1010, 400, 1130, 600, txLoadImage ("Album/Animals/DoG.bmp"), "",160 , 120};
    animals[3] = { 1010, 600, 1130, 800, txLoadImage ("Album/Animals/DoG.bmp"), "",160 , 120};

    MapObject b1 = { 100, 100, 800, 700, txLoadImage ("Album/House/house2.bmp"), "",  799 ,491};
    MapObject d =  { 600, 550, 900, 700, txLoadImage ("Album/Animals/DoG.bmp"), "",   160 ,120};
    MapObject F =  { 400, 600, 550, 700, txLoadImage ("Album/Animals/PetuX.bmp"), "", 50  ,67};
    MapObject G =  { 200, 600, 300, 700, txLoadImage ("Album/Animals/piG.bmp"), "",   119 ,95};



    bool visible = false;
    bool visible2 = false;
    bool visible3 = false;

    Button buttons[7];
    buttons[0] = {  0,0, "ÄÎÌ", txLoadImage("Album/button/fon_b.bmp")};
    buttons[1] = {120,0, "ÑÎÁÀÊÀ", txLoadImage("Album/button/fon_b.bmp")};
    buttons[2] = {240,0, "ÏÅÒÓÕ", txLoadImage("Album/button/fon_b.bmp")};
    buttons[3] = {360,0, "ÕÐÞØÊÀ", txLoadImage("Album/button/fon_b.bmp")};
    buttons[4] = {480,0, "ÄßÄß\nÏÅÒß", txLoadImage("Album/button/fon_b.bmp")};
    buttons[5] = {600,0, "ÑÒÀÑ", txLoadImage("Album/button/fon_b.bmp")};
    buttons[6] = {720,0, "ÌÀÐÈÍÀ", txLoadImage("Album/button/fon_b.bmp")};

    bool vid = false;
    bool vid2 = false;

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background);

        txSetFillColor(TX_TRANSPARENT);

        txRectangle(txGetExtentX() - 300, 0, txGetExtentX(), txGetExtentY());

        b1.drawMapObject();
        d.drawMapObject();
        for (int nomer_kartinki = 0; nomer_kartinki <= 3 ; nomer_kartinki ++)
        {
            if (vid)
            {
                houseVariants[nomer_kartinki].drawMapObject();
            }
            if (vid2)
            {
                animals[nomer_kartinki].drawMapObject();
            }
        }

        for (int nomer_knopki = 0; nomer_knopki < 7; nomer_knopki++)
        {
            buttons[nomer_knopki].drawButton();
            if (buttons[nomer_knopki].Click ())
            {   txSetColor(TX_BLACK);
                txTextOut(100, 500, "Âû íàæàëè íà êíîïêó");
            }
        }

            if (buttons[0].Click ())
            {
                vid = !vid;
                txSleep(200);
            }
             if (buttons[4].Click())
             {
              vid2 = !vid2;
              txSleep(200);
            }

      if (buttons[1].Click ())
        {
            visible = true;
        }
        if (buttons[2].Click ())
        {
            visible2 = true;
        }
        if (buttons[3].Click ())
        {
            visible3 = true;
        }


        b1.drawMapObject();

        if (visible)
        {
           d.drawMapObject();
        }
        if (visible2)
        {
           F.drawMapObject();

        }
        if (visible3)
        {
           G.drawMapObject();

        }


        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, "ÊÎÍÑÒÐÓÊÒÎÐ ÄÅÐÅÂÍÈ");

        txSleep(10);
        txEnd();
    }


    txDeleteDC(houseVariants[0].picture);
    txDeleteDC(houseVariants[1].picture);
    txDeleteDC(houseVariants[2].picture);
    txDeleteDC(background);

    return 0;
}
