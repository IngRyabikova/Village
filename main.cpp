#include <cstdlib>
#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"
void drawButtons (Button buttons[], int count)
{
      for (int nomer_knopki = 0; nomer_knopki < count; nomer_knopki++)
        {
            buttons[nomer_knopki].drawButton();
        }

}

void drawVariants (int count, MapObject houseVariants[], char * category )
{
        for (int nomer_kartinki = 0; nomer_kartinki < count ; nomer_kartinki ++)
        {
            if (category == houseVariants[nomer_kartinki].category)
            {
                houseVariants[nomer_kartinki].drawMapObject(0);
            }
        }
}

int main()
{
    txCreateWindow(1200,800);
    txDisableAutoPause();
    txPlaySound("Music\\somebody.wav",SND_LOOP);

    HDC background = txLoadImage("Album/Background.bmp");

    int CURRENT_X = 0;


    const int COUNT_HOUSE_VARIANTS = 13;
    MapObject houseVariants[COUNT_HOUSE_VARIANTS];
    houseVariants[0] = { 1030,   0, 1130, 150, txLoadImage ("Album/House/house2.bmp"), "", 799, 485, true, "House"};
    houseVariants[1] = { 1010, 200, 1180, 350, txLoadImage ("Album/House/house1.bmp"), "", 500, 366, true, "House"};
    houseVariants[2] = { 1010, 400, 1200, 600, txLoadImage ("Album/House/house3.bmp"), "", 796, 515, true, "House"};
    houseVariants[3] = { 1010, 600, 1150, 800, txLoadImage ("Album/House/House4.bmp"), "", 497, 553, true, "House"};;
    houseVariants[4] = { 1010,   0, 1170, 120, txLoadImage ("Album/Animals/DoG.bmp"), "",185 , 151, true, "Animals"};
    houseVariants[5] = { 1010, 200, 1130, 400, txLoadImage ("Album/Animals/PetuX.bmp"), "",96 , 136, true, "Animals"};
    houseVariants[6] = { 1010, 400, 1130, 600, txLoadImage ("Album/Animals/piG.bmp"), "",119 , 95, true, "Animals"};
    houseVariants[7] = { 1010, 600, 1130, 800, txLoadImage ("Album/Animals/Korova.bmp"), "",400 , 362, true, "Animals"};
    houseVariants[8] = { 1010,  50, 1170, 270, txLoadImage ("Album/people/man1.bmp"), "",205 , 285, true, "People"};
    houseVariants[9] = { 1010, 300, 1130, 500, txLoadImage ("Album/people/man2.bmp"), "",174 , 269, true, "People"};
    houseVariants[10] ={ 1010, 500, 1170, 700, txLoadImage ("Album/people/women.bmp"), "",155 , 377, true, "People"};
    houseVariants[11] ={ 1010, 100, 1130, 300, txLoadImage ("Album/Pamatnik/Stalin.bmp"), "",90 , 200, true, "Pamatnik"};
    houseVariants[12] ={ 1010, 300, 1180, 500, txLoadImage ("Album/Pamatnik/Lenin.bmp"), "",148 ,292, true, "Pamatnik"};

    HDC arrowLeft = txLoadImage ("Album/Arrows/Left.bmp");
    HDC arrowRight = txLoadImage ("Album/Arrows/Right.bmp");

    int COUNT_PICTURES = 0;
    MapObject pictures[100];

    Button buttons[4];
    buttons[0] = {  0,0, "Дома", "House"};
    buttons[1] = {160,0, "Люди","People" };
    buttons[2] = {320,0, "Животные","Animals"};
    buttons[3] = {480,0, "Памятники", "Pamatnik"};

    char *category = "";
    int nomer_kartinki = -100;
    int nomer_varianta = -100;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background);

        txTransparentBlt(txDC(), 0, 650, 150,150, arrowLeft   ,0,0,TX_WHITE);
        txTransparentBlt(txDC(), 750, 650, 150,150, arrowRight,0,0,TX_WHITE);

        txSetFillColor(TX_TRANSPARENT);
        txRectangle(txGetExtentX() - 300, 0, txGetExtentX(), txGetExtentY());

        drawVariants (COUNT_HOUSE_VARIANTS, houseVariants, category );
        drawButtons (buttons, 4);

        for (int nomer_picture = 0; nomer_picture < COUNT_PICTURES; nomer_picture++)
        {
            pictures[nomer_picture].drawMapObject(CURRENT_X);
        }

        for (int i = 0 ; i < COUNT_PICTURES;i++)
        {
            if (pictures[i].Click())
            {
                nomer_kartinki = i;
            }
         }

        if(GetAsyncKeyState(VK_LEFT)&& nomer_kartinki>=0)
        {
            pictures[nomer_kartinki].x-=5;
            pictures[nomer_kartinki].x2-=5;
        }
        if(GetAsyncKeyState(VK_RIGHT)&& nomer_kartinki>=0)
        {
            pictures[nomer_kartinki].x+=5;
            pictures[nomer_kartinki].x2+=5;
        }
        if(GetAsyncKeyState(VK_UP)&& nomer_kartinki>=0)
        {
            pictures[nomer_kartinki].y-=5;
            pictures[nomer_kartinki].y2-=5;
        }
        if(GetAsyncKeyState(VK_DOWN)&& nomer_kartinki>=0)
        {
            pictures[nomer_kartinki].y+=5;
            pictures[nomer_kartinki].y2+=5;
        }


        for(int j =0; j <= 3;j++)
        {
            if (buttons[j].Click())
            {
                category = buttons[j].category;
                txSleep(200);
            }
        }


        /*for(int i = 0; i < COUNT_HOUSE_VARIANTS; i++)
        {
            if(houseVariants[i].Click() &&
                category == houseVariants[i].category)
            {
                nomer_varianta = i;
                clicked = true;
            }
        } */

        for (int i = 0; i < COUNT_HOUSE_VARIANTS; i++)
        {
            if (houseVariants[i].Click() &&
                category == houseVariants[i].category)
            {
                int rand_x = rand() % 844;
                int rand_y = 63 + rand() % 732;
                MapObject tmp = {
                    rand_x,
                    rand_y,
                    rand_x + houseVariants[i].width/3,
                    rand_y + houseVariants[i].hight/3,
                    houseVariants[i].picture,
                    "",
                    houseVariants[i].width,
                    houseVariants[i].hight,
                    true,
                    ""
                };
                pictures[COUNT_PICTURES] = tmp;
                COUNT_PICTURES++;
                txSleep(200);
            }
        }


        for (int i = 0; i < COUNT_PICTURES; i++)
        {
            if (pictures[i].Click())
            {
                for (int k = 0; k < COUNT_PICTURES; k++)
                {
                    pictures[k].clicked = false;
                }
                pictures[i].clicked = true;
            }

            if ((txMouseButtons() & 1) && pictures[i].clicked)
            {
                int width = pictures[i].x2 - pictures[i].x;
                pictures[i].x = txMouseX() - width /2 ;
                pictures[i].x2 = pictures[i].x + width ;
                int high = pictures[i].y2 - pictures[i].y;
                pictures[i].y = txMouseY() - high / 2 ;
                pictures[i].y2 = pictures[i].y + high ;
            }

            if (!(txMouseButtons() & 1) && pictures[i].clicked)
            {
                pictures[i].clicked = false;
            }
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
         CURRENT_X++;

        }


        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, "Конструктор деревни");

        txSleep(10);
        txEnd();
    }

    for (int i = 0; i < COUNT_HOUSE_VARIANTS; i++) {
        txDeleteDC(houseVariants[i].picture);
    }
    txDeleteDC(background);

    return 0;
}
