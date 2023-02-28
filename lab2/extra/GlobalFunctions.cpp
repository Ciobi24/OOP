#include "GlobalFunctions.h";
#include <cstring>


int CompName(Student stud1, Student stud2)
{
	int comp = strcmp(stud1.GetName(), stud2.GetName());

	if (comp == 0)
		return 0;
	else if (comp < 0)
		return -1;
	return 1;

}
int CompMathGrade(Student stud1, Student stud2)
{
	int diff = stud1.GetMathGrade() - stud2.GetMathGrade();
	if (diff == 0)
		return 0;
	else if (diff < 0)
		return -1;
	return 1;

}
int CompEnglishGrade(Student stud1, Student stud2)
{
	int diff = stud1.GetEnglishGrade() - stud2.GetEnglishGrade();
	if (diff == 0)
		return 0;
	else if (diff < 0)
		return -1;
	return 1;
}
int CompHistoryGrade(Student stud1, Student stud2)
{
	int diff = stud1.GetHistoryGrade() - stud2.GetHistoryGrade();
	if (diff == 0)
		return 0;
	else if (diff < 0)
		return -1;
	return 1;
}
int CompAverageGrade(Student stud1, Student stud2)
{
	int diff = stud1.GetAverageGrade() - stud2.GetAverageGrade();
	if (diff == 0)
		return 0;
	else if (diff < 0)
		return -1;
	return 1;
}