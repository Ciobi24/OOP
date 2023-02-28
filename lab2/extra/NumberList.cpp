#include "NumberList.h";

#include <cstdio>
#include <utility>

using namespace std;

void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if(this->count >= 10)
		return false;

	this->numbers[this->count++] = x;
	return true;
}
void RecursiveQuickSort(int begin, int end, int v[])
{
	if (begin >= end)
		return;
	int pivot = v[begin];

	int i = begin+1;
	int j = end;

	while (i <= j)
	{
		if (v[i] <= pivot)
			i++;
		if (v[j] >= pivot)
			j--;
		if (v[i] > pivot && v[j] < pivot && i<j)
		{
			swap(v[i], v[j]);
			i++;
			j--;

		}
	}
	if(v[begin] > v[j])
	swap(v[begin], v[j]);

	RecursiveQuickSort(begin, j - 1,v);
	RecursiveQuickSort(j+1, end,v);

}
void NumberList::Sort()
{
	RecursiveQuickSort(0, this->count-1, this->numbers);
}
void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d", this->numbers[i]);
	printf("\n");
		
}