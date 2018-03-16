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


// ===================================================
// Function Name: BakPacket::element_cpy
// Function     : cpy element from data_packet to temp_packet once a time 
// 				  and then push back temp_packet into b_vec
// Input        : vector<BakPacket>
// Output       : none
// Return       : void
// ===================================================
void element_cpy(struct BakPacket b_stru[], 
		const DataPacket &data_packet, int cnt)
{
	//BakPacket       temp_packet; // used to save element 

	for (int i = 0; i < DATA_SIZE; i++) 
	{   
		b_stru[cnt * DATA_SIZE + i].i_num = data_packet.arr[i];
		b_stru[cnt * DATA_SIZE + i].l_num = data_packet.l_vec[i];
		b_stru[cnt * DATA_SIZE + i].d_num = data_packet.d_vec[i];
		b_stru[cnt * DATA_SIZE + i].str   = data_packet.str_vec[i].c_str();
		//int j = 0;
		//for (; j < LENGTH; j++)
		//{
		//	b_stru[cnt * DATA_SIZE + i].str[j] = temp_str[j];
		//}
		//b_stru[cnt * DATA_SIZE + i].str[j] = '\0';
		//temp_packet.l_num = data_packet.l_vec[i];
		//temp_packet.d_num = data_packet.d_vec[i];
		//temp_packet.str   = data_packet.str_vec[i];
		//b_vec.push_back(temp_packet);   
		//b_stru++;
	}

	return ;
} // temp for test


// compile error, why?
//void BakPacket::element_cpy(vector<BakPacket> &b_vec, 
//		const DataPacket &data_packet)
//{
//	BakPacket       temp_packet;
//	
//	vector<int>::iterator 		i_iter;	
//	vector<string>::iterator 	str_iter;	
//	vector<long>::iterator 	l_iter;	
//	vector<double>::iterator 	d_iter;	
//
//	for (i_iter = (data_packet.i_vec).begin(), d_iter = (data_packet.d_vec).begin(); 
//			i_iter != data_packet.i_vec.end(); i_iter++, d_iter++)
//	{
//	temp_packet.i_num = *i_iter;
//	temp_packet.str= *str_iter;
//	temp_packet.l_num = *l_iter;
//	temp_packet.d_num = *d_iter;
//	b_vec.push_back(temp_packet);   
//	}
//
//	return ;
//}
