#include <iostream>

void mergeTwoSortedArray(int A[], int m, int B[], int n) {
    if (!A || !B) return;

    int i(m-1), j(n-1), k(m+n-1);
    while (i>=0 && j>=0) {
        // (A[i] > B[j]) ? (A[k--] = A[i--]) : (A[k--] = B[j--]);
        A[k--] = (A[i] >= B[j]) ? A[i--] : B[j--];
    }
    while (j >= 0) {  // 如果是A中还有i>=0,则不用处理
        A[k--] = B[j--];
    }
}


int main()
{
    int A[100], B[10];
    int m(10),n(10);
    for (int i = 0; i < m; i++) {
        A[i] = 2*i + 1;  // 1 3 5 7 ...
    }
    for (int i = 0; i < n; i++) {
        B[i] = 2*i + 2;  // 2 4 6 8 ...
    }

    mergeTwoSortedArray(A, m, B, n);

    std::cout << "print A[]: ";
    for (int i = 0; i < (m+n); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
