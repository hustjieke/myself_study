// SrcFile	 : DataPacket.h
//
// Create on : 2016-5-11	
//
// Author	 : Gaoriyao
//
// Modify By  :
//
// Modify Time:

#ifndef DATAPACKET_H_
#define DATAPACKET_H_

#include <vector>

#define DATA_SIZE  4096  // default vector size
#define LENGTH	   30	 // default string length 

using namespace std;


class DataPacket
{
	public:
		DataPacket();
		DataPacket(int num);

		vector<int> 		i_vec;
		vector<long>		l_vec; 		
		vector<double>  	d_vec;
		vector<string> 		str_vec;

		~DataPacket(){}
	private:
		void RandInit(int upper_limit);
		string GetRandomStr();
};

#endif
