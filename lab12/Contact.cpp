#include "Contact.h"
Contact::Contact(std::string& name) :nume(name) {}
const std::string& Contact::getName()
{
	return this->nume;
}