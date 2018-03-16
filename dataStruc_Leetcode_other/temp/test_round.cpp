#include <iostream>
#include <math.h>
#include <stdint.h>

int main()
{
    double a = 0.13096013162794407e-10;
    int32_t _a = round(a * 1000000000);

    long double b = 0.13096013162794407e-10;
    int32_t _b = roundl(b * 1000000000);

    std::cout << "round: " << _a << std::endl;
    std::cout << "roundl: " << _b << std::endl;

    double num = 1064.4000000000001;

    int64_t day = num;
    int8_t hour = (num - day) * 24;  // double -> int8_t
    int8_t minute = ((num - day) * 24 - hour) * 60;
    int8_t second = (((num - day) * 24 - hour) * 60 - minute) * 60;
    int32_t fractionalsecond = round(
            ((((num - day) * 24 - hour) * 60 - minute) * 60 - second)
            * 1000000000); 
    double fracDou = (((num - day) * 24 - hour) * 60 - minute) * 60 - second;
    double fracTemp = fracDou * 1000000000;
    int32_t  fracInt = fracDou * 1000000000;

    std::cout << "fracDou: " << fracDou << std::endl;
    std::cout << "fracTemp: " << fracTemp << std::endl;
    std::cout << "fracInt: " << fracInt << std::endl;
    std::cout << "fractionalsecond: " << fractionalsecond << std::endl;

    return 0;
}
