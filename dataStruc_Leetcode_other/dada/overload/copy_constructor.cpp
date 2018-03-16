// 拷贝构造函数

#include <iostream>

using namespace std;

class A {
	public:
		//初始化列表只是初始化数据成员，而不是形参
		A() : data(100) {
			cout << "A()" << endl;
		}

		A(int d) : data(d) {
			cout << "A(int a)" << endl;
		}

		A(bool b) : data(b ? 123 : 456) {
			cout << "A(bool b)" << endl;
		}

		// 注意这里字符串转数字的技巧
		A(char c) : data((int) c) {
			cout << "A(char c)" << endl;
		}

		A(const A& o) : data(o.data) {
			cout << "A(const A& o)" << endl;
		}

		// 没加const
		void show() {
			cout << "data = " << data << endl;
		}

		// 析构函数只能是一个，可以写成虚析构形式
		virtual ~A() {
			cout << "virtual ~A()" << endl;
		}
	private:
		int data;
};

// 执行拷贝构造函数给形参
void show(A obj) {
	obj.show();
}

int main()
{
	A a1;	
	//A a2(200);
	//A a3(false);
	//A a4('v');
	//A a5(a2);

	// 具体调用什么构造函数完全由传入的实参类型决定
	show(a1);
	show(200); // 只能调用整形的A(int a)来初始化,本质是强制转换
	show(false);
	show('V');

	return 0;
}
