#include "Student.h"
#include <cstring>
#include <iostream>
void Student :: SetName(const char *s)
{
	strcpy(name, s);
}
const char* Student :: GetName() const
{
	return name;
}
void Student :: SetMath(float m)
{
	if(m>=1&&m<=10)
	math = m;
}
float Student :: GetMath() const
{
	return math;
}
void Student :: SetEng(float e)
{
	if(e>=1&&e<=10)
	eng = e;
}
float Student::GetEng() const
{
	return eng;
}
void Student :: SetHistory(float h)
{
	if(h>=1&&h<=10)
	history = h;
}
float Student :: GetHistory() const
{
	return history;
}
float Student::Average() const
{
	return (math + eng + history) / 3.0;
}