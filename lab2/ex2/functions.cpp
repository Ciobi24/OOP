#include "functions.h"
#include <cstring>
int CompName(Student s1, Student s2)
{
	return strcmp(s1.GetName(), s2.GetName());
}
int CompMath(Student s1, Student s2)
{
	if (s1.GetMath() == s2.GetMath())
		return 0;
	else if (s1.GetMath() > s2.GetMath())
		return 1;
	else return -1;
}
int CompEng(Student s1, Student s2)
{
	if (s1.GetEng() == s2.GetEng())
		return 0;
	else if (s1.GetEng() > s2.GetEng())
		return 1;
	else return -1;
}
int CompHistory(Student s1, Student s2)
{
	if (s1.GetHistory() == s2.GetHistory())
		return 0;
	else if (s1.GetHistory() > s2.GetHistory())
		return 1;
	else return -1;
}
int CompAverage(Student s1, Student s2)
{
	if (s1.Average() == s2.Average())
		return 0;
	else if (s1.Average() > s2.Average())
		return 1;
	else return -1;
}