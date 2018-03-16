//

#include <iostream>

#include "noname_obj.h"

using namespace std;

int main()
{
	A a1(1);
	A(2); // 无名对象，没有名字的对象，只能一次性使用
	A(3).show(); // 想要使用成员函数，直接调用就行

	A a4;
	a4 = A(4);// 无名对象可以用于赋值给另外一个对象

	cout << "验证无名对象被创建之后会立即释放" << endl;

	a4.show();
	cout << endl;
	a4 = 40;// 由低级到高级转换，40(int型)转换成A类型,等价于a4 = A(40);or a4 = (A)40;

	(A)5; // A(int),用于展示无名对象其实就是一个强制类型转换

	return 0;
}

