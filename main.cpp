#include <cstdlib> //��� ������� rand()
#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int main()
{
    txCreateWindow(1200,800);
    txDisableAutoPause();

    HDC background = txLoadImage("Album/Background.bmp");

    const int COUNT_HOUSE_VARIANTS = 11;
    MapObject houseVariants[COUNT_HOUSE_VARIANTS];
    houseVariants[0] = { 1030,   0, 1130, 150, txLoadImage ("Album/House/house2.bmp"), "", 799, 485, true, "House"};
    houseVariants[1] = { 1010, 200, 1180, 350, txLoadImage ("Album/House/house1.bmp"), "", 500, 366, true, "House"};
    houseVariants[2] = { 1010, 400, 1200, 600, txLoadImage ("Album/House/house3.bmp"), "", 796, 515, true, "House"};
    houseVariants[3] = { 1010, 600, 1150, 800, txLoadImage ("Album/House/House4.bmp"), "", 497, 553, true, "House"};;
    houseVariants[4] = { 1010,   0, 1170, 120, txLoadImage ("Album/Animals/DoG.bmp"), "",90 , 70, true, "Animals"};
    houseVariants[5] = { 1010, 200, 1130, 400, txLoadImage ("Album/Animals/PetuX.bmp"), "",50 , 67, true, "Animals"};
    houseVariants[6] = { 1010, 400, 1130, 600, txLoadImage ("Album/Animals/DoG.bmp"), "",90 , 70, true, "Animals"};
    houseVariants[7] = { 1010, 600, 1130, 800, txLoadImage ("Album/Animals/DoG.bmp"), "",90 , 70, true, "Animals"};
    houseVariants[8] = { 1010,  50, 1170, 270, txLoadImage ("Album/people/man1.bmp"), "",205 , 285, true, "People"};
    houseVariants[9] = { 1010, 300, 1130, 500, txLoadImage ("Album/people/man2.bmp"), "",174 , 269, true, "People"};
    houseVariants[10] ={ 1010, 500, 1130, 700, txLoadImage ("Album/people/women.bmp"), "",299 , 732, true, "People"};

    int last_num_obj = 0;
    MapObject obj[100];

    Button buttons[7];
    buttons[0] = {  0,0, "����"};
    buttons[1] = {120,0, "������"};
    buttons[2] = {240,0, "�����"};
    buttons[3] = {360,0, "������"};
    buttons[4] = {480,0, "��������"};
    buttons[5] = {600,0, "����"};
    buttons[6] = {720,0, "������"};
    char *catalog;


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background);

        txSetFillColor(TX_TRANSPARENT);

        txRectangle(txGetExtentX() - 300, 0, txGetExtentX(), txGetExtentY());

        for (int nomer_kartinki = 0; nomer_kartinki < COUNT_HOUSE_VARIANTS ; nomer_kartinki ++)
        {
            if (catalog == houseVariants[nomer_kartinki].catalog)
            {
                houseVariants[nomer_kartinki].drawMapObject();
            }
        }


        for (int nomer_knopki = 0; nomer_knopki < 7; nomer_knopki++)
        {
            buttons[nomer_knopki].drawButton();
        }

        for (int nomer_picture = 0; nomer_picture < last_num_obj; nomer_picture++)
        {
            obj[nomer_picture].drawMapObject();
        }


        if (buttons[0].Click())
        {
            catalog = "House";
            txSleep(200);
        }
        if (buttons[4].Click())
        {
            catalog = "Animals";
            txSleep(200);
        }
        if (buttons[5].Click())
        {
            catalog = "People";
            txSleep(200);
        }


        for(int i = 0; i < COUNT_HOUSE_VARIANTS; i++)
        {
            if(houseVariants[i].Click() &&
                catalog == houseVariants[i].catalog)
            {
                // ��� ��������� �������� ����)))
                int rand_x = rand() % 844;
                int rand_y = 63 + rand() % 732;
                MapObject tmp = {
                    rand_x,
                    rand_y,
                    rand_x + houseVariants[i].width/3, //��������� ������ ������ � ������
                    rand_y + houseVariants[i].hight/3,
                    houseVariants[i].picture,
                    "",
                    houseVariants[i].width,
                    houseVariants[i].hight,
                    true,
                    ""
                };
                obj[last_num_obj] = tmp;
                last_num_obj++;
                txSleep(200);
            }
        }

        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, "����������� �������");

        txSleep(10);
        txEnd();
    }

    for (int i = 0; i < COUNT_HOUSE_VARIANTS; i++) {
        txDeleteDC(houseVariants[i].picture);
    }
    txDeleteDC(background);

    return 0;
}
