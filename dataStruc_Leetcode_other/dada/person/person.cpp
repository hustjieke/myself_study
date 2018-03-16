#include "person.h"
#include <iostream>

using namespace std;

int main()
{
	Person p1("陈氏", true);	
	Person p2("高氏", false);	

	p1.set_age(20);
	p2.set_age(18);

	p1.show();
	p2.show();

	return 0;
}
