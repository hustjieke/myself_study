#ifndef HUMAN_H_
#define HUMAN_H_

#include <string.h>
#include <iostream>

using namespace std;

class Human{

	public:
		Human(){};
		Human(string name_t, int age_t, string ID_t)
			:name(name_t), age(age_t), ID(ID_t){
			}

		void set_name(string name_t){
			if (name_t == " "){
				cout << "Please input correct name!" << endl;
			}
			else{
				name = name_t;
			}
		}

		void set_age(int age_t){
			if ((age_t < 0) || (age_t > 130)){
				cout << "Warning!! You may input wrong No.,please check" << endl;
			}
			else{
				age = age_t;
			} 
		}

		void set_ID(string ID_t){
			if (ID_t.size() < 17)
		}

		void show(){
			cout << "I am" << (gender?"帅哥，大名：":"美女，大名：") << name 
				<< "，今年" << age << "岁" << endl;
		}

		~Human(){}

	private:
		string name;
		int  age;
		string ID;
		//bool gender;
};

class Student:public Person{
	public:

	private:
		int classroom;
		double score;
};

#endif
