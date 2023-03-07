#pragma once
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

class Canvas

{

private: 
    int h, w;
    char** mat;

public:

    Canvas(int width, int height);

    void DrawCircle(int x, int y, int ray, char ch);

    void FillCircle(int x, int y, int ray, char ch);

    void DrawRect(int left, int top, int right, int bottom, char ch);

    void FillRect(int left, int top, int right, int bottom, char ch);

    void SetPoint(int x, int y, char ch);

    void DrawLine(int x0, int y0, int x1, int y1, char ch);

    void Print(); // shows what was printed

    void Clear(); // clears the canvas

};
