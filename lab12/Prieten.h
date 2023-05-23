#pragma once
#include "Contact.h"
#include <string>
using namespace std;
class Prieten:public Contact
{
private:
	string date, phone, adress;
	//Type type = prieten;
public:
	//Prieten();
	Prieten(const string& date, const string& phone, const string& adress, const string& name);
	//~Prieten();
	const string& getDate();
	const string& getPhone();
	const string& getAdress();
	//const string getName();
	//Type getType() { return type; }
};

