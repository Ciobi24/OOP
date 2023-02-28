#pragma once
class Student 
{
private:
	char* name = new char;

	int mathGrade;
	int englishGrade;
	int historyGrade;

public:

	char* const GetName();
	
	float const GetMathGrade();
	float const GetEnglishGrade();
	float const GetHistoryGrade();
	float const GetAverageGrade();


	void SetName(const char* newName );
	void SetMathGrade(float newGrade );
	void SetEnglishGrade(float newGrade);
	void SetHistoryGrade(float newGrade);
};