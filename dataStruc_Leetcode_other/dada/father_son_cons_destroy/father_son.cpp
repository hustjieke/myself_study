//
#include <iostream>
#include "father_son.h"

using namespace std;

int main()
{
	Child c1;//不仅调用子类的构造函数，而子类包含父类的一整套成员，因此创建对象同时，还会调用父类的构造函数
	// 而且先执行父类的构造函数，先有父，再有子，析构的时候则相反
	Child c2(100); //创建子类的时候，默认调用父类无参的构造函数

	c1.show();

	return 0;
}
