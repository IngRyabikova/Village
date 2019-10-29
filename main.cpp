#include <cstdlib>
#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int get_height  (string adress)
{
  unsigned char info[54];
  FILE*f = fopen (adress.c_str() , "r");
  fread (info, sizeof (unsigned char), 54, f);
  int height =* (int*) &info[22];
  return height;
}

int get_widht  (string adress)
{
  unsigned char info[54];
  FILE*f = fopen (adress.c_str() , "r");
  fread (info, sizeof (unsigned char), 54, f);
  int widht =* (int*) &info[18];
  return widht;
}


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
    houseVariants[0] = { 1030,   0, 1130, 150,"Album/House/house2.bmp", "House"};
    houseVariants[1] = { 1010, 200, 1180, 350,"Album/House/house1.bmp", "House" };
    houseVariants[2] = { 1010, 400, 1200, 600,"Album/House/house3.bmp","House"};
    houseVariants[3] = { 1010, 600, 1150, 800, "Album/House/House4.bmp","House"};
    houseVariants[4] = { 1010,   0, 1170, 120, "Album/Animals/DoG.bmp","Animals"};
    houseVariants[5] = { 1010, 200, 1130, 400, "Album/Animals/PetuX.bmp","Animals"};
    houseVariants[6] = { 1010, 400, 1130, 600, "Album/Animals/piG.bmp","Animals" };
    houseVariants[7] = { 1010, 600, 1130, 800, "Album/Animals/Korova.bmp","Animals"};
    houseVariants[8] = { 1010,  50, 1170, 270, "Album/people/man1.bmp","People"};
    houseVariants[9] = { 1010, 300, 1130, 500, "Album/people/man2.bmp","People" };
    houseVariants[10] ={ 1010, 500, 1170, 700, "Album/people/women.bmp","People" };
    houseVariants[11] ={ 1010, 100, 1130, 300, "Album/Pamatnik/Stalin.bmp","Pamatnik" };
    houseVariants[12] ={ 1010, 300, 1180, 500, "Album/Pamatnik/Lenin.bmp","Pamatnik" };

    for (int i = 0; i < COUNT_HOUSE_VARIANTS; i++)
    {
        houseVariants[i].visible = true;
        houseVariants[i].text = "";
        houseVariants[i].picture = txLoadImage (houseVariants[i].adress.c_str());
        houseVariants[i].width = get_widht (houseVariants[i].adress);
        houseVariants[i].hight= get_height (houseVariants[i].adress) ;
    }
      
    int COUNT_PICTURES = 0;
    MapObject pictures[100];

    Button buttons[4];
    buttons[0] = {  0,0, "Äîìà", "House"};
    buttons[1] = {160,0, "Ëþäè","People" };
    buttons[2] = {320,0, "Æèâîòíûå","Animals"};
    buttons[3] = {480,0, "Ïàìÿòíèêè", "Pamatnik"};

    char *category = "";
    int nomer_kartinki = -100;
    int nomer_varianta = -100;

    MapObject arrowLeft  = {   0,   650, 150, 800, "Album/Arrows/Left.bmp"};
    MapObject arrowRight = { 750,   650, 900, 800, "Album/Arrows/Right.bmp"};
    arrowLeft.visible = true;
    arrowLeft.picture = txLoadImage (arrowLeft.adress.c_str());
    arrowLeft.width = get_widht (arrowLeft.adress);
    arrowLeft.hight= get_height (arrowLeft.adress) ;
    arrowLeft.text= "";

    arrowRight .visible = true;
    arrowRight .picture = txLoadImage (arrowRight.adress.c_str());
    arrowRight .width = get_widht (arrowRight .adress);
    arrowRight .hight= get_height (arrowRight.adress) ;
    arrowRight.text= "";

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txBitBlt(txDC(), CURRENT_X, 0, 10000, txGetExtentY(), background);

        arrowLeft.drawMapObject(0);
        arrowRight.drawMapObject(0);

        txSetFillColor(TX_BLACK);
        txRectangle(txGetExtentX() - WIDTH_MENU, 0, txGetExtentX(), txGetExtentY());


        drawButtons (buttons, 4);
        //draw pictures
        for (int nomer_picture = 0; nomer_picture < COUNT_PICTURES; nomer_picture++)
        {
            pictures[nomer_picture].drawMapObject(CURRENT_X);
        }
        // black menu
        txSetFillColor(TX_BLACK);
        txRectangle(txGetExtentX() - 300, 0, txGetExtentX(), txGetExtentY());

        drawVariants (COUNT_HOUSE_VARIANTS, houseVariants, category );

        //select a picture
        for (int i = 0 ; i < COUNT_PICTURES;i++)
        {
            if (pictures[i].Click(CURRENT_X))
            {
                nomer_kartinki = i;
            }
        }
        //Click on menu button
        for(int j =0; j <= 3;j++)
        {
            if (buttons[j].Click())
            {
                category = buttons[j].category;
                txSleep(200);
            }
        }


        //Click on variant
        for (int i = 0; i < COUNT_HOUSE_VARIANTS; i++)
        {
            if (houseVariants[i].Click(CURRENT_X) &&
                category == houseVariants[i].category)
            {
                int rand_x = rand() % 844;
                int rand_y = 63 + rand() % 732;
                MapObject tmp = {
                    rand_x,
                    rand_y,
                    rand_x + houseVariants[i].width/3,
                    rand_y + houseVariants[i].hight/3,
                    houseVariants[i].adress,
                     "",
                    houseVariants[i].picture,
                    houseVariants[i].width,
                    houseVariants[i].hight,
                   ""
                };

                pictures[COUNT_PICTURES] = tmp;
                COUNT_PICTURES++;
                txSleep(200);
            }
        }

        //Click on picture
        for (int i = 0; i < COUNT_PICTURES; i++)
        {
            if (pictures[i].Click(CURRENT_X) && (txMouseX() < txGetExtentX() - 300))
            {
                for (int k = 0; k < COUNT_PICTURES; k++)
                {
                    pictures[k].clicked = false;
                }
                pictures[i].clicked = true;
            }

            if ((txMouseButtons() & 1) && pictures[i].clicked)
            {
                int width = pictures[i].x2  - pictures[i].x;
                pictures[i].x = txMouseX() - CURRENT_X - width /2 ;
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

        //Camera moving
        if(arrowRight.Click())
        {
         CURRENT_X -= 10;
        }
        if(arrowLeft.Click())
        {
         CURRENT_X += 10;

        }

        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, "Êîíñòðóêòîð äåðåâíè");

        txSleep(10);
        txEnd();
    }

    for (int i = 0; i < COUNT_HOUSE_VARIANTS; i++) {
        txDeleteDC(houseVariants[i].picture);
    }
    txDeleteDC(background);

    return 0;
}