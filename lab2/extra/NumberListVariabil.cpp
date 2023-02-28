#include "NumberListVariabil.h";
#include "NumberList.h"

#include <cstdio>
#include <utility>

using namespace std;

void NumberListVariabil::IncreaseSize(int additionalSize)
{
	printf("Increasing Size");
	int* newArray = new int[this->count + additionalSize];
	int* oldArray = this->numbers;

	for (int i = 0; i < this->count; i++)
	{
		newArray[i] = this->numbers[i];
	}

	delete oldArray;
	this->numbers = newArray;
}

void NumberListVariabil::Init()
{
	this->count = 0;
	this->numbers = new int[10];
}
bool NumberListVariabil::Add(int x)
{
	if (this->count >= 10)
	{
		this->IncreaseSize(10);
	}

	this->numbers[this->count++] = x;
	return true;
}
void NumberListVariabil::Sort()
{
	RecursiveQuickSort(0, this->count - 1, this->numbers);
}
void NumberListVariabil::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d", this->numbers[i]);
	printf("\n");

}