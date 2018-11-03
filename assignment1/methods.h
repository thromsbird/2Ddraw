//#ifdef METHODS_H
//#define METHODS_H

#include <iostream>
using namespace std;
//Bresenham 算法画直线段
void Draw_Line(HDC hdc, int x1, int y1, int x2, int y2);
//使用正负法画圆
void Draw_Circle(HDC hdc, int r, int x0, int y0);
//使用中点算法画椭圆
void Draw_Ellipse(HDC hdc, int x0, int y0, int a, int b);
//四连通域（内点表示）颜色填充漫水算法
void Flood_Fill_4(HDC hdc, int x, int y, COLORREF old_color, COLORREF new_color);
//阴影线填充算法
void Shadow_Fill(HDC hdc);
//一键绘制固定图形及颜色填充
void Show_Shape(HDC hdc);

//#endif