// SrcFile    : BakPacket.h
//
// Create on  : 2016-5-11 
//
// Author     : Gaoriyao
//
// Modify By  :
//
// Modify Time:

#ifndef BAKPACKET_H_
#define BAKPACKET_H_

#include <vector>
#include "DataPacket.h"

struct BakPacket
{
	//public:	
	//BakPacket(){}

	int 	i_num;
	long 	l_num;
	double 	d_num;
	const char 	*str;

	//bool operator < (const BakPacket &bak_packet)const
	//{
	//	return i_num < bak_packet.i_num;
	//}

	//bool operator > (const BakPacket &bak_packet)const
	//{
	//	return i_num > bak_packet.i_num;
	//}

	//void element_cpy(vector<BakPacket> &b_vec, const DataPacket &data_packet);

	BakPacket(){}
};

void element_cpy(struct BakPacket b_stru[], const DataPacket &data_packet, int cnt);
//bool cmp(BakPacket a, BakPacket b)
//{
//	return a.i_num > b.i_num;
//}

#endif
