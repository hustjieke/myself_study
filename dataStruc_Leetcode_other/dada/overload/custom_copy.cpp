// 在自定义拷贝构造函数之后就没有默认构造函数了，要在自己定义的拷贝函数中处理所有需要处理的数据

#include <iostream>

using namespace std;

class A {
	public:
		//初始化列表只是初始化数据成员，而不是形参
		A() : data(100) {
			cout << "A()" << endl;
		}

		// 引用是用来初始化它的那个变量的别名,之所以用一个初始化形参,是也因为拷贝对象只
		// 拷贝到形参里面(即这里的o)而不是成员变量里面，而在执行完拷贝构造函数后，形参就消失了
		// data并没有被初始化
		A(const A& o) : data(o.data) {
			cout << "A(const A& o)" << endl;
		}//拷贝构造函数

		// 形参是一个新变量，在调用时创建，由实参来初始化,因此A(A o)在内存的中
		// 先执行A o,生成o对象，在用 a1 初始化o(a1),这个初始化过程中又调用A(A o)
		// 再拷贝形参生成新的对象o，用a1初始化o。。。形成无限循环，这个拷贝构造
		// 函数是错误的
		//A(A o) : data(o.data) {
		//	cout << "A(A o)" << endl;
		//}

		void show() const {
			cout << "data = " << data << endl;
		} // 

		// 析构函数只能是一个，可以写成虚析构形式
		virtual ~A() {
			cout << "virtual ~A()" << endl;
		}
	private:
		int data;
};


int main()
{
	A a1;	
	A a2(a1);

	// 具体调用什么构造函数完全由传入的实参类型决定

	return 0;
}
