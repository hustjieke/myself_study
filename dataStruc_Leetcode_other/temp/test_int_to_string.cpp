#include <iostream>
#include <sstream>

int main()
{
    int a = 123;
    std::ostringstream os;
    os << a;

    std::string str = os.str();
    std::cout << "str: " << str << std::endl;

    return 0;
}
