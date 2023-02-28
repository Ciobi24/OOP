#include <iostream>
#include "NumberList.h"
using namespace std;
NumberList nr;
int main()
{
	nr.Init();
	nr.Add(5);
	nr.Add(3);
	nr.Add(9);
	nr.Sort();
	nr.Print();
	return 0;
}
