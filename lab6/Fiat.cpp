#include "Fiat.h"
Fiat::Fiat() {
	fuel_capacity = 15;
	consumption = 5.9;
	rainspeed = 140;
	sunnyspeed = 165;
	snowspeed = 110;
	name = new char[5];
	const char* x = "Fiat";
	int i;
	for (i = 0; i < 4; i++)
		name[i] = x[i];
	name[i] = '\0';
}
double Fiat::getFuel() {
	return fuel_capacity;
}
double Fiat::getConsumption() {
	return consumption;
}
int Fiat::getSpeed(Weather w) {
	if (w == Sunny)return sunnyspeed;
	if (w == Rain)return rainspeed;
	return snowspeed;
}
bool Fiat::isFinished()
{
	return finished;
}

void Fiat::printName()
{
	cout << name;
}