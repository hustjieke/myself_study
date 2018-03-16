#include <iostream>
#include <unistd.h>

int main()
{
    // 调用系统函数，获取内存page的大小，一般为4096字节(4k)
    int pageSize = getpagesize();

    std::cout << "mem page size = " << pageSize << std::endl;

    return 0;
}
