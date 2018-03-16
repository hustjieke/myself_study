#include <string>
#include <vector>
#include <iostream>

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/format.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

int main()
{
    std::string test1 = "/Compaction/TaskAssigned/puID/";
    std::string test2 = "/Compaction/TaskAssigned/puID/receiveID.123.123/taskInfo";
    
    //std::string subStr = test2.substr(test1.size(), index);
    //test2.Remove(0, test1.size());
    std::string::size_type indexTemp = test2.find_last_of("/");
    std::cout << "subStr yyyy: " << test2.substr(test1.size(), indexTemp - test1.size()) << std::endl;


    test2.erase(0, test1.size());
    std::cout << "size of test2: " << test2.size() << std::endl;

    std::string::size_type index = test2.find_last_of("/");
    test2.erase(index, test2.size()-index);

    std::cout << "index: " << index << std::endl;
    std::cout << "subStr: " << test2 << std::endl;
    
    std::vector<std::string> vecStr;
    vecStr.resize(0);
    boost::split(vecStr, test2, boost::is_any_of("."));
    int size = 0;
    BOOST_FOREACH(std::string& item, vecStr) {
        size++;
        std::cout << "index: " << size << " str is: " << item << std::endl;
    }
    int seqNo = boost::lexical_cast<int>(vecStr[1]);
    uint64_t time = boost::lexical_cast<uint64_t>(vecStr[2]);
    std::cout << "seqNo: " << seqNo << std::endl;
    std::cout << "time: " << time << std::endl;
    
    return 0;
}
