#include <iostream>
#include <stdexcept>


int main()
{
    try {
        // std::runtime_error ex("error");
        // throw ex;
        throw std::runtime_error("error", __FILE__, __LINE__);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
