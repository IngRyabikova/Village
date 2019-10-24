
#include "TXLib.h"







        void draw_car(int x)
        {
    x = x - 75;
    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(237, 38, 28));
    txRectangle(75 + x, 190, 170 + x, 225);
    txRectangle(212 + x, 150, 170 + x, 225);
    txRectangle(212 + x, 180, 260 + x, 225);


    txSetColor(RGB(153, 217, 234), 6);
    txSetFillColor(RGB(153, 217, 234));
    txRectangle(175 + x, 155, 206 + x, 185);

    txSetColor(RGB(255, 240, 0), 6);
    txSetFillColor(RGB(255, 240, 0));
    txRectangle(253 + x, 198, 260 + x, 205);


    txSetColor(RGB(0, 0, 0), 6);
    txSetFillColor(RGB(195, 195, 195));
    txCircle(105 + x, 235, 18);

    txSetColor(RGB(0, 0, 0), 6);
    txSetFillColor(RGB(195, 195, 195));
    txCircle(230 + x, 235, 18);

}

        void draw_doroga()
        {
     txSetColor(RGB(255, 255, 255), 5);
     txLine(20, 280, 85, 280);
     txLine(150, 280, 215, 280);
     txLine(280, 280, 345, 280);
     txLine(410, 280, 475, 280);
     txLine(540, 280, 605, 280);
     txLine(670, 280, 735, 280);
     txLine(800, 280, 865, 280);
     txLine(930, 280, 995, 280);

        }

        void draw_fon()
        {
        txSetColor(RGB(122, 122, 122), 6);
     txSetFillColor(RGB(162, 162, 162));
     txRectangle(-5, 365, 1300, 210);

     txSetColor(RGB(35, 180, 80), 6);
     txSetFillColor(RGB(35, 180, 80));
     txRectangle(-5, 60, 1300, 206);

     txRectangle(-5, 370, 1200, 800);

     txSetColor(RGB(100, 200, 225), 6);
     txSetFillColor(RGB(100, 200, 225));
     txRectangle(0, 60, 1200, 0);

     txSetColor(RGB(255, 200, 15), 6);
     txSetFillColor(RGB(255, 200, 15));
     txCircle(1000, 0, 25);
        }

        void draw_cloud(int x)
        {

            txSetColor(RGB(255, 255, 255), 8);
            txSetFillColor(RGB(255, 255, 255));
            txCircle(125 + x, 22, 10);
            txCircle(150 + x, 22, 18);
            txCircle(175 + x, 22, 10);

        }

        void draw_Gruzovik(int x)
        {
    x = x - 500;

    txSetColor(RGB(0, 0, 0), 8);
    txSetFillColor(RGB(255, 255, 255));
    txRectangle(605 + x, 205, 940 + x, 290);


    txSetColor(RGB(35, 41, 130), 8);
    txSetFillColor(RGB(35, 41, 130));
    txRectangle(650 + x, 285, 585 + x, 300);

    txSetColor(RGB(35, 41, 130), 8);
    txSetFillColor(RGB(65, 72, 205));
    txRectangle(512 + x, 235, 580 + x, 300);
    txLine(512 + x, 235, 533 + x, 207);
    txLine(580 + x, 207, 533 + x, 207);
    txLine(580 + x, 207, 580 + x, 300);
    //залить линии



    txSetColor(RGB(153, 217, 234), 8);
    txSetFillColor(RGB(153, 217, 234));
    txRectangle(560  + x, 250, 510 + x, 234);


     txSetColor(RGB(0, 0, 0), 6);
     txSetFillColor(RGB(195, 195, 195));
     txCircle(548 + x, 305, 18);
     txCircle(625 + x, 305, 18);
     txCircle(800 + x, 305, 18);
     txCircle(835 + x, 305, 18);
     txCircle(870 + x, 305, 18);
}

        void draw_Home(int x)
        {
   txSetColor(RGB(176, 106, 72), 6);
    txSetFillColor(RGB(160, 100, 65));
    txRectangle(345 + x, 185, 505 + x, 60);


    txSetColor(RGB(153, 217, 234), 6);
    txSetFillColor(RGB(153, 217, 234));
    txRectangle(440 + x, 108, 480 + x, 145);


   txSetColor(RGB(176, 106, 72), 6);
    txSetFillColor(RGB(160, 100, 65));
    txRectangle(365 + x, 112, 405 + x, 180);


    txSetColor(RGB(223, 192, 176), 4);
    txSetFillColor(RGB(237, 28, 36));

    POINT krysa[3] = {
        {505 + x, 60},
        {426 + x, -30},
        {345 + x, 60}
    };
    txPolygon (krysa, 3);
}

        void draw_BlueCar(int x)
        {
            txSetColor(RGB(0, 0, 0), 0.5);
            txSetFillColor(RGB(63, 72, 204));
            txRectangle(730 + x, 270, 925 + x, 305);




            txSetColor(RGB(63, 72, 204), 4);
            txLine(780 + x, 250, 795 + x, 250);//275 не робит???
            txLine(890 + x, 275, 880 + x, 250);
            txLine(890 + x, 275, 780 + x, 275);//275 не робит???




            txSetColor(RGB(0, 0, 0), 6);
            txSetFillColor(RGB(195, 195, 195));
            txCircle(772 + x, 310, 15);
            txCircle(890 + x, 310, 15);



        }

        void draw_Autobus(int x)
        {

        txSetColor(RGB(255, 200, 15), 6);
        txSetFillColor(RGB(213, 165, 0));
        txRectangle(90 + x, 185, 337 + x, 250);
       txRectangle(370 + x, 215, 337 + x, 250);


        txSetColor(RGB(255, 240, 0), 6); //окно
        txSetFillColor(RGB(40, 163, 193));
        txRectangle(265 + x, 200, 245 + x, 220);
        txRectangle(245 + x, 200, 225 + x, 220);
        txRectangle(225 + x, 200, 205 + x, 220);
        txRectangle(205 + x, 200, 185 + x, 220);
        txRectangle(185 + x, 200, 165 + x, 220);
        txRectangle(165 + x, 200, 145 + x, 220);
        txRectangle(145 + x, 200, 125 + x, 220);
        txRectangle(125 + x, 200, 105 + x, 220);







        txSetColor(RGB(255, 240, 0), 6);
        txSetFillColor(RGB(40, 163, 193));
        txRectangle(305 + x, 195, 275 + x, 245);
        txLine(275 + x, 222, 303 + x, 222);
        txLine(290 + x, 196, 290 + x, 245);


        txSetColor(RGB(78, 190, 218), 6);
        txSetFillColor(RGB(40, 163, 193));
        txRectangle(312 + x, 194, 334 + x, 212);








        txSetColor(RGB(0, 0, 0), 6);
        txSetFillColor(RGB(195, 195, 195));
        txCircle(120 + x, 250, 14);


        txSetColor(RGB(0, 0, 0), 6);
        txSetFillColor(RGB(195, 195, 195));
        txCircle(334 + x, 250, 14);


        }

        void draw_Human(int x, int y)
        {
    txSetColor(RGB(237, 28, 36), 6);
    txSetFillColor(RGB(237, 28, 36));
    txLine(384 + x -385, 185 + y -160, 384 + x -385, 155 + y -160);
    txLine(385 + x -385, 160 + y -160, 393 + x -385, 171 + y -160);
    txLine(385 + x -385, 160 + y -160, 374 + x -385, 171 + y -160);
    txLine(384 + x -385, 185 + y -160, 390 + x -385, 197 + y -160);
    txLine(384 + x -385, 185 + y -160, 377 + x -385, 197 + y -160);
    txCircle(384 + x -385, 148 + y -160, 9);
}

        void drawWindow(int x)
        {
    x = x - 415;
    txSetColor(RGB(0, 0, 0), 3);
    txSetFillColor(RGB(129, 208, 228));
    txRectangle(415 + x, 105, 455 + x, 170);
    txLine(435 + x, 105, 435 + x, 170);
    txLine(415 + x, 125, 455 + x, 125);
    txLine(415 + x, 145, 455 + x, 145);
}

        void draw_School(int x)
        {
    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(237, 28, 36));
    txRectangle(550 + x, 60, 815 + x, 200);
    txRectangle(550 + x, 75, 407 + x, 200);
    txRectangle(815 + x, 75, 962 + x, 200);


    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(240, 230, 175));
    txRectangle(406 + x, 200, 962 + x, 204);
    txRectangle(646 + x, 194, 719 + x, 198);
    txRectangle(640 + x, 198, 726 + x, 202);
    txRectangle(635 + x, 202, 732 + x, 206);

    txRectangle(648 + x, 193, 654 + x, 150);
    txRectangle(710 + x, 193, 716 + x, 150);
    txRectangle(642 + x, 146, 721 + x, 153);

    txRectangle(656 + x, 147, 660 + x, 141);
    txRectangle(703 + x, 147, 707 + x, 141);


    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(255, 200, 15));
    txRectangle(651 + x, 141, 713 + x, 126);


    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(255, 200, 15));
    txRectangle(670 + x, 160, 713 + x, 126);



    drawWindow(415);
    drawWindow(460);
    drawWindow(505);

    drawWindow(822);
    drawWindow(870);
    drawWindow(917);



    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(255, 127, 39));
    txRectangle(816 + x, 75, 975 + x, 82);
    txRectangle(550 + x, 75, 400 + x, 82);
    txRectangle(546 + x, 60, 826 + x, 56);
    txRectangle(565 + x, 13, 806 + x, 8);
    txLine(975 + x, 75, 955 + x, 40);
    txLine(400 + x, 75, 425 + x, 40);
    txRectangle(957 + x, 40, 820 + x, 44);
    txRectangle(423 + x, 40, 548 + x, 44);
    txLine(548 + x, 56, 565 + x, 16);
    txLine(824 + x, 56, 805 + x, 16);
}


        void draw_Derevo(int x)
        {

        txSetColor(RGB(0, 0, 0), 1);
        txSetFillColor(RGB(172, 107, 72));
        txRectangle(730 + x, 530, 755 + x, 390);

        txSetColor(RGB(0, 0, 0), 1);
        txSetFillColor(RGB(27, 137, 60));
        Win32::RoundRect (txDC(), 813 + x, 410, 670 + x, 200, 130, 130);


        }


        void drawBackgroundScene1(int x_cloud2, int x_Home, int x_Derevo )
        {
    txBegin();

    draw_fon();
    draw_doroga();
    draw_cloud(x_cloud2);
    draw_Home(x_Home);
    draw_Derevo(x_Derevo);

        }

