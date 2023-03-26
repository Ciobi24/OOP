#pragma once
#include "Car.h"
class BMW :
    public Car
{
public:
	BMW();
	double getFuel() override;
	double getConsumption() override;
	int getSpeed(Weather w) override;
	bool isFinished() override;
	void printName() override;
};

