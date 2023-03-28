#pragma once
#include "Car.h"

class Fiat :
    public Car
{
public:
	Fiat();
	double getFuel() override;
	double getConsumption() override;
	int getSpeed(Weather w) override;
	bool isFinished() override;
	void printName() override;
};

