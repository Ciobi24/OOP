#pragma once
#pragma warning (disable : 4996)
#include <cstdarg>
#include <cstring>
#include <iostream>
using namespace std;

class Sort

{
    int nr;
    int* l;


public:

    Sort(int count, int mini, int maxi);
    Sort(initializer_list<int> elements);
    Sort(const int v[], int count);
    Sort(int count, ...);
    Sort(const char* p);

    void quickSort(int low, int high, bool ascendent);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};
