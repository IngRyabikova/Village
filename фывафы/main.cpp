#include "TXLib.h"




int main()
{
    txCreateWindow(1000,800);
    HDC  HOUSE =  txLoadImage ( "���.bmp")   ;
    HDC  DOG =  txLoadImage ( "������.bmp")  ;


    txBitBlt (txDC(), 0, 0, 800, 600, HOUSE, 0, 0);

    txBitBlt (txDC(), 0, 0, 900, 700, DOG, 0, 0);




}
