#include "Student.h"
#include <cstring>
#include <cstdio>

char* const Student::GetName()
{
	return this->name;
}

float const Student::GetMathGrade()
{
	return this->mathGrade;
}
float const Student::GetEnglishGrade()
{
	return this->englishGrade;
}
float const Student::GetHistoryGrade()
{
	return this->historyGrade;
}
float const Student::GetAverageGrade()
{
	return (this->mathGrade + this->historyGrade + this->englishGrade) / 3.0f;
}

void Student::SetName(const char* newName)
{
	int i;
	for ( i = 0; newName[i] != NULL; i++)
	{
		this->name[i] = newName[i];
	}
	this->name[i] = NULL;
}
void Student::SetMathGrade(float newGrade)
{
	if (newGrade > 10 || newGrade < 1)
	{
		printf("%.2f%s%s", newGrade, " is not a valid grade for ", this->name);
		return;
	}

	this->mathGrade = newGrade;
}
void Student::SetEnglishGrade(float newGrade)
{
	if (newGrade > 10 || newGrade < 1)
	{
		printf("%.2f%s%s", newGrade, " is not a valid grade for ", this->name);
		return;
	}

	this->englishGrade = newGrade;
}
void Student::SetHistoryGrade(float newGrade)
{
	if (newGrade > 10 || newGrade < 1)
	{
		printf("\n%.2f%s%s", newGrade, " is not a valid grade for ", this->name);
		return;
	}

	this->historyGrade	 = newGrade;
}