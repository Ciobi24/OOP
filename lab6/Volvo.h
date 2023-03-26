#pragma once
#include "Car.h"
class Volvo :
    public Car
{
public:
	Volvo();
	double getFuel() override;
	double getConsumption() override;
	int getSpeed(Weather w) override;
	bool isFinished() override;
	void printName() override;
};

