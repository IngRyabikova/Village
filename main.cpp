#include <cstdlib>
#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"

int get_height  (string adress)
{
  char info[54];
  FILE*f = fopen (adress.c_str() , "r");
  fread (info, sizeof (char), 54, f);
  int height =* (int*) &info[22];
  return height;
}

int get_widht  (string adress)
{
  char info[54];
  FILE*f = fopen (adress.c_str() , "r");
  fread (info, sizeof (char), 54, f);
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
    const int WIDTH_MENU = 200;


    const int COUNT_VARIANTS = 14;
    MapObject variants[COUNT_VARIANTS];
    variants[0] = { 1030,   0, 1130, 150,"Album/House/house2.bmp", "House"};
    variants[1] = { 1010, 200, 1180, 350,"Album/House/house1.bmp", "House" };
    variants[2] = { 1010, 400, 1200, 600,"Album/House/house3.bmp","House"};
    variants[3] = { 1010, 600, 1150, 800, "Album/House/House4.bmp","House"};
    variants[4] = { 1010,   0, 1170, 120, "Album/Animals/DoG.bmp","Animals"};
    variants[5] = { 1010, 200, 1130, 400, "Album/Animals/PetuX.bmp","Animals"};
    variants[6] = { 1010, 400, 1130, 600, "Album/Animals/piG.bmp","Animals" };
    variants[7] = { 1010, 600, 1130, 800, "Album/Animals/Korova.bmp","Animals"};
    variants[8] = { 1010,  50, 1170, 270, "Album/people/man1.bmp","People"};
    variants[9] = { 1010, 300, 1130, 500, "Album/people/man2.bmp","People" };
    variants[10] ={ 1010, 500, 1170, 700, "Album/people/women.bmp","People" };
    variants[11] ={ 1010, 100, 1130, 300, "Album/Pamatnik/Stalin.bmp","Pamatnik" };
    variants[12] ={ 1010, 300, 1180, 500, "Album/Pamatnik/Lenin.bmp","Pamatnik" };
    variants[13] ={ 1010, 300, 1180, 500, "Album/House/school.bmp","Zdanie" };

    for (int i = 0; i < COUNT_VARIANTS; i++)
    {
    string str = variants[i].adress;
    int fpos = str.find("/");
    int spos = str.find("/", fpos + 1);
        variants[i].visible = true;
        variants[i].text = "";
        variants[i].picture = txLoadImage (variants[i].adress.c_str());
        variants[i].width = get_widht (variants[i].adress);
        variants[i].hight= get_height (variants[i].adress) ;
    }

    int COUNT_PICTURES = 0;
    MapObject pictures[100];

    Button buttons[5];
    buttons[0] = {  0,0, "Дома", "House"};
    buttons[1] = {160,0, "Люди","People" };
    buttons[2] = {320,0, "Животные","Animals"};
    buttons[3] = {480,0, "Памятники", "Pamatnik"};
    buttons[4] = {640,0, "Здания", "Zdanie"};

    char *selected_category = "";
    int nomer_kartinki = -100;
    int nomer_varianta = -100;

    MapObject arrowLeft  = {   0,   700,  100, 800, "Album/Arrows/Left.bmp"};
    MapObject arrowRight = { 900,   700, 1000, 800, "Album/Arrows/Right.bmp"};
    arrowLeft.visible = true;
    arrowLeft.picture = txLoadImage (arrowLeft.adress.c_str());
    arrowLeft.width = get_widht (arrowLeft.adress);
    arrowLeft.hight= get_height (arrowLeft.adress);
    arrowLeft.text= "";

    arrowRight.visible = true;
    arrowRight.picture = txLoadImage (arrowRight.adress.c_str());
    arrowRight.width = get_widht (arrowRight .adress);
    arrowRight.hight= get_height (arrowRight.adress);
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


        drawButtons (buttons, 5);
        //draw pictures
        for (int nomer_picture = 0; nomer_picture < COUNT_PICTURES; nomer_picture++)
        {
            pictures[nomer_picture].drawMapObject(CURRENT_X);
        }
        // black menu
        txSetFillColor(TX_BLACK);
        txRectangle(txGetExtentX() - WIDTH_MENU, 0, txGetExtentX(), txGetExtentY());

        drawVariants (COUNT_VARIANTS, variants, selected_category );

        //select a picture
        for (int i = 0 ; i < COUNT_PICTURES;i++)
        {
            if (pictures[i].Click(CURRENT_X))
            {
                nomer_kartinki = i;
            }
        }
        //Click on menu button
        for(int j =0; j < 5;j++)
        {
            if (buttons[j].Click())
            {
                selected_category = buttons[j].category;
                txSleep(200);
            }
        }


        //Click on variant
        for (int i = 0; i < COUNT_VARIANTS; i++)
        {
            if (variants[i].Click(0) &&
                selected_category == variants[i].category)
            {
                int new_x = -CURRENT_X + random(0,844);
                int new_y = 63 + random(0,732);
                MapObject tmp = {
                    new_x,
                    new_y,
                    new_x + variants[i].width/3,
                    new_y + variants[i].hight/3,
                    variants[i].adress,
                     "",
                    variants[i].picture,
                    variants[i].width,
                    variants[i].hight,
                    "",
                    true
                };

                pictures[COUNT_PICTURES] = tmp;
                COUNT_PICTURES++;
                txSleep(200);
            }
        }

        //Click on picture
        if (pictures[nomer_kartinki].Click(CURRENT_X) && (txMouseX() < txGetExtentX() - 300))
        {
            for (int k = 0; k < COUNT_PICTURES; k++)
            {
                pictures[k].clicked = false;
            }
            pictures[nomer_kartinki].clicked = true;
        }

        if ((txMouseButtons() & 1) && pictures[nomer_kartinki].clicked)
        {
            int width = pictures[nomer_kartinki].x2  - pictures[nomer_kartinki].x;
            pictures[nomer_kartinki].x = txMouseX() - CURRENT_X - width /2 ;
            pictures[nomer_kartinki].x2 = pictures[nomer_kartinki].x + width ;
            int high = pictures[nomer_kartinki].y2 - pictures[nomer_kartinki].y;
            pictures[nomer_kartinki].y = txMouseY() - high / 2 ;
            pictures[nomer_kartinki].y2 = pictures[nomer_kartinki].y + high ;
        }

        if (!(txMouseButtons() & 1) && pictures[nomer_kartinki].clicked)
        {
            pictures[nomer_kartinki].clicked = false;
        }

        //Deleting picture
        if (nomer_kartinki >= 0 && GetAsyncKeyState(VK_DELETE))
        {
            pictures[nomer_kartinki] = pictures[COUNT_PICTURES - 1];
            COUNT_PICTURES -= 1 ;
            nomer_kartinki = - 100 ;
        }

        //Camera moving
        if (arrowRight.Click(0))
        {
            CURRENT_X -= 10;
        }
        else if (arrowLeft.Click(0))
        {
            CURRENT_X += 10;
        }

        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, "Конструктор деревни");

        txSleep(10);
        txEnd();
    }

    for (int i = 0; i < COUNT_VARIANTS; i++) {
        txDeleteDC(variants[i].picture);
    }
    txDeleteDC(background);

    return 0;
}
