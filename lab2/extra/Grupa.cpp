#include "Grupa.h"
#include "Student.h"
#include <utility>
#include <cstdio>

using namespace std;
void Grupa::Init()
{
	this->nrStudenti = 0;
}
void RecursiveQuickSort(int begin, int end, Student v[])
{
	if (begin >= end)
		return;
	float pivot = v[begin].GetAverageGrade();

	int i = begin + 1;
	int j = end;

	while (i <= j)
	{
		if (v[i].GetAverageGrade() <= pivot)
			i++;
		if (v[j].GetAverageGrade() >= pivot)
			j--;
		if (v[i].GetAverageGrade() > pivot && v[j].GetAverageGrade() < pivot && i < j)
		{
			swap(v[i], v[j]);
			i++;
			j--;
		}
	}
	if (v[begin].GetAverageGrade() > v[j].GetAverageGrade())
		swap(v[begin], v[j]);

	RecursiveQuickSort(begin, j - 1, v);
	RecursiveQuickSort(j + 1, end, v);

}
void Grupa::Add(Student x)
{
	this->students[this->nrStudenti++] = x;

}
void Grupa::SortAverage()
{
	RecursiveQuickSort(0, this->nrStudenti,this->students);
}
void Grupa::Print()
{
	for (int i = 0; i < this->nrStudenti; i++)
	{
		printf(this->students[i].GetName());
	}
}