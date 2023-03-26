#pragma once
#include "Car.h"
class RangeRover :
    public Car
{
public:
	RangeRover();
	double getFuel() override;
	double getConsumption() override;
	int getSpeed(Weather w) override;
	bool isFinished() override;
	void printName() override;

};

