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

class BakPacket
{
	public:	
		BakPacket(){}

		int 	i_num;
		long 	l_num;
		double 	d_num;
		string 	str;

		bool operator < (const BakPacket &bak_packet)const
		{
			return i_num < bak_packet.i_num;
		}

		bool operator > (const BakPacket &bak_packet)const
		{
			return i_num > bak_packet.i_num;
		}

		void element_cpy(vector<BakPacket> &b_vec, const DataPacket &data_packet);

		~BakPacket(){}
};

#endif
