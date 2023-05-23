#pragma once
#include "Contact.h"
#include "Prieten.h"
#include <string>
#include <list>
using namespace std;
class Agenda
{
private:
	list<Contact*> contacts;
public:
	//Agenda();	
	//~Agenda();	
	Contact* searchByName(const string& name);
	list<Prieten*> friends();
	void deleteContact(string& name);
	void addContact(Contact& contact);
};

