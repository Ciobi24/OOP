#include "BMW.h"
BMW::BMW() {
	fuel_capacity = 40;
	consumption = 6;
	rainspeed = 180;
	sunnyspeed = 200;
	snowspeed = 160;
	name = new char[4];
	const char* x = "BMW";
	int i;
	for (i = 0; i < 3; i++)
		name[i] = x[i];
	name[i] = '\0';
}
double BMW::getFuel() {
	return fuel_capacity;
}
double BMW::getConsumption() {
	return consumption;
}
int BMW::getSpeed(Weather w) {
	if (w == Sunny)return sunnyspeed;
	if (w == Rain)return rainspeed;
	return snowspeed;
}
bool BMW::isFinished()
{
	return f.finished;
}

void BMW::printName()
{
	cout << name;
}