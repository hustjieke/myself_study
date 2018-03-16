#include <iostream>
#include <string>

unsigned int find(const std::string& src, const std::string& pattern,
        unsigned int startIndex) {
    // Get last position
    unsigned lastIndex = src.size() - pattern.size();
    // lastIndex must be bigger than startIndex
    if (startIndex > lastIndex) {
        return -1;
    }

    //for (int g = 0; startIndex < lastIndex; ++g) {
    while (startIndex <= lastIndex) {
        if (pattern == src.substr(startIndex, pattern.size())) {
            return startIndex;
        } else {
            ++startIndex;
            continue;
        }
    }

    return -1;
}

int main()
{
    std::string src = "hustgaoriyao";
    std::string pattern = "gaori";
    std::string patternN  = "gr";
    
    std::cout << src.substr(1, 3) << std::endl;
    int ret = find(src, pattern, 0);
    std::cout << "ret = " << ret << std::endl;
    std::cout << "substr: " << src.substr(ret, pattern.size()) << std::endl;

    int retN = find(src, patternN, 0);
    std::cout << "retN = " << retN << std::endl;

    return 0;
}
