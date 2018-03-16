// 拷贝构造函数A()和A(const A&)在没有的时候编译器会自动创建，在自己显示构造的时候（即）自己写出来，则编译器不生成
// 默认的拷贝构造函数，把旧对象的内容逐个字节赋值到新对象中,比如有一个对象含有一个指针变量 name(保存指针),则默认
// 拷贝构造函数在调用的时候，新的对象也有一个name(指向同样的地址),这样新旧对象都能对这个地址的内容进行改变，这样就
// 会有问题：默认拷贝构造函数在有指针成员指向动态内存时会有问题

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

		// 引用是用来初始化它的那个变量的别名
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

// 执行拷贝构造函数给形参,注意这里不是默认构造函数，因为有显示拷贝构造函数
void show(A obj) {
	obj.show();
}

void func(const A& obj) {
	obj.show(); // 类里的show()必须是const函数
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
	func(a1);

	return 0;
}
