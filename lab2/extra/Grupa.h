#include "Student.h"

class Grupa
{
private:
	
	Student students[10];
	int nrStudenti;

public:
	void Init();
	void Add(Student x);
	void SortAverage();
	void Print();
};