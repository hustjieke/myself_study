//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName        : manipulator.h (UTF-8)
// Summary         : define class Manipulator just used for testing
// Author          : Gaoriyao
// Version         : v1.0
// CreatTime       : 2016-5-24
// Description     : Hello World in C++, Ansi-style
// History         : # 
//========================================================


#ifndef PERSON_DESIGN_INCLUDE_MANIPULATORS_H_
#define PERSON_DESIGN_INCLUDE_MANIPULATORS_H_

#include "human.h"
#include "judge_string.h"

class Manipulator{
    public:
        Manipulator() {}
        Manipulator(string name_t):m_name(name_t) {}

        void setName(string name_t);
        void play(const Human *p);

        ~Manipulator() {}

    private:
        string m_name;
};


#endif
