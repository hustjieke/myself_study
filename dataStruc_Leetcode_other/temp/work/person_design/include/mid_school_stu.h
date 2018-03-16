//
//
#ifndef PERSON_DESIGN_INCLUDE_MID_SCHOOL_STU_H_ 
#define PERSON_DESIGN_INCLUDE_MID_SCHOOL_STU_H_ 

#include "student.h"

class MidSchoolStu : public Student {
	public:
		MidSchoolStu() {}

		MidSchoolStu(string name_t, int age_t, string ID_t, bool gender_t,
                string profession_t,
				string school_t, string student_ID_t, string grade_t) :
			Student(name_t, age_t, ID_t, gender_t, profession_t,
					school_t, student_ID_t, grade_t) {

			}

		MidSchoolStu(const MidSchoolStu& obj) : Student(obj) {}

		MidSchoolStu& operator=(const MidSchoolStu& obj) {
			Student::operator=(obj);

			return *this;
		}

		void study() const; // inherited from Student
		void exam() const; // inherited from Student
        void selfIntroduction() const;

		void sleep() const; // inherited from Human
		void doAction() const; // inherited from Human
};

#endif
