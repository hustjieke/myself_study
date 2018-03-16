#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SortTime.h"

using namespace std;

// used to swap two elements
void swap(int& m, int& n)
{
	int temp = m;
	m = n;
	n = temp;
}


// print first 100 elements in array[]
void SortTime::Print()
{
	cout << "arr_num:" << this->arr_num << endl; 
	//for (int i = 0; i < this->arr_num; ++i)
	for (int i = 0; i < 50; ++i)
		cout << *(this->array + i) << endl;
}

// create rand num from 0~65535
void SortTime::RandInit()
{
	cout << "init array! " << endl;
	srand((unsigned)time(NULL));	
	for (int i = 0; i < this->arr_num; ++i)
		*(this->array_init + i) = rand() % 65535;
}

// the copied array is used for sorting
void SortTime::ArrayCpy()
{
	for (int i = 0; i < this->arr_num; ++i)
		*(this->array + i) = *(this->array_init + i);
}

// record over time and calculate time cost
void SortTime::TimeEnd()
{
	double  tm_cost = 0;
	long    tm_cost_sec = 0, tm_cost_usec = 0;
	gettimeofday(&(this->tm_end), NULL);	

	// calculate time cost
	tm_cost_sec     = (this->tm_end).tv_sec - (this->tm_start).tv_sec;
	tm_cost_usec    = (this->tm_end).tv_usec - (this->tm_start).tv_usec;
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
	cout << "tm_cost: " << tm_cost << endl;
}

// 1 bubble sort (always little to big)
void SortTime::BubbleSort()
{
	int i, j;
	bool flag = true; // judge if the array already sorted or not

	for (i = 0; (i < this->arr_num) && flag; ++i)
	{
		bool flag = false;
		for (j = this->arr_num - 1; j >= i; j--) 
		{
			if ((this->array)[j - 1] > (this->array)[j])
			{
				swap(*(this->array + j -1), *(this->array + j));
				flag = true;
			}
		}
	}
}

// 2 insert sort
void SortTime::InsertSort()
{
	int i, j, temp;	
	for (i = 1; i < this->arr_num; i++)
	{
		if ((this->array)[i - 1] > (this->array)[i])
		{
			temp = (this->array)[i];
			j = i;
			while (j > 0 && (this->array)[j - 1] > temp)
			{
				(this->array)[j] = (this->array)[j-1];
				j--;
			}
			(this->array)[j] = temp;
		}
	}

}

// 3 shell sort
/*
void SortTime::ShellSort() 
{
	if (this->arr_num <= 1 || NULL == this->array)
		return;
	int temp = 0;
	int i, j, div;

	for (div = this->arr_num / 2; div >= 1; div /= 2)
	{
		for (i = div; i < this->arr_num; i++)
		{
			temp = (this->array)[i];
			for (j = i - div; ((this->array)[j] > 
						temp && j >=0); j -= div)
			{
				(this->array)[j +div] = (this->array)[j];
			}
			(this->array)[j + div] = temp;
		}
	}
}
*/

void SortTime::ShellSort() 
{
	int i, j, temp;
	int incre = this->arr_num;

	do
	{
		incre = incre / 3 + 1;  // increment sequence
		for (i = incre; i < this->arr_num; ++i)
		{
			if ((this->array)[i] < (this->array)[i - incre])
			{
				temp = (this->array)[i]; // save
				for (j = i - incre; j >= 0 && temp < (this->array)[j]; j -= incre)
					(this->array)[j + incre] = (this->array)[j]; // back
				(this->array)[j + incre] = temp; // insert
			}
		}
	}
	while (incre > 1);
}


// 4 heap sort,from big to small
void HeapAdjust(int** arr, int index, int size)
{
	int min;
	while (index * 2 + 1 < size)
	{
		min = index * 2 + 1;
		if (index * 2 + 2 < size)
			if ((*arr)[min] > (*arr)[index * 2 + 2])
				min = index * 2 + 2;
		if ((*arr)[index] < (*arr)[min])
			break;
		else
		{
			swap((*arr)[index], (*arr)[min]);
			index = min;
		}
	}
}

void SortTime::HeapSort() 
{
	int i;		
	int size = this->arr_num;
	for (i = this->arr_num / 2 - 1; i >= 0; i--)
		HeapAdjust(&(this->array), i, this->arr_num);
	for (i = size - 1; i >= 1; i--)
	{
		swap((this->array)[0], (this->array[i]) );
		size--;
		HeapAdjust(&(this->array), 0, size);
	}
	//this->arr_num = size;
}

// 5 quikcd sort
void QSort(int** arr, int left, int right)
{
	if (left < right)	
	{
		int key = (*arr)[left];
		int low = left;
		int high = right;
		while (low < high)
		{
			while (low < high && (*arr)[high] >= key)
				high--;
			(*arr)[low] = (*arr)[high];

			while (low < high && (*arr)[low] <= key)
				low++;
			(*arr)[high] = (*arr)[low];
		}
		(*arr)[low] = key;
		QSort(arr, left, low - 1);
		QSort(arr, low + 1, right);
	}
}

void SortTime::QuickSort()
{
	QSort(&(this->array), 0, this->arr_num -1);
}
