// SrcFile	 : DataPacket.cpp
//
// Create on : 2016-5-11	
//
// Author	 : Gaoriyao
//
// Modify By  :
//
// Modify Time:

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>

#include "../include/DataPacket.h"


// ===================================================
// default pass DATA_SIZE value(macro) when obj init
// ===================================================
DataPacket::DataPacket()
{
	RandInit(DATA_SIZE);
}

// ===================================================
// pass specify number when obj init
// ===================================================
DataPacket::DataPacket(int num)
{
	RandInit(num);
}

// ===================================================
// Function Name: RandInit
// Function		: creat random init value
// Input		: upper_limit(pass a number when obj is created)
// Output		: random init obj
// Return		: void
// ===================================================
void DataPacket::RandInit(int upper_limit)
{

	for (int i = 0; i < upper_limit; i++)
	{
		// random int value 0 ~ 65535
		//i_vec.push_back( rand() % 65536 );
		arr[i] 	 	= rand() % 65536 ;
		// random long value 0 ~ 65535
		l_vec.push_back( rand() % 65536 );
		//arr_long[i] = rand() % (long)65536;
		// random double value 0.0 ~ 65535.0
		d_vec.push_back( rand() / (double)(RAND_MAX / 65536) );
		str_vec.push_back( GetRandomStr() );
	}

	return ;
}

// ===================================================
// Function Name: GetRandomStr
// Function		: get random str ('a' ~ 'z', 'A' ~ 'Z')
// Input		: none
// Output		: none
// Return		: string
// ===================================================
string DataPacket::GetRandomStr()
{
	// changed once by 1 second, bug?
	//srand((unsigned)time(NULL)); 

	string	str; 
	for (int i = 0; i < LENGTH; i++)  // LENGTH (macro):default 30  
	{
		if (0 == rand() % 2)
			str += 'a' + rand() % 26; // 'a' ~ 'z'
		else
			str += 'A' + rand() % 26; // 'A' ~ 'Z'
	}

	return str;
}


