#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string>
#include <iostream>
#include<cmath>
using namespace std;

class Number
{
	char* value;
	int base;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& other);//copy 
	Number(Number&& other);//move
	Number(int val);
	~Number();

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

	Number& operator = (const Number& other);
	friend Number operator + (Number n1, Number n2);
	friend Number operator - (Number n1, Number n2);
	bool operator> (Number n);
	bool operator< (Number n);
	bool operator<= (Number n);
	bool operator>= (Number n);
	bool operator== (Number n);
	Number& operator--();
	Number& operator--(int);
	void operator+=(Number n);
	void operator=(int nr);
	void operator=(const char* nr);
	char operator[](int index);
};

