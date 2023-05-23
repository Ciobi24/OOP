#include "Coleg.h"

Coleg::Coleg(const string& phone, const string& company, const string& adress, const string& name) : phone(phone), company(company), adress(adress) { this->type = coleg; this->name = name; }


const string& Coleg::getPhone()
{
	return phone;
}

const string& Coleg::getCompany()
{
	return company;
}

const string& Coleg::getAdress()
{
	return adress;
}

//const string Coleg::getName()
//{
//	return name;
//}
