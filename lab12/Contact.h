#pragma once
#include <string>
using namespace std;

enum Type { prieten, coleg, cunoscut };

class Contact
{
protected:
	Contact(){}
	/*Contact(Type type) { this->type = type; }
	Contact(string name) { this->name = name; }
	Contact(string name, Type type) { this->type = type; this->name = name; }*/
public:
	Type type;
	string name;
	//Contact() = default;
	//Contact(const string& name);
	//virtual ~Contact() {}
	//virtual const string getName()=0;
	//virtual Type getType()=0;
};

