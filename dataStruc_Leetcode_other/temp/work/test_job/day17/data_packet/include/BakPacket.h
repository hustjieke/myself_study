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
#include <cstdlib>
#include "DataPacket.h"

typedef struct BakPacket_
{
	int 	i_num;
	long 	l_num;
	double 	d_num;
	const char 	*str;
} BakPacket;



enum Enumcmp{ ASC, DESC };

class compare
{
	private:
		Enumcmp cmp;
	public:
		compare(Enumcmp c):cmp(c) {};
		bool operator ()(BakPacket cmp_a, BakPacket cmp_b)
		{
			switch(cmp)	
			{
				case ASC:
					return cmp_a.i_num < cmp_b.i_num;
					break;
				case DESC:
					return cmp_a.i_num > cmp_b.i_num;
					break;
				default:
					std::cout << "please choose just ASC or DESC" << std::endl;	
					exit(0);
			}
		}
};

//
void element_cpy(BakPacket b_stru[], const DataPacket &data_packet, int cnt);
//
void element_cpy_new(BakPacket b_stru[], DataPacket &data_packet);

#endif
