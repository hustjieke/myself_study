#include <iostream>
#include <string>
#include <vector>

struct Block {
    explicit Block(int size) : m_data(size), m_size(size) {
    }  // vector容器初始化个数，并且默认初始化为""

    std::vector<std::string> m_data;
    int m_size;
};

int main()
{
    Block block(5);
    std::cout << (block.m_data)[0];

    return 0;
}
