#include <iostream>

using namespace std;

static inline void swap(int& a, int& b) {
    int tmp = a; a = b; b = tmp;
}

void bubbleSort(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; (j > i) && (a[j] < a[j-1]); j--) {
            swap(a[j], a[j-1]);
        }
    }
}

int main()
{
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "before sort a[10]: ";
    for (int i = 0; i < 10; i++) {
        cout << " " << a[i];
    }
    cout << endl;

    bubbleSort(a, 10);

    cout << "after sort a[10]: ";
    for (int i = 0; i < 10; i++) {
        cout << " " << a[i];
    }
    cout << endl;

    return 0;
}
