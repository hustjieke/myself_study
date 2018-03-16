// 友元函数、重载
#include <iostream>

using namespace std;

class A {
	public:
		A(int d = 0):data(d) {
			cout << "A(int=0)" << endl;
		}

		// 如果没有这个拷贝构造函数,那么调用 A add (const A a1, const A a2)
		// 函数将会发生默认拷贝构造，编译器合成的构造函数，释放时候依旧调用
		// 析构，这个时候会发现三次构造五次析构，其实两次默认构造自动完成了
		A(const A& obj) {
			cout << "A(const A&)" << endl;
		}// 无参构造函数是什么都不干,由编译器初始化内部数据类型
		// A a1 = obj1等效于 A a1(obj1);一般喜欢用后面的形式，因为可以初始化好几个,形式自由
		// 这个叫拷贝构造函数，还是构造函数，只是名字比较普通而已

		void show() {
			cout << "data =" << data << endl;
		}

		friend A add(const A a1, const A a2);

		~A() {
			cout << "~A()" << endl;
		}
	private:
		int data;
};

// 只使用而不改变对象一般都是用的const &或者const指针
A add (const A a1, const A a2) {
	int sum = a1.data + a2.data;
	cout << "sum = " << sum << endl;
	return A(sum); // 无名对象,一次性使用
}

int main()
{
	A obj1(40), obj2(50);
	add(obj1, obj2).show();

	return 0;
}
