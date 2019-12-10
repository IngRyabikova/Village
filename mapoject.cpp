#include "TXLib.h"

struct MapObject
{
    ///адрес файла с картинкой
    string adress;
    ///левая граница картинки
    int x;
    ///верхняя граница картинки
    int y;
    ///правая граница картинки
    int x2;
    /*!
    \
    правое граница карты
     */
    int y2;
    /*!
    \

     */




    string category;
    HDC picture;
    int width;
    int hight;
    const char* text;
    bool visible;
    bool clicked;

    /*!
    \ ваня привет я илон маск

       Спасибо ваня что купил мне этот Reno logan чёрного цвета 20 века
       P.S привет с марса
     */
    void drawMapObject(int current_x)
    {
        if (visible)
        {
            Win32::TransparentBlt(txDC(), x + current_x,  y, x2 - x, y2 - y, picture, 0, 0, width, hight, TX_WHITE);
            txDrawText(      x,  y, x2, y2, text);
        }
    }

    bool Click(int current_x) /*!
    {                         \
                               делает клик
                               */
    {

        if (txMouseButtons() == 1 &&
                txMouseX() > x + current_x &&   //Г¤Г®Г«Г¦Г­Г  ГЎГ»ГІГј Г±Г®ГІГЄГ 
                txMouseX() < x2 + current_x &&   //Г¤Г®Г«Г¦Г­Г  ГЎГ»ГІГј Г±Г®ГІГЄГ 
                txMouseY() > y    &&   //Г¤Г®Г«Г¦ГҐГ­ ГЎГ»ГІГј Г­Г®Г«Гј
                txMouseY() < y2 )         //Г¤Г®Г«Г¦Г­Г® ГЎГ»ГІГј 70
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void DeleteAllPictures(const int COUNT_VARIANTS, MapObject variants[], HDC background )
{
    for (int i = 0; i < COUNT_VARIANTS; i++) {
        txDeleteDC(variants[i].picture);
    }
    txDeleteDC(background);
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




