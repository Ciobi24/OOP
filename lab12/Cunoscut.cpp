#include "Cunoscut.h"

Cunoscut::Cunoscut(const string& phone, const string& name) :phone(phone) { this->type = cunoscut; this->name = name; }


//const string Cunoscut::getName()
//{
//	return name;
//}

const string& Cunoscut::getPhone()
{
	return phone;
}
