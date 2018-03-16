// 只是用来说明纯虚函数、抽象类

#include <iostream>

using namespace std;

// 有纯虚函数的类叫抽象类,抽象类不允许直接创建对象,只能用来指向或引用子类对象,调虚函数的时候执行的是子类的函数
class Animal{
	public:
		virtual void eat() = 0; // 纯虚函数，表示一定不会被真正执行的函数,只有声明没有定义

		virtual void sleep() = 0;  

		virtual void shout() = 0;
		
	private:
		string name; //在内存占用默认4个字节
};

