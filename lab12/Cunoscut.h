#pragma once
#include "Contact.h"
#include <string>
using namespace std;
class Cunoscut: public Contact
{
private:
	string phone;
	//Type type = cunoscut;
public:
	//Cunoscut();
	Cunoscut(const string& phone, const string& name);
	//~Cunoscut();
	const string getName();
	const string& getPhone();
	//Type getType() { return type; }
};

