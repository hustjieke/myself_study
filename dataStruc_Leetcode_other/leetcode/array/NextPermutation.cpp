// 普素的讲解,见 https://www.cnblogs.com/luruiyuan/p/5914909.html
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void nextPermutation(std::vector<int>& num) {
        next_permutation(num.begin(), num.end());
    }
    
private:
    template<typename BidiIt>
    bool next_permutation(BidiIt first, BidiIt last) {
        // 反转迭代器,从后往前移动
        const auto rfirst = std::reverse_iterator<BidiIt>(last);
        const auto rlast  = std::reverse_iterator<BidiIt>(first);
        
        auto pivot = std::next(rfirst);  // 仔细看网络上的讲解,实际位指和逻辑指向值是不一样的
        while (pivot != rlast && (*pivot < *std::prev(pivot))) {
            ++pivot;
        }
        
        if (pivot == rlast) {  // 说明是逆序,极端情况
            // std::reverse(rfirst, rlast);
            reverse(rfirst, rlast);
            return false;
        }

        auto change = std::find_if(rfirst, pivot, binkd1st(less<int>(), *pivot));
        
        // swap(*pivot, *change);
        swap(pivot, change);
        std::reverse(rfirst, pivot);

        return true;
    }
};
