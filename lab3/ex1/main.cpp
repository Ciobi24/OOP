
#include "Math.h"

int main()
{
	Math m1;
	m1.Add(1, 2);
	m1.Add(1, 2, 3);
	m1.Add(1.1, 2.2);
	m1.Add(1.1, 2.2, 3.3);
	m1.Add(5, 1, 2, 3, 4, 5);
	m1.Mul(1, 2);
	m1.Mul(1.1, 2.2);
	m1.Mul(1, 2, 3);
	m1.Mul(1.1, 2.2, 3.3);
	std::cout<<m1.Add("3", "18");

}
