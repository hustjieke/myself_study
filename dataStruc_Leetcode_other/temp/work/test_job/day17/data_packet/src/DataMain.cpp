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


using namespace std;

void PrintTest(const DataPacket &); // for test

//int main(int argc, char **argv)
int main(void)
{
	// 1 program start running 
	struct timeval tm_pro_start;
	struct timeval tm_pro_end;
	cout << "------program start------" << endl;
	if (-1 == TimeStart(tm_pro_start))    
		cout << "TimeStart() called failed!" << endl;

	// data_vec used to save 1000 data_packs	
	vector<DataPacket> 		data_vec; 
	// define struct array to save data get from DataPacket obj
	BakPacket *b_stru = new BakPacket[1000 * DATA_SIZE];

	// 2 init obj(class DataPacket) and copy to b_stru(struct BakPacket) 
	srand((unsigned)time(NULL)); // must be out side of for loop
	for (int loop_cnt = 0; loop_cnt < 1000; loop_cnt++)
	{
		DataPacket 	data_pack; 		   // default init size 4096

		data_vec.push_back(data_pack); // save 1000 data_packs

		element_cpy(b_stru, data_pack, loop_cnt);
	}

	// 3 print out time before sort
	struct timeval tm_sort_start;
	struct timeval tm_sort_end;
	cout << "------before sort ------" << endl;
	if (-1 == TimeStart(tm_sort_start))    
		cout << "TimeStart() called failed!" << endl;

	// 4 begin to sort
	sort(b_stru, b_stru+1000 * DATA_SIZE, compare(ASC));

	// 5 print out sort time cost
	if (-1 == TimeEnd(tm_sort_end))    
		cout << "TimeStart() called failed!" << endl;
	cout << "sort time cost: " << endl;
	TimeCost(tm_sort_start, tm_sort_end);

	// 6 cpy new data_packet and calulate all time cost
	// struct BakPacket *b_stru =new struct BakPacket[1000 * DATA_SIZE];
	DataPacket new_data_pack;
	element_cpy_new(b_stru, new_data_pack);

	cout << "------ before sort ------" << endl;
	if (-1 == TimeEnd(tm_pro_end))    
		cout << "TimeStart() called failed!" << endl;
	TimeCost(tm_pro_start, tm_pro_end);

	// for test
	//PrintTest(b_stru);
	PrintTest(new_data_pack);

	delete []b_stru;
	return 0;
}


// just for test
//void PrintTest(const struct BakPacket b_stru[])
void PrintTest(const DataPacket &new_packet)
{
	for(unsigned i = 0; i < 100; i++)
	{
		cout   << "i_num: " << new_packet.arr[i] << endl;
		cout << "l_num: " 	<< new_packet.l_vec[i] << endl;
		cout << "d_num: " 	<< new_packet.d_vec[i] << endl;
		cout << "str_num: " << new_packet.str_vec[i] << endl;
		cout << endl;
	}
}

