
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"

void drawButton(int x, int y, const char* text)
{
      txSetFillColor(TX_MAGENTA);
      txRectangle(x,y, x + 100, y + 70);
      txSelectFont("Comic Sans MS", 30);
      txDrawText(x,y, x +100, y +70, text) ;
}

int main()
    {
      txCreateWindow(1000,800);

       drawButton(0,0, "���");
       drawButton(100,0, "������");
       drawButton(200,0, "����");
       drawButton(300,0, "������");
       drawButton(400,0, "������");
       drawButton(500,0, "����\n����");


    }

