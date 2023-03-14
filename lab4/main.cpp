#include "Sort.h"

int v[] = { 2,5,1,7 };
char s[20];
int main()
{
    Sort p = { 1,4,7,2 };
	Sort c1(v, 4);
	Sort c2(5, 1, 10);
	strcpy(s, (const char*)"10,2,3,25");
	Sort c3(s);
	p.Print();
	c1.Print();
	c2.Print();
	c3.Print();
	cout << endl << endl;
	c1.BubbleSort();
	c2.InsertSort();
	c3.QuickSort();
	c1.Print();
	c2.Print();
	c3.Print();
}
