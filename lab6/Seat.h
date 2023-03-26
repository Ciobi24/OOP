#pragma once
#include "Car.h"
class Seat :
    public Car
{
public:
	Seat();
	double getFuel() override;
	double getConsumption() override;
	int getSpeed(Weather w) override;
	bool isFinished() override;
	void printName() override;
};

