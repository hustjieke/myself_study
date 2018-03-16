#include <set>
#include <iostream>

int main()
{
    std::set<std::string>  str_set;

    str_set.insert("gry11");
    str_set.insert("gry21");
    str_set.insert("gry31");
    str_set.insert("gry11");
    str_set.insert("gry21");
    str_set.insert("gry31");

    std::set<std::string>::iterator  itr_begin = str_set.begin();
    std::set<std::string>::iterator  itr_end = str_set.end();

    std::cout << "hello!" << std::endl;
    while (itr_begin != itr_end) {
        std::cout << "hello!" << std::endl;
        std::cout << *itr_begin << std::endl;
        ++itr_begin;
    }

    return 0;
}
