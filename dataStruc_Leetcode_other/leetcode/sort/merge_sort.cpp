//build: g++ -std=c++11 merge_sort.cpp -g
#include <iostream>

void merge(int arr[], int start, int mid, int end) {
    int arrSize = end - start + 1;
    int *tmpArray = new int[arrSize];
    int i(start), j(mid+1), k(0);
    while ((i <= mid) && (j <= end)) {
        (arr[i] <= arr[j]) ? (tmpArray[k++] = arr[i++]) : (tmpArray[k++] = arr[j++]);
    }
    while (i <= mid) {  // considering arrSize may be 1, it means i may be equal to mid
        tmpArray[k++] = arr[i++];
    }
    while (j <= end) {  // the same as above
        tmpArray[k++] = arr[j++];
    }

    // print merge begin
    std::cout << "start=" << start << " mid=" << mid << " end=" << end;
    std::cout << "merge: ";
    for (int idx = 0; idx < arrSize; idx++) {
        std::cout << tmpArray[idx];
    }
    std::cout << std::endl;
    // print end

    for (int i = 0; i < arrSize; i++) {
        arr[start+i] = tmpArray[i];  // start+i
    }

    delete []tmpArray;
}

void mergeSort(int arr[], int start, int end) {
    if (!arr)
        std::cout << "arr == NULL" << std::endl;

    if (start >= end)  // atention!! if start = end, it means the arr just has 1 member
        return;

    int mid = (end + start) >> 1;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int arr1[10] = {1, 4, 5, 3, 2, 7, 9, 6, 8, 10};
    int arr2[9] = {1, 4, 5, 3, 2, 7, 9, 6, 8};

    int start(0), end(9);
    int start2(0), end2(8);

    mergeSort(arr1, start, end);
    std::cout << "result: ";
    for (auto idx : arr1) {
        std::cout << idx;
    }
    std::cout << std::endl << std::endl;

    mergeSort(arr2, start2, end2);
    std::cout << "result: ";
    for (auto idx : arr2) {
        std::cout << idx;
    }
    std::cout << std::endl;

    return 0;
}
