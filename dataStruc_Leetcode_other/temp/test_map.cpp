#include <map>
#include <set>
#include <iostream>
#include <string>

int main()
{
    std::map<std::string, size_t>   word_count;
    //set<std::string> exclude;
    std::set<std::string> exclude = { "The", "but", "an", "or",
        "a"};

    std::string word;
    while (std::cin >> word) {
        if (exclude.find(word) == exclude.end()) {
        ++word_count[word];
        }
    }
    std::map<std::string, size_t>::iterator itr = word_count.begin();
    std::map<std::string, size_t>::iterator itr_end   = word_count.end();
    while (itr != itr_end) {
        std::cout << (*itr).first << " occurs " << (*itr).second
            << (((*itr).second > 1) ? "times" : "time") << std::endl;
        ++itr;
    }

    return 0;
}
