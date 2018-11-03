
#include "stdafx.h"
#include "resource.h"

#include <iostream>
using namespace std;

//Bresenham �㷨��ֱ�߶�
void Draw_Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	
	int x;//��ǰλ��
	int y;
	int deltax;//x��y�����ϵĸı���
	int deltay;
	int e;//�б���

	if (x2 > x1) {
		if (y2 >= y1) {//б�ʴ���1�����
			deltax = x2 - x1;//����б�ʼ���
			deltay = y2 - y1;
			e = -deltax;
			x = x1;
			y = y1;

			for (int i = 0; i <= deltax; i++) {
				SetPixel(hdc, x, y, RGB(0, 0, 0));//����
				if (e >= 0) {//����e����ֵ
					y = y + 1;
					e = e - 2 * deltax;
				}
				else {
					x = x + 1;
					e = e + 2 * deltay;
				}
			}
		}
		else {//б��С��-1�����
			deltax = x2 - x1;
			y2 = 2 * y1 - y2;//deltay�൱��y1-y2
			deltay = y2 - y1;
			e = -deltax;
			x = x1;
			y = y1;

			for (int i = 0; i <= deltax; i++) {
				SetPixel(hdc, x, 2 * y1 - y, RGB(0, 0, 0));//����
				if (e >= 0) {//����e����ֵ
					y = y + 1;
					e = e - 2 * deltax;
				}
				else {
					x = x + 1;
					e = e + 2 * deltay;
				}
			}
		}
	}
	else if(x2 < x1) {//��һ��б��С��-1�����
		if (y2 >= y1) {
			x2 = 2 * x1 - x2;
			deltax = x2 - x1;//deltax�൱��x1-x2
			deltay = y2 - y1;
			e = -deltax;
			x = x1;
			y = y1;

			for (int i = 0; i <= deltax; i++) {
				SetPixel(hdc, 2 * x1 - x, y, RGB(0, 0, 0));//����
				if (e >= 0) {//����e����ֵ
					y = y + 1;
					e = e - 2 * deltax;
				}
				else {
					x = x + 1;
					e = e + 2 * deltay;
				}
			}
		}
		else {//��һ��б�ʴ���1�����
			std::swap(x1, x2);
			std::swap(y1, y2);
			deltax = x2 - x1;
			deltay = y2 - y1;
			e = -deltax;
			x = x1;
			y = y1;

			for (int i = 0; i <= deltax; i++) {
				SetPixel(hdc, x, y, RGB(0, 0, 0));//����
				if (e >= 0) {//����e����ֵ
					y = y + 1;
					e = e - 2 * deltax;
				}
				else {
					x = x + 1;
					e = e + 2 * deltay;
				}
			}
		}
	}
	else {
		if (y2 > y1)
		{
			deltay = y2 - y1;
			x = x1;
			for (int i = 0; i <= deltay; i++)
				SetPixel(hdc, x, y1 + i, RGB(0, 0, 0));//����
		}
		else 
		{
			deltay = y1 - y2;
			x = x1;
			for (int i = 0; i <= deltay; i++)
				SetPixel(hdc, x, y1 - i, RGB(0, 0, 0));//����
		}
	}

}

//ʹ����������Բ
void Draw_Circle(HDC hdc, int r, int x0, int y0)
{
	
	int x, y, f;//(x,y)Ϊ��ǰ���� fΪ���ֵ
	x = x0;
	y = y0 + r;
	f = 0;

	while (y >= y0) {//��Բ�ܵ����ϲ��ֿ�ʼ
		SetPixel(hdc, x, y, RGB(0, 0, 0));//�ԳƵػ����ĸ������ڵ������
		SetPixel(hdc, 2 * x0 - x, y, RGB(0, 0, 0));
		SetPixel(hdc, x, 2 * y0 - y, RGB(0, 0, 0));
		SetPixel(hdc, 2 * x0 - x, 2 * y0 - y, RGB(0, 0, 0));

		if (f > 0) {
			f = f - 2 * (y - y0) + 1;
			y--;//��Բ����
		}
		else {
			f = f + 2 * (x - x0) + 1;
			x++;//��Բ����
		}
	}

	if (y == y0)
		SetPixel(hdc, x, y, RGB(0, 0, 0));
}

