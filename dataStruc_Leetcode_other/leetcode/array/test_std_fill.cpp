#include <iostream>

int main()
{
    int array[9];
    std::fill(array, array+9, 1);
    for (auto i : array) {
        std::cout << "i = " << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
