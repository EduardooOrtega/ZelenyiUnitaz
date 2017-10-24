#include <iostream>
#include "Lib\\TXLib.h"

/*
1) ��������� ��� ������ (� ������� ���� ��� � ��������)
2) ���������� ����
3) ������� ������� �� ������ ��������
4) �������� ������ �������� �� ������� �� ������ ������
*/

using namespace std;

struct Mebel {
    int x;   //������������ �� x
    int y;   //������������ �� y
    int o;   //��� ������� (����, ����)
    int v;   //��� ������� (������� ����, ��������� ����)
};

const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

int mode = GAME_MODE;

void draw_button(int x, int y, const char* text)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(x, y,400,100);
    txTextOut(x + 40, y + 40, text);
}

void Level_1 (HDC TV, HDC Chair, HDC Table, HDC Bed)
{
      txBitBlt (txDC(), 200, 200, 30, 30, TV);
      txBitBlt (txDC(), 200, 400, 30, 30, TV);
      txBitBlt (txDC(), 400, 200, 30, 30, TV);
      txBitBlt (txDC(), 300, 200, 30, 30, Chair);
      txBitBlt (txDC(), 200, 300, 30, 30, Chair);
      txBitBlt (txDC(), 300, 300, 30, 30, Chair);
      txBitBlt (txDC(), 600, 200, 30, 30, Table);
}



void btn_click (int x, int y, int xx, int yy, int* risovatKartinku)
{
    if (txMouseButtons() & 1
        && txMouseX() >= x
        && txMouseX() <= y
        && txMouseY() >= xx
        && txMouseY() <= yy)
    {
        *risovatKartinku = - *risovatKartinku;
        txSleep(100);
    }

}

int main()
{

    txCreateWindow(800,720);


    int risovatKartinku = -1;
    HDC tv = txLoadImage ("Icons\\���������.bmp");

    int risovatKartinku2 = 1;
    HDC chair = txLoadImage ("Icons\\����.bmp");

    HDC  TV = txLoadImage ("Icons\\���������.bmp");
    HDC  Chair = txLoadImage ("Icons\\����.bmp");
    HDC  Table = txLoadImage ("Icons\\����.bmp");
    HDC  Bed = txLoadImage ("Icons\\�������.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        draw_button(0, 0, "���������");
        draw_button(200, 0, "����");
        draw_button(400, 0, "����");

        btn_click (0,200,0,100, &risovatKartinku);      //0 200 0 100
        btn_click(200,200,0,100, &risovatKartinku2 );

        Level_1 (TV, Chair, Table, Bed) ;

        if (risovatKartinku == 1)
        {
            txBitBlt (txDC(), 500, 500, 30, 30, tv, 0, 0);
        }

         if (risovatKartinku2 == 1)
        {
            txBitBlt (txDC(), 500, 600, 30, 30, chair, 0, 0);
        }

        txSleep (10);
        txEnd();
    }


    txDeleteDC (tv);
    txDeleteDC (chair);

    txDeleteDC (TV);
    txDeleteDC (Chair);
    txDeleteDC (Table);
    txDeleteDC (Bed);

    return 0;
}