//ʹ���е��㷨����Բ
void Draw_Ellipse(HDC hdc, int x0, int y0, int a, int b)
{
	
	int a1 = a * a, b1 = b * b;
	int a2 = 2 * a1, b2 = 2 * b1;
	int x = 0, y = b;
	int d;
	int dx = 0, dy = a2 * y;

	d = int(b1 + a1 * (-b + 0.25) + 0.5);

	SetPixel(hdc, x0 + x, y0 + y, RGB(0, 0, 0));
	SetPixel(hdc, x0 - x, y0 + y, RGB(0, 0, 0));
	SetPixel(hdc, x0 + x, y0 - y, RGB(0, 0, 0));
	SetPixel(hdc, x0 - x, y0 - y, RGB(0, 0, 0));

	while (dx < dy) {
		x++;
		dx += b2;
		if (d < 0)
			d += b1 + dx;
		else {
			dy -= a2;
			d += b1 + dx - dy;
			y--;
		}
		SetPixel(hdc, x0 + x, y0 + y, RGB(0, 0, 0));
		SetPixel(hdc, x0 - x, y0 + y, RGB(0, 0, 0));
		SetPixel(hdc, x0 + x, y0 - y, RGB(0, 0, 0));
		SetPixel(hdc, x0 - x, y0 - y, RGB(0, 0, 0));
	}
	d = int(b1 * (x + 0.5) * (x + 0.5) + a1 * (y - 1) * (y - 1) - a1 * b1 - 0.5);

	while (y > 0)
	{
		y--;
		dy -= a2;
		if (d > 0)
			d += a1 - dy;
		else {
			x++;
			dx += b2;
			d += a1 - dy + dx;
		}
		SetPixel(hdc, x0 + x, y0 + y, RGB(0, 0, 0));
		SetPixel(hdc, x0 - x, y0 + y, RGB(0, 0, 0));
		SetPixel(hdc, x0 + x, y0 - y, RGB(0, 0, 0));
		SetPixel(hdc, x0 - x, y0 - y, RGB(0, 0, 0));
	}
}

//����ͨ���ڵ��ʾ����ɫ�����ˮ�㷨
void Flood_Fill_4(HDC hdc, int x, int y, COLORREF old_color, COLORREF new_color)
{
	//������ʹ�ø�����ɫ������� 
	if ((GetPixel(hdc, x, y) != RGB(0, 0, 0))&(GetPixel(hdc, x, y) != new_color)) {
		SetPixel(hdc, x, y, new_color);//�����ǰ���ص��Ǿ���ɫ ����ı�Ϊ�������ɫ

		Flood_Fill_4(hdc, x, y + 1, old_color, new_color);//�ݹ������뵱ǰ�������ڵ��ĸ���
		Flood_Fill_4(hdc, x, y - 1, old_color, new_color);
		Flood_Fill_4(hdc, x - 1, y, old_color, new_color);
		Flood_Fill_4(hdc, x + 1, y, old_color, new_color);
		
	}
}

//��Ӱ������㷨
void Shadow_Fill(HDC hdc)
{
	int vertex[2][4];
	int distance[4];
	float cross[2][4];
	int k = 1;
	int dis_max = 0;
	int dis_min = 1000000;
	int dis;
	BOOL paint = true;

	/*vertex[0][0] = 100;//Ԥ�ø���������
	vertex[1][0] = 100;
	vertex[0][1] = 200;
	vertex[1][1] = 100;
	vertex[0][2] = 200;
	vertex[1][2] = 200;
	vertex[0][3] = 100;
	vertex[1][3] = 200;*/

	vertex[0][0] = 400;//Ԥ�ø���������
	vertex[1][0] = 200;
	vertex[0][1] = 500;
	vertex[1][1] = 200;
	vertex[0][2] = 500;
	vertex[1][2] = 300;
	vertex[0][3] = 400;
	vertex[1][3] = 200;
	for (int i = 0; i < 4; i++)//������߽ؾ�
		distance[i] = vertex[1][i] - vertex[0][i] * k;

	for (int i = 0; i < 4; i++) {//����ؾ�����ֵ����Сֵ
		if (distance[i] > dis_max)
			dis_max = distance[i];
		else if (distance[i] < dis_min)
			dis_min = distance[i];
	}

	dis = dis_min + 3;

	while (dis <= dis_max) {
		for (int i = 0; i < 4; i++) {//����Ӱ����ߵĽ���
			int j = (i + 1) % 4;

			if ((vertex[1][j] - vertex[1][i]) - k * (vertex[0][j] - vertex[0][i]) == 0)
				break;

			cross[0][i] = (vertex[1][j] * vertex[0][i] - vertex[1][i] * vertex[0][j]
				+ dis * (vertex[0][j] - vertex[0][i])) /
				((vertex[1][j] - vertex[1][i]) - k * (vertex[0][j] - vertex[0][i]));

			cross[1][i] = k * cross[0][i] + dis;
		}
		Draw_Line(hdc, cross[0][0], cross[1][0], cross[0][1], cross[1][1]);//����Ӱ��
		Draw_Line(hdc, cross[0][2], cross[1][2], cross[0][3], cross[1][3]);
		dis += 3;
	}
}

//һ�����ƹ̶�ͼ�μ���ɫ���
void Show_Shape(HDC hdc) {
	Draw_Line(hdc, 50, 50, 150, 150);
	Draw_Circle(hdc, 50, 200, 100);
	Draw_Ellipse(hdc, 350, 100, 70, 50);

	Draw_Line(hdc, 100, 200, 200, 200);
	Draw_Line(hdc, 200, 200, 200, 250);
	Draw_Line(hdc, 100, 200, 100, 250);
	Draw_Line(hdc, 100, 250, 200, 250);//���߶λ�һ������

	Flood_Fill_4(hdc, 150, 225, RGB(255, 255, 255), RGB(255, 0, 0));//�Ծ��ν����������
	Flood_Fill_4(hdc, 200, 100, RGB(255, 255, 255), RGB(0, 255, 0));//��Բ�����������
	Shadow_Fill(hdc);

}
