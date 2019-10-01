#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int main()
{
    txCreateWindow(1000,800);


    MapObject houseVariants[4];
    houseVariants[0] = { 810,   0, 930, 200, txLoadImage ("Album/House/house1.bmp"), ""};
    houseVariants[1] = { 810, 300, 930, 500, txLoadImage ("Album/House/house2.bmp"), ""};
    houseVariants[2] = { 810, 600, 930, 800, txLoadImage ("Album/House/house3.bmp"), ""};
    houseVariants[3] = { 810, 200, 930, 300, txLoadImage ("Album/House/House4.bmp"), ""};

    MapObject2 b1 = { 100, 100, 600, 600, txLoadImage ("Album/House/house2.bmp"), ""};
    MapObject2 d =  { 600, 550, 900, 700, txLoadImage ("Album/Animals/DoG.bmp"), ""};
    MapObject2 F =  { 400, 600, 900, 700, txLoadImage ("Album/Animals/PetuX.bmp"), ""};
    MapObject2 G =  { 200, 600, 900, 700, txLoadImage ("Album/Animals/piG.bmp"), ""};



    bool visible = false;
    bool visible2 = false;
    bool visible3 = false;

    Button buttons[7];
    buttons[0] = {0,0, "���"};
    buttons[1] = {100,0, "������"};
    buttons[2] = {200,0, "�����"};
    buttons[3] = {300,0, "������"};
    buttons[4] = {400,0, "����\n����"};
    buttons[5] = {500,0, "����"};
    buttons[6] = {600,0, "������"};

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txRectangle(txGetExtentX() - 200, 0, txGetExtentX(), txGetExtentY());


        for (int nomer_kartinki = 0; nomer_kartinki <= 3 ; nomer_kartinki ++)
        {
            houseVariants[nomer_kartinki].drawMapObject();
        }

        for (int nomer_knopki = 0; nomer_knopki < 7; nomer_knopki++)
        {
            buttons[nomer_knopki].drawButton();
            if (buttons[nomer_knopki].Click ())
            {
                txTextOut(100, 500, "�� ������ �� ������");
            }
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
        txTextOut(200,700, "����������� �������");

        txSleep(10);
        txEnd();
    }


    txDeleteDC(houseVariants[0].picture);
    txDeleteDC(houseVariants[1].picture);
    txDeleteDC(houseVariants[2].picture);

    return 0;
}
