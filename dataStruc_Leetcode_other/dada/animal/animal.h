//动物类（父类）--鸟类（子类）。来说明父类子类概念，以及子类覆盖父类的同名函数。
//这里构造函数和析构函数是不齐全的，这里知识简单说明，在另外一个单独写的类详细说明父类子类的构造析构
#ifndef ANIMAL_H_
#define AINMAL_H_

using namespace std;

class Animal{
	public:
		Animal(){};
		Animal(string name_t, int age_t)
			:name(name_t), age(age_t){
			}

		void setName(string name_t){
			name = name_t;
		}
		void setAge(int age_t){
			age = age_t;
		}

		string getName(){ return name; }
		int getAge(){ return age; }

		void show(){
			cout << name << ':' << age;
		}// 会被子类的同名函数覆盖
		 // 输出信息函数一般不执行换行操作，换行由类用户来决定是否换行

	private:
		string 	name;
		int 	age;
};

//弄一个子类。继承父类全部成员，但是不能直接使用父类私有成员
class Bird:public Animal{
	public:	
		void setWeight(double weight_t){
			weight = weight_t;
		}
		double getWeight(){
			return weight;
		}

		void fly(){
			cout << "I can fly!!" << endl;
		}

		void show(){
			cout << "name: " << getName() << " age: " << getAge() 
				<< " Weight: " << weight; 
		} // 覆盖父类的同名函数,输出信息函数一般不执行换行操作，换行由类用户来决定是否换行
	private:
		double weight;
}; // 继承父类的所有成员，但是不能修改私有成员，可以修改保护成员，但是开发中一般不会用保护成员，容易被子类修改

#endif
