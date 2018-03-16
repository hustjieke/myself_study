// 位运算
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned char ch_temp[3];

    ch_temp[0] = 0x87; // 1000 0111
    ch_temp[1] = 0x77; // 0111 0111
    ch_temp[2] = 0xEF; // 1110 1111

    unsigned char ch_0 = ch_temp[0] & 0x07; // 取低三位
    unsigned char ch_1 = ch_temp[1] & 0xF0; // 取高四位
    unsigned char ch_2 = ch_temp[2] & 0x0F; // 取低四位
    cout << "ch_0: " << (bitset<8>)ch_0 << endl // 0000 0111
        << "ch_1: " << (bitset<8>)ch_1 << endl  // 0111 0000
        << "ch_2: " << (bitset<8>)ch_2 << endl; // 0000 1111

    // 将ch_0、ch_1、ch_2重新组合成一个无符号整型数 
    // 组合方式: 00000000 00001111 01110000 00000111
    unsigned int value = (unsigned int)(ch_0 & 0x000000FF)
        + (unsigned int)((ch_1 & 0x000000FF) << 8) 
        + (unsigned int)((ch_2 & 0x000000FF) << 16);
    // value = 00000000 00001111 01110000 00000111
    cout << "重新组合后二进制：" << endl;
    cout << (bitset<sizeof(int) * 8>)value << endl;   

    return 0;
}
