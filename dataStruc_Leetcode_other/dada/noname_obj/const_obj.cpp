//用于验证常量对象，文件要单独变异，不能跟无名对象cpp一块编译

#include <iostream>

#include "const_obj.h"

using namespace std;

int main()
{
	A a1(1);
	const A a2(2);//this在初始化后为指向常量对象的常量指针(this在对象初始化后就初始化为对象地址,一直跟随)
	// 而指向的对象又是常量的对象，因此函数必须声明为const,否则类型不匹配，因为非const函数能修改对象成员
	// 而此处显然是不想去修改常量对象成员

	a1.show();// 默认先调用跟函数匹配的非常量成员函数，而不是常量函数
	cout << endl;
	a2.show();
	cout << endl;

	return 0;
}

