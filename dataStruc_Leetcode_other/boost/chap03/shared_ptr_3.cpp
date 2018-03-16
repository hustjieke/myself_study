// shared_ptr used in std container

#include <iostream>
#include <vector>
#include <boost/smart_ptr.hpp>
//#include <boost/make_shared.hpp>

using std::vector;
using namespace std;
using boost::shared_ptr;
using boost::make_shared;

int main()
{
    typedef vector<shared_ptr<int> > vs;    // a std container type with shared_ptr
    vs v(10);                               // 声明一个拥有10个元素的容器，元素被初始化为nullptr

    int i = 0;
    //for (auto pos = v.begin(); pos != v.end(); ++pos) { // 编译器不支持auto,最好使用迭代器类型
    for (vs::iterator pos = v.begin(); pos != v.end(); ++pos) {
        (*pos) = make_shared<int>(++i);   // 使用工厂函数赋值
        std::cout << *(*pos) << ", ";
    }
    std::cout << std::endl;

    shared_ptr<int> p = v[9];
    *p = 100;
    std::cout << *v[9] << std::endl;

    return 0;
}
