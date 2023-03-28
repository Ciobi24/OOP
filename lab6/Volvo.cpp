#include "Volvo.h"
Volvo::Volvo() {
	fuel_capacity = 30;
	consumption = 5.6;
	rainspeed = 150;
	sunnyspeed = 160;
	snowspeed = 120;
	name = new char[6];
	const char* x = "Volvo";
	int i;
	for (i = 0; i < 5; i++)
		name[i] = x[i];
	name[i] = '\0';
}
double Volvo::getFuel() {
	return fuel_capacity;
}
double Volvo:: getConsumption() {
	return consumption;
}
int Volvo::getSpeed(Weather w) {
	if (w == Sunny)return sunnyspeed;
	if (w == Rain)return rainspeed;
	return snowspeed;
}
bool Volvo:: isFinished()
{
	return f.finished;
 }

void Volvo::printName()
{
	cout << name;
}