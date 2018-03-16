//============================================================================
// FileName    : SortMain.cpp
// Author      : Gaoriyao
// Version     : v1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

#include "../include/BakPacket.h"
#include "../include/DataPacket.h"
#include "../include/Time.h"


using namespace std;

void PrintTest(const struct BakPacket b_stru[]);

bool cmp(BakPacket a, BakPacket b)
{
	return a.i_num < b.i_num;
}

int main(int argc, char **argv)
{
	// 1 program start running 
	struct timeval tm_pro_start;
	struct timeval tm_pro_end;
	cout << "------program start------" << endl;
	if (-1 == TimeStart(tm_pro_start))    
		cout << "TimeStart() called failed!" << endl;

	vector<DataPacket> 		data_vec; // used to save 1000 data_packs	

	struct BakPacket *b_stru =new struct BakPacket[1000 * DATA_SIZE];

	// 2 init obj(class DataPacket) and copy to temp_packet(class BakPacket) 
	srand((unsigned)time(NULL)); // must be out side of for loop
	for (int i = 0; i < 1000; i++)
	{
		//DataPacket data_pack(2048);  // specify size to init
		DataPacket 	data_pack; 		   // default init size 4096
		data_vec.push_back(data_pack); // save 1000 data_packs

		element_cpy(b_stru, data_pack, i);
	}

	// 3 print out time before sort
	struct timeval tm_sort_start;
	struct timeval tm_sort_end;
	cout << "------before sort ------" << endl;
	if (-1 == TimeStart(tm_sort_start))    
		cout << "TimeStart() called failed!" << endl;

	// 4 begin to sort
	sort(b_stru, b_stru+1000 * DATA_SIZE, cmp);

	// 5 print out sort time cost
	if (-1 == TimeEnd(tm_sort_end))    
		cout << "TimeStart() called failed!" << endl;
	cout << "sort time cost: " << endl;
	TimeCost(tm_sort_start, tm_sort_end);

	// for test
	PrintTest(b_stru);

	// 6 all time cost
	cout << "------before sort ------" << endl;
	if (-1 == TimeEnd(tm_pro_end))    
		cout << "TimeStart() called failed!" << endl;
	TimeCost(tm_pro_start, tm_pro_end);

	delete []b_stru;
	return 0;
}




// just for test
void PrintTest(const struct BakPacket b_stru[])
{
	for(unsigned i = 0; i < 100; i++)
	{
		cout   << "i_num: " << b_stru[i].i_num << endl;
		cout << "l_num: " 	<< b_stru[i].l_num << endl;
		cout << "d_num: " 	<< b_stru[i].d_num << endl;
		cout << "str_num: " << *(b_stru[i].str) << endl;
		cout << endl;
	}
}

