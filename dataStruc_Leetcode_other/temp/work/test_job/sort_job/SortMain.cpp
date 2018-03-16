//============================================================================
// Name        : SortMain.cpp
// Author      : Gao
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>

#include "SortTime.h"

using namespace std;

int main()
{
	int init_num;
	//cout << "Please enter a integer number(1000 or 10000 or 100000):" << endl;
	//cin >> init_num;
	//SortTime test_obj(init_num);
	SortTime test_obj(20);

	// 1 bubble sort
	test_obj.ArrayCpy();
	//test_obj.Print();

	cout << endl << "bubble sort time:" << endl;
	test_obj.TimeStart();
	test_obj.BubbleSort();
	test_obj.TimeEnd(); // print time cost

	test_obj.Print();

	// 2 Insert sort
	test_obj.ArrayCpy();
	//test_obj.Print();

	cout << endl << "insert sort time:" << endl;
	test_obj.TimeStart();
	test_obj.InsertSort();
	test_obj.TimeEnd(); // print time cost

	test_obj.Print();


	// 3 shell sort
	test_obj.ArrayCpy();
	//test_obj.Print();

	cout << endl << "shell sort time:" << endl;
	test_obj.TimeStart();
	test_obj.ShellSort();
	test_obj.TimeEnd(); // print time cost

	//test_obj.Print();

	// 4 heap sort
	test_obj.ArrayCpy();
	//test_obj.Print();

	cout << endl << "heap sort time:" << endl;
	test_obj.TimeStart();
	test_obj.HeapSort();
	test_obj.TimeEnd(); // print time cost

	//test_obj.Print();

	// 5 quick sort
	test_obj.ArrayCpy();
	//test_obj.Print();

	cout << endl << "quick sort time:" << endl;
	test_obj.TimeStart();
	test_obj.QuickSort();
	test_obj.TimeEnd(); // print time cost

	test_obj.Print();

	// release memory
	test_obj.clean();

	return 0;
}
