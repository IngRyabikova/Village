#include "TXLib.h"



int main()
{
    txCreateWindow (1000 , 800) ;

    HDC pic = txLoadImage("C:\\Users\\user\\Pictures\\house5.bmp");
    txSetColor(TX_BLACK);

    while(true)
    {
        txClear();
        txBitBlt(txDC(), 0,0,1700,1600,pic);
        txRectangle(50,50,100,200);

        if (txMouseButtons() == 1 &&
            txMouseX() >  50 &&
            txMouseX() < 100 &&
            txMouseY() <  200)
        {
            txTextOut(100, 500, "dsfsdf");
        }

        txSleep(10);
    }
    txDeleteDC(pic);


    return 0;
}
