#include <unistd.h>
#include <string>
#include <iostream>

int main()
{
    char buff[256];
    gethostname(buff, 256);

    std::cout << "hostname: " << buff << std::endl;

    return 0;
}
