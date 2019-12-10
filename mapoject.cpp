#include "TXLib.h"

struct MapObject
{
    ///����� ����� � ���������
    string adress;
    ///����� ������� ��������
    int x;
    ///������� ������� ��������
    int y;
    ///������ ������� ��������
    int x2;
    /*!
    \
    ������ ������� �����
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
    \ ���� ������ � ���� ����

       ������� ���� ��� ����� ��� ���� Reno logan ������� ����� 20 ����
       P.S ������ � �����
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
                               ������ ����
                               */
    {

        if (txMouseButtons() == 1 &&
                txMouseX() > x + current_x &&   //äîëæíà áûòü ñîòêà
                txMouseX() < x2 + current_x &&   //äîëæíà áûòü ñîòêà
                txMouseY() > y    &&   //äîëæåí áûòü íîëü
                txMouseY() < y2 )         //äîëæíî áûòü 70
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




