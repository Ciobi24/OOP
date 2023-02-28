#include "NumberList.h"
#include "NumberListVariabil.h"
#include "GlobalFunctions.h";
#include "Student.h";
#include "Grupa.h";

#include <cstdio>

#pragma region Problema 1
int mainProblema1() 
{
	NumberList x;
	x.Init();
	x.Add(4);
	x.Add(2);
	x.Add(7);
	x.Add(9);
	x.Add(1);
	x.Add(3);
	x.Add(6);
	x.Add(5);
	x.Add(8);

	x.Print();//before sort

	x.Sort();

	x.Print();///after sort

	return 0;
}
#pragma endregion	

#pragma region Problema 2
int mainProblema2()
{
	Student bread;
	Student fred;

	bread.SetName("Bread");
	fred.SetName("Fred");

	bread.SetEnglishGrade(10);
	bread.SetMathGrade(5);
	bread.SetHistoryGrade(2);
	
	fred.SetEnglishGrade(6);
	fred.SetMathGrade(10);
	fred.SetHistoryGrade(8);

	printf("%d", CompName(bread, fred));
	printf("%d", CompEnglishGrade(bread, fred));
	printf("%d", CompMathGrade(bread, fred));
	printf("%d", CompHistoryGrade(bread, fred));
	printf("%d", CompAverageGrade(bread, fred));

	fred.SetHistoryGrade(100);

	return 0;
}
#pragma endregion

#pragma region Problema1 Size Variabil
int mainProblema3()
{
	NumberListVariabil x;
	x.Init();
	for (int i = 1; i <= 11; i++)
		x.Add(i);

	x.Print();///after sort

	return 0;
}
#pragma endregion

#pragma region Problema2 Grupa Studenti
int mainProblema4()
{
	Grupa x;
	x.Init();
	for (int i = 9; i >= 1; i--)
	{
		Student a;

		char* nume = new char[2];
		nume[0] = '0' + i;
		nume[1] = NULL;
		a.SetName(nume);

		a.SetEnglishGrade(i);
		a.SetMathGrade(i);
		a.SetHistoryGrade(i);
		
		x.Add(a);
	}

	x.SortAverage();
	x.Print();

	return 0;
}
#pragma endregion


int main()
{
	//mainProblema1();
	//mainProblema2();
	//mainProblema3();
	mainProblema4();
	return 0;
}