#include "Circuit.h"
Circuit::Circuit() {
	weather = Sunny;
	length = 0;
	cars = new Car*[10];
	n = 0;
}
Circuit::~Circuit() {
	weather = Sunny;
	length = 0;
	for (int i = 0; i < n; i++) delete cars[i];
	delete[] cars;
	n = 0;
}
void Circuit::SetLength(int l) {
	this->length = l;
}
void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}
Weather Circuit:: GetWeather() {
	return weather;
}
void Circuit::AddCar(Car *car) {
	if(car!=nullptr)
	cars[n++] = car;
}

void Circuit::Race() {
	for (int i = 0; i < n; i++)
	{
		cars[i]->race_time = (double)length / cars[i]->getSpeed(this->weather) *60;
		if (cars[i]->getFuel() >= cars[i]->getConsumption() * length/100)
			cars[i]->f.finished = 1;
		else {
			cars[i]->f.finished = 0;
			cars[i]->f.stop = (double) cars[i]->getFuel() /(double) cars[i]->getConsumption()*100;
		}
	}
}
void Circuit::ShowFinalRanks() {
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if (cars[j]->race_time < cars[i]->race_time)
			{
				Car* aux;
				aux = cars[i];
				cars[i] = cars[j];
				cars[j] = aux;
			}
	Car** aux=new Car*[10];
	int k = 0;
	for (int i = 0; i < n; i++)
		if (cars[i]->f.finished == 1)
			aux[k++] = cars[i];
	for (int i = 0; i < n; i++)
		if (cars[i]->f.finished == 0)
			aux[k++] = cars[i];
	for (int i = 0; i < n; i++)
		cars[i] = aux[i];
	delete[] aux;
	for (int i = 0; i < n; i++)
	{
		
		cout << cars[i]->race_time << " ";
		cars[i]->printName(), cout << endl;
	}
}
void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < n; i++)
		if (cars[i]->isFinished() == 0)
			cars[i]->printName(), cout << " " << cars[i]->f.stop << endl;
}