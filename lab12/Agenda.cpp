#include "Agenda.h"
Contact* Agenda::searchByName(const string& name)
{
    for (auto contact : contacts)
        if (contact->name == name)
            return contact;
    return nullptr;
}

list<Prieten*> Agenda::friends()
{
    list<Prieten*> friends;
    for (auto contact : contacts)
        if (contact->type == prieten) //if(typeid(contact)==typeid(Prieten*))
            friends.push_back(static_cast<Prieten*>(contact));
    return friends;
}

void Agenda::deleteContact(string& name)
{
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if ((*it)->name == name) {
            contacts.erase(it);
            return;
        }
    }
}

void Agenda::addContact(Contact& contact)
{
	contacts.push_back(&contact);
}
