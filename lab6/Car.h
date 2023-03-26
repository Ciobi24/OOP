#pragma once
#include <iostream>
#include "Weather.h"
using namespace std;

class Car
{
protected:
	double fuel_capacity;
	double consumption;
	int rainspeed;
	int sunnyspeed;
	int snowspeed;
	char* name;
public:
	double race_time;
	bool finished;

	virtual double getFuel();
	virtual double getConsumption();
	virtual int getSpeed(Weather w);
	virtual bool isFinished();
	virtual void printName();
};

