//#ifdef METHODS_H
//#define METHODS_H

#include <iostream>
using namespace std;
//Bresenham �㷨��ֱ�߶�
void Draw_Line(HDC hdc, int x1, int y1, int x2, int y2);
//ʹ����������Բ
void Draw_Circle(HDC hdc, int r, int x0, int y0);
//ʹ���е��㷨����Բ
void Draw_Ellipse(HDC hdc, int x0, int y0, int a, int b);
//����ͨ���ڵ��ʾ����ɫ�����ˮ�㷨
void Flood_Fill_4(HDC hdc, int x, int y, COLORREF old_color, COLORREF new_color);
//��Ӱ������㷨
void Shadow_Fill(HDC hdc);
//һ�����ƹ̶�ͼ�μ���ɫ���
void Show_Shape(HDC hdc);

//#endif