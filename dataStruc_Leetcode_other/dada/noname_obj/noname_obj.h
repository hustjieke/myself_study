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

		void show(){
			cout << "data = " << data;
		}

		~A(){
			cout << "~A()" << endl;
		}

	private:
		int data;
};

#endif
