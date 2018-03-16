//

#ifndef FATHER_SON_H_
#define FATHER_SON_H_

using namespace std;

class Parent{
	public:
		Parent():mp(0){
			cout << "Parent()" << endl; // 用于测试，正常是不用写的，只是执行默认构造
		}
		Parent(int d):mp(d){
			cout << "Parent(" << d << ")" << endl;
		} // 注意输出 'd' 的写法



		~Parent(){
			cout << "~Parent()" << endl;
		}

	private:
		int mp;

};

class Child:public Parent{
	public:
		Child():mc(0.0){
			cout << "Child()" << endl;
		}
		Child(double d):mc(d){
			cout << "Child(" << d << ")" << endl;
		}//默认创建子类总是调用父类的无参的构造函数,若想调用父类有参函数，则用初始化列表,如Child(double d):mc(d),Parent(d){}

		~Child(){
			cout << "~Child()" << endl;
		}

	private:
		double mc;
};

#endif
