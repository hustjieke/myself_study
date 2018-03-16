// share_ptr指针模板的简单使用
//
#include <iostream>
//#include <boost/shared_ptr.hpp>
#include <boost/smart_ptr.hpp>
#include <string>

using std::string;
using boost::shared_ptr;


int main()
{
    string str = " ";
    //shared_ptr<string> p1(" ");// 之所以不能这么用，因为别人本身就是动态内存，必须new啊！！！
    shared_ptr<int> p2(new int(1024));
    shared_ptr<string> p1(new string("")); // " "这个字符串不是为空的,含有空格！！
    if (p1 && p1->empty()) {
        *p1 = "hi";
    }

    std::cout << *p1 << std::endl;

    return 0;
}
