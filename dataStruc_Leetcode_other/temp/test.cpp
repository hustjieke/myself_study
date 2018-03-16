#include <math.h>
#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
/*
int main()
{
    long double month = 999999999.999999999;
    long double month_2 = 999999999.99999;
    long double month_3 = 999999999.55;
    int64_t xxx =  month;
    int64_t xxx_2 = month_2;
    int64_t xxx_3 = month_3;
    cout << "xxx: " << xxx;
    cout << "xxx_2: " << xxx_2;
    cout << "xxx_3: " << xxx_3;
    //long double ret = roundl(month * 12);
    //long int_ret = ret;

    //cout << "double: " << ret << endl;
    //cout << "int: " << int_ret << endl;

    //int64_t tmp = 12345678901234567890123456;
    //cout << "tmp: " << tmp;

    return 0;
}

*/

int main()
{
    char* c_str = new char[10];
    memset(c_str, '\0', 8);
    char tmp_str[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    memcpy(c_str, tmp_str, 8);
    
    string test_str = c_str;

    cout << "c_str: " << c_str << endl;
    cout << "test_str: " << test_str << endl;
    cout << "test_str length: " << test_str.length() << endl;

}
