#ifndef PERSON_H_
#define PERSON_H_

#include <string.h>
#include <iostream>

using namespace std;

class Person{
	private:
		//char name[20];
		string name;
		bool gender;
		int  age;

	public:
		Person(string p_name, bool _gender)
			:name(p_name), gender(_gender), age(0){
			//if (strlen(name) > 19){
			//	cout << "name too long!" << endl;
			//	name[19] = '\0';
			//}
		}

		void set_age(int age_){
			if (age_ < 0){
				cout << "can you go back?" << endl;
			}
			else if (age_ > 200){
				cout << "too old" << endl;
			}
			else{
				age = age_;
			} 
		}

		void show(){
			cout << "I am" << (gender?"帅哥，大名：":"美女，大名：") << name 
				<< "，今年" << age << "岁" << endl;
		}

		~Person(){}
};

class Student:public Person{
	public:

	private:
		int classroom;
		double score;
};

#endif
