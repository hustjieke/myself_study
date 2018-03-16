//
//
//

#include "university_stu.h"
#include <iostream>

using namespace std;


void UniversityStu::study() const {
	cout << "I am studying calculus" << endl;
}

void UniversityStu::exam() const {
	cout << "I am doing calculus examination" << endl;
}

void UniversityStu::sleep() const {
	cout << "I sleep 9 hours one day" << endl;
}

void UniversityStu::selfIntroduction() const {
	cout << "My name is: " << m_name << " Age: " << m_age
		<< " ID: " << m_ID << endl;
	cout << "My job is " << m_profession << endl;
}

void UniversityStu::doAction() const {
    selfIntroduction();

	eat(); // inherited from Human
	sleep();
	entertain(); // inherited from Student
	study();
	exam();
}
