// SrcFile   : BakPacket.cpp
//
// Create on : 2016-5-11    
//
// Author    : Gaoriyao
//
// Modify By  :
//
// Modify Time:

#include <iostream>
#include <vector>

#include "../include/BakPacket.h"
#include "../include/DataPacket.h"

using namespace std;

//bool cmp(BakPacket a, BakPacket b)
//{
//	return a.i_num < b.i_num;
//}

// ===================================================
// Function Name: BakPacket::element_cpy
// Function     : cpy element from data_packet to temp_packet once a time 
// 				  and then push back temp_packet into b_vec
// Input        : vector<BakPacket>
// Output       : none
// Return       : void
// ===================================================
void element_cpy(BakPacket b_stru[], 
		const DataPacket &data_packet, int cnt)
{
	//BakPacket       temp_packet; // used to save element 

	for (int i = 0; i < DATA_SIZE; i++) 
	{   
		b_stru[cnt * DATA_SIZE + i].i_num = data_packet.arr[i];
		b_stru[cnt * DATA_SIZE + i].l_num = data_packet.l_vec[i];
		b_stru[cnt * DATA_SIZE + i].d_num = data_packet.d_vec[i];
		b_stru[cnt * DATA_SIZE + i].str   = data_packet.str_vec[i].c_str();
	}

	return ;
} // temp for test


void element_cpy_new(BakPacket b_stru[], 
		DataPacket &data_packet)
{
	//string  temp_str;
	for (int i = 0; i < DATA_SIZE; i++)
	{
		//temp_i   = b_stru[i].i_num;
		//temp_l   = b_stru[i].l_num;
		//temp_d 	 = b_stru[i].d_num;
		//temp_str =b_stru[i].str;
		data_packet.arr[i] = b_stru[i].i_num;
		//data_packet.l_vec[i].push_back(temp_l);
		data_packet.l_vec.push_back(b_stru[i].l_num);
		data_packet.d_vec.push_back(b_stru[i].d_num);
		data_packet.str_vec.push_back(b_stru[i].str);
	}
}
