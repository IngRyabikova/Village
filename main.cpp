#include <cstdlib>
#include "TXLib.h"
#include "button.cpp"
#include "mapoject.cpp"
#include <fstream>
#include <string>

using namespace std;

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

int selectPics(int COUNT_PICTURES, MapObject pictures[], int CURRENT_X, int nomer_kartinki)
{
    for (int i = 0 ; i < COUNT_PICTURES;i++)
    {
        if (pictures[i].Click(CURRENT_X))
        {
            nomer_kartinki = i;
        }
    }

    return nomer_kartinki;
}

char* selectCateg(char* selected_category ,Button buttons[], int COUNT_BTN)
{
	for(int j =0; j < COUNT_BTN;j++)
	{
		if (buttons[j].Click())
		{
			selected_category = buttons[j].category;
			txSleep(200);
		}
	}
	return selected_category;
}

void  drawfromCurrentX(MapObject pictures[], int COUNT_PICTURES,int CURRENT_X)
{
    for (int nomer_picture = 0; nomer_picture < COUNT_PICTURES; nomer_picture++)
	{
		pictures[nomer_picture].drawMapObject(CURRENT_X);
	}
}

int main()
{
    txCreateWindow(1200,800);
    txDisableAutoPause();

    HDC background = txLoadImage("Album/Background.bmp");

    int CURRENT_X = 0;
    const int WIDTH_MENU = 200;


    const int COUNT_VARIANTS = 14;
    MapObject variants[COUNT_VARIANTS];
    variants[0] = {   0, "Album/House/house2.bmp"};
    variants[1] = { 200, "Album/House/house1.bmp" };
    variants[2] = { 400, "Album/House/house3.bmp"};
    variants[3] = { 600, "Album/House/House4.bmp"};
    variants[4] = {   0, "Album/Animals/DoG.bmp"};
    variants[5] = { 200, "Album/Animals/PetuX.bmp"};
    variants[6] = { 400, "Album/Animals/piG.bmp" };
    variants[7] = { 600, "Album/Animals/Korova.bmp"};
    variants[8] = {  50, "Album/people/man1.bmp"};
    variants[9] = { 300, "Album/people/man2.bmp" };
    variants[10] ={ 500, "Album/people/women.bmp"};
    variants[11] ={ 100, "Album/Pamatnik/Stalin.bmp" };
    variants[12] ={ 300, "Album/Pamatnik/Lenin.bmp" };
    variants[13] ={ 300, "Album/building/school.bmp" };

    for (int i = 0; i < COUNT_VARIANTS; i++)
    {
        variants[i].x = 1010;
        variants[i].x2 = 1150;
        variants[i].y2 = variants[i].y + 100;
        string str = variants[i].adress;
        int fpos = str.find("/");
        int spos = str.find("/", fpos + 1);
        variants[i].category = str.substr(fpos + 1, spos - fpos -1);
        variants[i].visible = true;
        variants[i].text = "";
        variants[i].picture = txLoadImage (variants[i].adress.c_str());
        variants[i].width = get_widht (variants[i].adress);
        variants[i].hight= get_height (variants[i].adress) ;
    }

    int COUNT_PICTURES = 0;
    MapObject pictures[100];

    string stroka_x;
    string stroka_y;
    string stroka_adress;
    ifstream file("text.txt");

    while (file.good())
    {
        getline(file,stroka_x);
        getline(file,stroka_y);
        getline(file,stroka_adress);


        pictures[COUNT_PICTURES].x = atoi(stroka_x.c_str());
        pictures[COUNT_PICTURES].y = atoi(stroka_y.c_str());
        pictures[COUNT_PICTURES].adress = stroka_adress;

        pictures[COUNT_PICTURES].width = get_widht (pictures[COUNT_PICTURES].adress);
        pictures[COUNT_PICTURES].hight= get_height (pictures[COUNT_PICTURES].adress) ;
        pictures[COUNT_PICTURES].x2 = pictures[COUNT_PICTURES].x + pictures[COUNT_PICTURES].width /3;
        pictures[COUNT_PICTURES].y2 = pictures[COUNT_PICTURES].y + pictures[COUNT_PICTURES].hight /3;
        pictures[COUNT_PICTURES].visible = true;
        pictures[COUNT_PICTURES].text = "";
        pictures[COUNT_PICTURES].picture = txLoadImage ( pictures[COUNT_PICTURES].adress.c_str());





        COUNT_PICTURES++;
    }

    file.close();

    const int COUNT_BTN = 8;
    Button buttons[COUNT_BTN];
    buttons[0] = {  0,0, "Дома", "House"};
    buttons[1] = {160,0, "Люди","people" };
    buttons[2] = {320,0, "Животные","Animals"};
    buttons[3] = {480,0, "Памятники", "Pamatnik"};
    buttons[4] = {640,0, "Здания", "building"};
    buttons[5] = {725,0, "On"};
    buttons[6] = {800,0, "Off"};
    buttons[7] = {850,0, "?"};

    char *selected_category = "";
    int nomer_kartinki = -100;
    int nomer_varianta = -100;

    MapObject arrowLeft  = { 700, "Album/Arrows/Left.bmp",    0,  100, 800};
    MapObject arrowRight = { 700, "Album/Arrows/Right.bmp", 900, 1000, 800};
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
        txBitBlt(txDC(), CURRENT_X - 5632 * 2, 0, 5632, txGetExtentY(), background);
        txBitBlt(txDC(), CURRENT_X - 5632 * 1, 0, 5632, txGetExtentY(), background);
        txBitBlt(txDC(), CURRENT_X           , 0, 5632, txGetExtentY(), background);
        txBitBlt(txDC(), CURRENT_X + 5632 * 1, 0, 5632, txGetExtentY(), background);
        txBitBlt(txDC(), CURRENT_X + 5632 * 2, 0, 5632, txGetExtentY(), background);
        arrowLeft.drawMapObject(0);
        arrowRight.drawMapObject(0);

        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 60);
        txTextOut(200,700, "Конструктор деревни");

        txSetFillColor(TX_BLACK);
        txRectangle(txGetExtentX() - WIDTH_MENU, 0, txGetExtentX(), txGetExtentY());


        drawButtons (buttons, COUNT_BTN);
        //draw pictures
		drawfromCurrentX(pictures, COUNT_PICTURES,CURRENT_X);
        // black menu
        txSetFillColor(TX_BLACK);
        txRectangle(txGetExtentX() - WIDTH_MENU, 0, txGetExtentX(), txGetExtentY());

        drawVariants (COUNT_VARIANTS, variants, selected_category );

        //select a picture
        nomer_kartinki = selectPics(COUNT_PICTURES, pictures, CURRENT_X, nomer_kartinki);

        //Click on menu button
        selected_category = selectCateg(selected_category , buttons, COUNT_BTN - 3);

        if (buttons[5].Click())
        {
            txPlaySound("Music\\somebody.wav");
        }
        else if (buttons[6].Click())
        {
            txPlaySound(NULL);
        }

        else if (buttons[7].Click())
        {
            bool stop = false;
            while (stop == false)
            {
            	txSetFillColor(TX_WHITE);
            	txSetColor(TX_BLACK);
                txRectangle (100, 100,500,500);
                txDrawText(100, 100,500,500,
                    "Приветствую в\n"
                    " справке\n"
                    " \n"
                    " Программа позволяет создать деревню\n"
                    " \n"
                    " \n"
                    " \n"
                    " Разработчики:\n"
                    "Никита, Илья, Ярослав, Иван");

                if (txMouseButtons() == 1 &&
                    txMouseX() > 100 &&
                    txMouseX() < 500 &&
                    txMouseY() > 100 &&
                    txMouseY() < 500)
                {
                    stop = true;
                }

                txSleep(10);
            }
        }

        //Click on variant
        if (!(txMouseButtons() == 1 && pictures[nomer_kartinki].clicked))
        {
            for (int i = 0; i < COUNT_VARIANTS; i++)
            {
                if (variants[i].Click(0) &&
                    selected_category == variants[i].category)
                {
                    int new_x = -CURRENT_X + random(0,844);
                    int new_y = 63 + random(0,732);
                    MapObject tmp = {
                        new_y,
                        variants[i].adress,
                        new_x,
                        new_x + variants[i].width/3,
                        new_y + variants[i].hight/3,
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

        txSleep(10);
        txEnd();
    }

    for (int i = 0; i < COUNT_VARIANTS; i++) {
        txDeleteDC(variants[i].picture);
    }
    txDeleteDC(background);


    ofstream file1("text1.txt");

    for (int nomer_picture = 0; nomer_picture < COUNT_PICTURES; nomer_picture++)
	{
        file1 << pictures[nomer_picture].x << endl;
        file1 << pictures[nomer_picture].y << endl;
        file1 << pictures[nomer_picture].adress << endl;
	}

    file1.close();

    return 0;
}
