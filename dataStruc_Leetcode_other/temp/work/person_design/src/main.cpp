//========================================================
// Copyright(c) : 2016-20xx BONC.Inc
// FileName        : main.cpp (UTF-8)
// Summary        : just used to test the relationship of 
//                   parent and subclasses defined
// Author          : Gaoriyao
// Version         : v1.0
// CreatTime    : 2016-5-24
// Description     : Hello World in C++, Ansi-style
// History        : # 
//========================================================

#include "athletes.h"
#include "basketball_player.h"
#include "firemen.h"
#include "football_player.h"
#include "human.h"
#include "manipulator.h"
#include "mid_school_stu.h"
#include "one_hundred_m_runner.h"
#include "pilot.h"
#include "student.h"
#include "university_stu.h"

#include <iostream>

using namespace std;

int main()
{
    // construct a controller(You can think it just a game player) to test  
    Manipulator controller("Jack");

    Human* arr[10];
    // construct a obj(such as a game role) to test class defined
    arr[0] = new MidSchoolStu("X氏", 14, "111111111111111111", true,
            "中学生", "北京十五中", "u201614", "初一");
    arr[1] = new UniversityStu("Y氏", 25, "111111111111111112", true,
            "大学生", "清华", "u201618", "大一");
    arr[2] = new Firemen("李氏", 25, "111111111111111113", true,
            "消防员", "望京消防局", 10);
    arr[2]->setAge(20);
    arr[3] = new Pilot("张氏", 22, "111111111111111114", true,
            "飞行员", "中国航空公司", "波音737");
    arr[4] = new Runners("王氏", 20, "111111111111111115", false, "百米运动员", 11);
    arr[5] = new BasketballPlayer("科比", 37, "111111111111111116", true, "篮球运动员", 20, "湖人");
    arr[6] = new FootballPlayer("梅西", 31, "111111111111111117", true, "足球运动员", 10, "巴萨");
    arr[7] = new FootballPlayer("小罗", 36, "111111111111111118", true, "足球运动员", 10, "巴萨");
    arr[8] = new FootballPlayer("卡卡", 32, "111111111111111119", true,"足球运动员", 10, "巴萨");
    arr[9] = new FootballPlayer("大罗", 38, "111111111111111120", true, "足球运动员", 10, "巴萨");

    // self-introduction
    for (int i = 0; i < 10; i++) {
        controller.play(arr[i]);
        cout << endl;
    }
    
    // delete and print out how many obj exist
    arr[9]->telepathicFunction();
    for (int i = 0; i < 10; i++) {
        delete arr[i];
        arr[i]->telepathicFunction();
    }

    return 0;
}