int main()
{
    txCreateWindow (1000, 600);

    int x_cloud2 = 760;
    int x_Gruzovik = 500;
    int x_car = -1000;
    int x_BlueCar = 1400;
    int x_Autobus = -700;
    int x_Home = 400;
    int x_School = -500;
    int x_Derevo = 750;


    //Едет все
    while (x_cloud2 > 430)
    {
        txBegin();

        draw_fon();
        draw_doroga();

        draw_cloud(x_cloud2);
        draw_Home(0);



        draw_BlueCar(x_BlueCar);
        draw_car(x_car);
        draw_Gruzovik(x_Gruzovik);

        draw_Derevo(x_Derevo);


        x_cloud2 -= 4;
        x_Gruzovik -= 20;
        x_car += 30;
        x_BlueCar -= 30;


        txSleep(20);
        txEnd();
    }

    //Едет автобус
    while (x_cloud2 > 400)
    {
        drawBackgroundScene1(x_cloud2, 0);
        draw_Autobus(x_Autobus);


        x_cloud2 -= 4;
        x_Autobus += 20;

        txSleep(20);
        txEnd();
    }

    while (x_Autobus < -10)
    {
        drawBackgroundScene1(x_cloud2, x_Home, x_Derevo 0);
        draw_Autobus(x_Autobus);

        x_cloud2 -= 4;
        x_Autobus += 20;

        txSleep(20);
        txEnd();
    }


    int x_Human = 385;
    int y_Human = 140;
    while (y_Human < 220)
    {
        drawBackgroundScene1(x_cloud2, x_Home, x_Derevo 0);
        draw_Autobus(x_Autobus);
        draw_Human(x_Human, y_Human);

        x_cloud2 -= 4;
        y_Human += 6;

        txSleep(20);
        txEnd();
    }

    while (x_Human > 300)
    {
        drawBackgroundScene1(x_cloud2, x_Home, x_Derevo 0);
        draw_Autobus(x_Autobus);
        draw_Human(x_Human, y_Human);

        x_cloud2 -= 4;
        x_Human -= 6;

        txSleep(20);
        txEnd();
    }

    while (y_Human > 194)
    {
        drawBackgroundScene1(x_cloud2, x_Home, x_Derevo 0);
        draw_Autobus(x_Autobus);
        draw_Human(x_Human, y_Human);

        x_cloud2 -= 4;
        y_Human -= 3;

        txSleep(20);
        txEnd();
    }


    while (y_Human > 194)
    {
        drawBackgroundScene1(x_cloud2, x_Home, x_Derevo 0);
        draw_Autobus(x_Autobus);


        x_cloud2 -= 4;


        txSleep(20);
        txEnd();
    }



    txSleep(1000);


      while (x_Autobus < 280)
    {
        drawBackgroundScene1(x_cloud2, x_Home, x_Derevo 0);
        draw_Autobus(x_Autobus);


        x_cloud2 -= 4;
        x_Autobus  +=20;


        txSleep(20);
        txEnd();
    }



      while (x_School < 400)
    {
        txBegin();
        draw_fon();
        draw_doroga();
        draw_cloud(x_cloud2);
        draw_School(x_School);
        draw_Home(x_Home);
        draw_Autobus(x_Autobus);
        draw_Derevo(x_Derevo);



        x_cloud2 -=24;
        x_Home   -=20;
        x_School -=20;
        x_Derevo -=20;

        txSleep(20);
        txEnd();
    }

    return 0;
}
