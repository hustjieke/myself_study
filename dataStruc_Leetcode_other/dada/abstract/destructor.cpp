#include <iostream>

using namespace std;

class A {
	public:
		A() { cout << "A()" << endl; }
		virtual ~A() { cout << "~A()" << endl; } // 根据对象的真实类型执行相应的析构函数
};

class B : public A {
	public:
		B() { cout << "B()" << endl; }
		~B() { cout << "~B()" << endl; }
};

int main()
{
	A *p = new B;

	delete p;
	
	return 0;
}
