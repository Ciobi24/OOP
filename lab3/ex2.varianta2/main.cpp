#include "Canvas.h"
Canvas c(50,50);
int main()
{
	c.FillRect(1,1,5,9,'%');
	c.DrawRect(1,1,5,9,'$');
	c.DrawLine(1, 1, 1, 9, '@');
	c.FillCircle(10, 10, 9, '!');
	c.DrawCircle(10,10,9,'~');
	c.Print();
}
