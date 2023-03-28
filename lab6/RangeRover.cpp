#include "RangeRover.h"
RangeRover::RangeRover() {
	fuel_capacity = 45;
	consumption = 6.2;
	rainspeed = 190;
	sunnyspeed = 205;
	snowspeed = 180;
	name = new char[11];
	const char* x = "RangeRover";
	int i;
	for (i = 0; i < 10; i++)
		name[i] = x[i];
	name[i] = '\0';
}
double RangeRover::getFuel() {
	return fuel_capacity;
}
double RangeRover::getConsumption() {
	return consumption;
}
int RangeRover::getSpeed(Weather w) {
	if (w == Sunny)return sunnyspeed;
	if (w == Rain)return rainspeed;
	return snowspeed;
}
bool RangeRover::isFinished()
{
	return f.finished;
}

void RangeRover::printName()
{
	cout << name;
}