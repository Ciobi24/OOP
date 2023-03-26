#pragma once
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Volvo.h"
#include "Fiat.h"

class Circuit
{

	Weather weather;
	int length;
	Car** cars;
	int n;

public:
	Circuit();
	~Circuit();
	void SetLength(int l);
	void SetWeather(Weather weather);
	Weather GetWeather();
	void AddCar(Car *car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	friend int Car::getSpeed(Weather w);
};

