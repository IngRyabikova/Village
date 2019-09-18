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

    drawButton(0,0, "днл");
    drawButton(100,0, "янаюйю");
    drawButton(200,0, "йнгю");
    drawButton(300,0, "янкмже");
    drawButton(400,0, "накюйю");
    drawButton(500,0, "дъдъ\nоеръ");
}