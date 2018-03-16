#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main()
{
    int size = getpagesize();
    std::cout << "size = " << size << std::endl;
}
