// 普素的讲解,错误的地方还留了言 http://blog.csdn.net/u012050154/article/details/51541380
// 先了解九宫的规则,输入就是一个九宫,这里不测试

#include <iostream>
#include <vector>

class Solution {
public:
    bool isValidSoduku(std::vector<std::vector<char>>& vec) {
        // 先定义一个数组,因为值在1~9,数组长度为9,然后根据其值索引数组
        bool array[9];
        // 按对角线1~9递增分别检查行和列
        for (int i = 0; i < 9; i++) {
            // 检查行
            std::fill(array, array + 9, false);
            for (int j = 0; j < 9; ++j) {
                if (!check(vec[i][j], array)) {
                    return false;
                }
            }

            // 检查列
            std::fill(array, array + 9, false);
            for (int j = 0; j < 9; ++j) {
                if (!check(vec[j][i], array)) {
                    return false;
                }
            }
        }  // for loop end

        // 检查小九宫所有的数字不重复,不是按行跟列不重复的要求
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                // 检查小九宫
                std::fill(array, array + 9, false);
                for (int i = 3 * row; i < 3 * row + 3; i++) {
                    for (int j = 3 * col; j < 3 * col + 3; j++) {
                        if (!check(vec[i][j], array)) {
                            return false;
                        }
                    }  // j
                }  // i
            }  // col
        }  // row
    }

    bool check(char c, bool array[9]) {
        // if ((c - '1') < 0 || (c - '1') > 9 ) {
        // }  // 我觉得应该加上对1~9范围的值进行确认
        if (c = '.') {
            return true;
        }

        if (array[c - '1']) {
            return false;
        } else {
            array[c -'1'] = true;
            return true;
        }
    }
};

int main()
{
    return 0;
}
