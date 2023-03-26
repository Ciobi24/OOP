#include "Seat.h"
Seat::Seat() {
	fuel_capacity = 30;
	consumption = 6;
	rainspeed = 140;
	sunnyspeed = 155;
	snowspeed = 100;
	name = new char[5];
	const char* x = "Seat";
	int i;
	for (i = 0; i < 4; i++)
		name[i] = x[i];
	name[i] = '\0';
}
double Seat::getFuel() {
	return fuel_capacity;
}
double Seat::getConsumption() {
	return consumption;
}
int Seat::getSpeed(Weather w) {
	if (w == Sunny)return sunnyspeed;
	if (w == Rain)return rainspeed;
	return snowspeed;
}
bool Seat::isFinished()
{
	return finished;
}

void Seat::printName()
{
	cout << name;
}