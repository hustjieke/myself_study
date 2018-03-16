#ifndef SORTTIME_H_
#define SORTTIME_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>

class SortTime
{
	public:
		SortTime();
		SortTime(int n)
		{
			arr_num  = n;
			array_init = new int[n];
			array = new int[n];
			if (!array_init || !array)
				std::cout << "Not enough memory!" << std::endl;
			RandInit();
		}

		void RandInit(); // generate rand num
		void ArrayCpy(); 
		void Print(); // print for test result

		void TimeStart()
		{
			gettimeofday(&tm_start, NULL);
		}

		void TimeEnd();

		void BubbleSort();
		void InsertSort();
		void ShellSort();
		void HeapSort();
		void QuickSort();

		void clean()
		{
			delete []array;
			delete []array_init;
		}

		~SortTime()
		{
			std::cout << "destory!!" << std::endl;
		}

	private:
		int *array;
		int *array_init;
		int arr_num;
		struct timeval tm_start;
		struct timeval tm_end;
};

#endif


