#include <iostream>
#include <string>

int main()
{
    std::string hdfsAssignedPath("/Compaction/TaskAssigned/");
    std::string fullPath = hdfsAssignedPath + "puId/taskIdToStr/TaskInfo";

    fullPath.erase(0, hdfsAssignedPath.size());
    std::string::size_type firstSep = fullPath.find_first_of("/");
    std::string subStr = fullPath.substr(0, firstSep);

    std::cout << "subStr: " << subStr << std::endl;
    return 0;
}
