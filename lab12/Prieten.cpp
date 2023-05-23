#include "Prieten.h"

Prieten::Prieten(const string& date, const string& phone, const string& adress, const string& name) : date(date), phone(phone), adress(adress) { this->name = name; this->type = prieten; }

const string& Prieten::getDate()
{
	return this->date;
}

const string& Prieten::getPhone()
{
	return phone;
}

const string& Prieten::getAdress()
{
	return adress;
}

//const string Prieten::getName()
//{
//	return name;
//}
