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

	virtual double getFuel() { return fuel_capacity; }
	virtual double getConsumption() { return consumption; }
	virtual int getSpeed(Weather w) { return 0; }
	virtual bool isFinished() { return finished; }
	virtual void printName(){}
};

