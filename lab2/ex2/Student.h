#pragma once
class Student
{
	char name[20];
	float math, eng, history;

public:
	void SetName(const char* s);
	const char* GetName() const;
	void SetMath(float m);
	float GetMath() const;
	void SetEng(float e);
	float GetEng() const;
	void SetHistory(float h);
	float GetHistory() const;
	float Average() const;
};