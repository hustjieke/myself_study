// SrcFile   : Time.cpp
//
// Create on : 2016-5-11    
//
// Author    : Gaoriyao
//
// Modify By  :
//
// Modify Time:
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>

#include "../include/Time.h"

using namespace std;

//static struct timeval tm_start;
//static struct timeval tm_end;

// ===================================================
// Function Name: ShowCurTime
// Function     : print out time(gtm and local) 
// Input        : none
// Output       : none
// Return       : 0  -- Success
// 				: -1 -- Failed
// ===================================================
int ShowCurTime()
{
	struct tm *local, *ptr;

	// get calendar time
	time_t t;
	t = time(NULL);  

	// convert calendar time to gmt
	ptr=gmtime(&t);	 
	if (!ptr)
	{
		cout << "gmtime() called failed!" << endl;
		cout << "file: " << __FILE__ << "	line: " << __LINE__ << endl; 
		return -1;
	}
	cout << "The UTC time is: 	" << asctime(ptr); 

	// convert calendar time to local time
	local = localtime(&t);
	if (!local)
	{
		cout << "localtime() called failed!" << endl;
		cout << "file: " << __FILE__ << "	line: " << __LINE__ << endl; 
		return -1;
	}
	cout << "The local time is: " << ctime(&t) << endl;

	return 0;
}

// ===================================================
// Function Name: TimeStart
// Function     : record and print out start time 
// Input        : none
// Output       : none
// Return       : 0  -- Success
// 				: -1 -- Failed
// ===================================================
int TimeStart(struct timeval &tm_start)
{
	// print out start time(gtm time and local time)
	if (-1 == ShowCurTime())
	{
		cout << "ShowCurTime() called failed!" << endl;
		cout << "file: " << __FILE__ << "	line: " << __LINE__ << endl; 
		return -1;
	}

	// save static time in tm_start
	if (-1 == gettimeofday(&tm_start, NULL))
	{
		cout << "gettimeofday() called failed!" << endl;
		cout << "file: " << __FILE__ << "	line: " << __LINE__ << endl; 
		return -1;
	}

	return 0;
}

// ===================================================
// Function Name: TimeEnd
// Function     : record and print out ended time 
// Input        : none
// Output       : none
// Return       : 0  -- Success
// 				: -1 -- Failed
// ===================================================
int TimeEnd(struct timeval &tm_end)
{
	// get ended time and save in tm_end
	if (-1 == gettimeofday(&tm_end, NULL))    
	{
		cout << "gettimeofday() called failed!" << endl;
		cout << "file: " << __FILE__ << "	line: " << __LINE__ << endl; 
		return -1;
	}

	// print out ended time(gtm time and local time)
	if (-1 == ShowCurTime())
	{
		cout << "ShowCurTime() called failed!" << endl;
		cout << "file: " << __FILE__ << "	line: " << __LINE__ << endl; 
		return -1;
	}

	return 0;
}

// ===================================================
// Function Name: TimeCost
// Function     : calculate time cost between start time and end time 
// Input        : none
// Output       : none
// Return       : void
// ===================================================
void TimeCost(struct timeval &tm_start, struct timeval &tm_end)
{
	double  tm_cost = 0;	// save total time cost
	long    tm_cost_sec = 0, tm_cost_usec = 0;

	tm_cost_sec     = tm_end.tv_sec - tm_start.tv_sec;
	tm_cost_usec    = tm_end.tv_usec - tm_start.tv_usec;
	if (tm_cost_usec < 0)
	{   
		tm_cost_usec   =   1000000     +   tm_cost_usec;
		tm_cost_sec    -=  1;  
		tm_cost        =   tm_cost_sec +   tm_cost_usec / 1000000.0;
	}   
	else
	{   
		tm_cost        =   tm_cost_sec +   tm_cost_usec / 1000000.0;
	}   

	cout << "tm_cost_sec: " << tm_cost_sec << endl;
	cout << "tm_cost_usec: " << tm_cost_usec << endl;
	cout << "tm_cost: " << tm_cost << endl << endl;

	return ;
}
