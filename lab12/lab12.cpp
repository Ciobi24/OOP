#include "Contact.h"
#include "Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"
#include "Agenda.h"
#include <iostream>
using namespace std;
int main()
{
	Prieten* p1 = new Prieten("22.03.2001","0767347845","Str Garii","Mirel");
	Agenda a;
	a.addContact(*p1);
	Cunoscut* p2 = new Cunoscut("076373473", "Anda");
	a.addContact(*p2);
	list<Prieten*>friends= a.friends();
	for (auto it : friends)
		cout << (*it).name << endl;
	return 0;
}