#include <iostream>
#include "animal.h"

using namespace std;

int main()
{
	Animal a1, a2;	
	Bird b1;

	a1.setName("团团");
	a1.setAge(300);

	b1.setName("鸽子");
	b1.setAge(300);
	b1.setWeight(100);

	a2.setName("圆圆");
	a2.setAge(400);

	//std::cout << "name: " << a1.getName() << "age: " << a1.getAge() << std::endl;
	//std::cout << "name: " << a2.getName() << "age: " << a2.getAge() << std::endl;
	//std::cout << "name: " << b1.getName() << "age: " << b1.getAge() << std::endl;
	//std::cout << "Weight: " << b1.getWeight() << endl;
	a1.show();
	cout << endl;
	a2.show();
	cout << endl;
	b1.show();
	cout << endl;

	b1.fly();

	return 0;
}
