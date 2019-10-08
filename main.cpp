#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int main()
{
    txCreateWindow(1200,800);

    HDC background = txLoadImage("Album/background.bmp");

    MapObject houseVariants[4];
    houseVariants[0] = { 1030,   0, 1130, 150, txLoadImage ("Album/House/house1.bmp"), "", 500, 366, true};
    houseVariants[1] = { 1010, 200, 1180, 350, txLoadImage ("Album/House/house2.bmp"), "", 799, 485, true};
    houseVariants[2] = { 1010, 400, 1200, 600, txLoadImage ("Album/House/house3.bmp"), "", 796, 515, true};
    houseVariants[3] = { 1010, 600, 1150, 800, txLoadImage ("Album/House/House4.bmp"), "", 497, 553, true};

    MapObject animals[4];
    animals[0] = { 1010,   0, 1170, 120, txLoadImage ("Album/Animals/DoG.bmp"), "",90 , 70, true};
    animals[1] = { 1010, 200, 1130, 400, txLoadImage ("Album/Animals/piG.bmp"), "",119 , 95, true};
    animals[2] = { 1010, 400, 1130, 600, txLoadImage ("Album/Animals/PetuX.bmp"), "",50 , 67, true};

    MapObject people[4];
    people[0] = { 1010, 50, 1170, 270, txLoadImage ("Album/people/man1.bmp"), "",270 , 712, true};
    people[1] = { 1010, 300, 1130, 500, txLoadImage ("Album/people/man2.bmp"), "",212 , 613, true};
    people[2] = { 1010, 500, 1130, 700, txLoadImage ("Album/people/women.bmp"), "",309 , 748, true};

    MapObject obj[4];
    obj[0] = { 100, 100, 800, 700, txLoadImage ("Album/House/house2.bmp"), "",  799 ,485, false};
    obj[1] =  { 600, 550, 900, 700, txLoadImage ("Album/Animals/DoG.bmp"), "",   90 ,70, false};
    obj[2] =  { 400, 600, 900, 700, txLoadImage ("Album/Animals/PetuX.bmp"), "", 50  ,67, false};
    obj[3] =  { 200, 600, 900, 700, txLoadImage ("Album/Animals/piG.bmp"), "",   119 ,95, false};

    bool visible = false;
    bool visible2 = false;
    bool visible3 = false;

    Button buttons[7];
    buttons[0] = {  0,0, "����", txLoadImage("Album/button/fon_b.bmp")};
    buttons[1] = {120,0, "������", txLoadImage("Album/button/fon_b.bmp")};
    buttons[2] = {240,0, "�����", txLoadImage("Album/button/fon_b.bmp")};
    buttons[3] = {360,0, "������", txLoadImage("Album/button/fon_b.bmp")};
    buttons[4] = {480,0, "��������", txLoadImage("Album/button/fon_b.bmp")};
    buttons[5] = {640,0, "��������", txLoadImage("Album/button/fon_b.bmp")};


    bool vid = false;
    bool vid2 = false;
    bool vid3 = false;


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background);

        txSetFillColor(TX_TRANSPARENT);

        txRectangle(txGetExtentX() - 300, 0, txGetExtentX(), txGetExtentY());

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

            if (vid3)
            {
                people[nomer_kartinki].drawMapObject();
            }
        }


        for (int nomer_knopki = 0; nomer_knopki < 7; nomer_knopki++)
        {
            buttons[nomer_knopki].drawButton();
            if (buttons[nomer_knopki].Click ())
            {
                txSetColor(TX_BLACK);
                txTextOut(100, 500, "�� ������ �� ������");
            }
        }

        for (int nomer_picture = 0; nomer_picture <= 2;nomer_picture++)
        {
            obj[nomer_picture].drawMapObject();
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
        if (buttons[5].Click())
        {
            vid3 = !vid3;
            txSleep(200);
        }



        if (buttons[1].Click ())
        {
            obj[1].visible = !obj[1].visible;
            txSleep(200);
        }
        if (buttons[2].Click ())
        {
            obj[2].visible = !obj[2].visible;
            txSleep(200);
        }
        if (buttons[3].Click ())
        {
            obj[3].visible = !obj[3].visible;
            txSleep(200);
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
    txDeleteDC(background);

    return 0;
}
