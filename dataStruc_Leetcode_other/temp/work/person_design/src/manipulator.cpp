//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName        : manipulator.cpp (UTF-8)
// Summary         : define funciton in header file manipulator.h
// Author          : Gaoriyao
// Version         : v1.0
// CreatTime       : 2016-5-24
// Description     : Hello World in C++, Ansi-style
// History         : # 
//========================================================

#include "human.h"
#include "manipulator.h"



void Manipulator::setName(string name_t) {
    judgeString(name_t);
    m_name = name_t;
}

void Manipulator::play(const Human *p) {
    p->doAction();
}
