// 用于演示理解无名对象
//

#ifndef NONAME_OBJ_H_
#define NONAME_OBJ_H_

using namespace std;

class 	A{
	public:
		A():data(0){
			cout << "A()" << endl;
		}
		A(int d):data(d){
			cout << "A(" << d <<")" <<  endl;
		}

		void show() const{
			cout << "DATA = " << data;
		}//同名函数，有没有const也构成重载的因素,
		//对于常量对象只能调用常量函数，对于普通对象，优先调用非常量函数

		void show() {
			cout << "data = " << data;
		}

		~A(){
			cout << "~A()" << endl;
		}

	private:
		int data;
};

#endif
