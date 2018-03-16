#include <iostream>
#include <stdlib.h>
#include <math.h>

int main()
{
    // double a(0.511), b(0.1);
    // double c = a - b;
    // std::cout << "c: " << c << std::endl;

    // int d(999999000), e(3);
    // double f = (double)d / 100000000 / 3;
    // std::cout << "f: " << f << std::endl;
    
    double a = 1.0;
    double b = 1.00000000000001;
    //double a = 0.0;
    //double b = 0.000000000000001;
    //double c = 1.00000000000001;
    
    if (fabs(a - b) < 1e-14) {
        std::cout << "a = b" << std::endl;
    } else {
        std::cout << "a != b: " << a-b << std::endl;
    }

    return 0;
}
