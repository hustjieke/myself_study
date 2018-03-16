// 测试mysql中decimal宏定义值
#include <iostream>
#include <stdint.h>

typedef long long int dec2;
#define DIG_PER_DEC1 9
#define DIG_BASE     1000000000
#define DIG_BASE2    ((dec2)DIG_BASE * (dec2)DIG_BASE)
#define ROUND_UP(X)  (((X)+DIG_PER_DEC1-1)/DIG_PER_DEC1)

static const int dig2bytes[DIG_PER_DEC1+1]={0, 1, 1, 2, 2, 3, 3, 4, 4, 4};
int main()
{
    std::cout << "gry: " << DIG_BASE2 << std::endl;
    std::cout << "size of long long int: " << sizeof(long long int) << std::endl;

    std::cout << "round up 0.6: " << ROUND_UP(0.6) << std::endl;
    std::cout << "round up 8.6: " << ROUND_UP(8.6) << std::endl;

    int precision = 11, scale = 3;
    int intg = precision-scale;
    int intg0=intg/DIG_PER_DEC1, frac0=scale/DIG_PER_DEC1,
        intg0x=intg-intg0*DIG_PER_DEC1, frac0x=scale-frac0*DIG_PER_DEC1;
    int temp = intg0*sizeof(int)+dig2bytes[intg0x] + frac0*sizeof(int)+dig2bytes[frac0x];

    return 0;
}
