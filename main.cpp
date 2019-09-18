
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <Автор>, <Год> (<Имя> <Почта>)
//! @date       <Дата>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.01 Alpha
//!             - Только что созданный файл
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

       drawButton(0,0, "ДОМ");
       drawButton(100,0, "СОБАКА");
       drawButton(200,0, "КОЗА");
       drawButton(300,0, "СОЛНЦЕ");
       drawButton(400,0, "ОБЛАКА");
       drawButton(500,0, "ДЯДЯ\nПЕТЯ");


    }

