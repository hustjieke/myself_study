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
//#include <ctime>

#include "../include/BakPacket.h"
#include "../include/DataPacket.h"
#include "../include/Time.h"


using namespace std;
void PrintTest(const vector<BakPacket> &vec);

int main(int argc, char **argv)
{
	vector<DataPacket> 		data_vec; // used to save 1000 data_packs	
	vector<BakPacket>		bak_vec;  // used to copy element in data_pack 
	BakPacket 	temp_packet; // temp obj，used to cpy single data packet
	//struct BakPacket *b_stru = new BakPacket[1000 * DATA_SIZE];

	srand((unsigned)time(NULL)); // must 
	// 1 init obj(class DataPacket) and copy to temp_packet(class BakPacket) 
	for (int i = 0; i < 1000; i++)
	{
		//DataPacket data_pack(2048);  // specify size to init
		DataPacket 	data_pack; 		   // default init size 4096
		data_vec.push_back(data_pack); // save 1000 data_packs

		// copy element in data_pack to bak_vec to generate 
		// a new data packet (in vector<BakPacket>) include all data 
		temp_packet.element_cpy(bak_vec, data_pack);
	}

	// 2 print out cur time
	if (-1 == TimeStart())    
		cout << "TimeStart() called failed!" << endl;

	// 3 begin to sort
	//stable_sort(bak_vec.begin(), bak_vec.end(), less<BakPacket>());
	sort(bak_vec.begin(), bak_vec.end(), less<BakPacket>());

	// 4 print out time cost
	cout << "-----after sort ...." << endl;
	if (-1 == TimeEnd())    
		cout << "TimeStart() called failed!" << endl;
	TimeCost();

	// for test
	PrintTest(bak_vec);

	return 0;
}




// just for test
void PrintTest(const vector<BakPacket> &vec)
{
	for(unsigned i = 0; i < 100; i++)
	{
		cout   << "i_num: " << vec[i].i_num << endl;
		//cout << "l_num: " 	<< vec[i].l_num << endl;
		//cout << "d_num: " 	<< vec[i].d_num << endl;
		//cout << "str_num: " << vec[i].str 	<< endl;
		cout << endl;
	}
}

