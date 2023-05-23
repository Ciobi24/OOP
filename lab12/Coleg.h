#pragma once
#include "Contact.h"
#include <string>
using namespace std;
class Coleg: public Contact
{
private:
	string phone, company, adress;
	//Type type = coleg;
public:
	//Coleg();
	Coleg(const string& phone, const string& company, const string& adress,const string& name);
	//~Coleg();
	const string& getPhone();
	const string& getCompany();
	const string& getAdress();
	const string getName();
	//Type getType() { return type; }
};

