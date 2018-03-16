#include <time.h>
#include <iostream>

using namespace std;

int main()
{
    struct timespec tv_time;
    int ret_val = clock_gettime(CLOCK_REALTIME, &tv_time); // 导入的参数有很多，分析下他们的区别
    if (ret_val) {
        cout << "wrong" << endl;
    }

    cout << "seconds: " << tv_time.tv_sec << "nano: " << tv_time.tv_nsec << endl;

    struct tm clock;
    localtime_r(&tv_time.tv_sec, &clock);
    cout << 1900 + clock.tm_year << "-";
    cout << 1 + clock.tm_mon << "  ";
    cout << clock.tm_mday << ":";
    cout << clock.tm_hour << ":";
    cout << clock.tm_min << ":";
    cout << clock.tm_sec << ":" << endl;

    return 0;
}
