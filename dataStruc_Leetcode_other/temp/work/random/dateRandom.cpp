#include <iostream>
#include <sstream>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    //uniform_int_distribution<unsigned> u(0, 9);
    //default_random_engine e;

    std::ostringstream oss;
    while (1) {
        while (1) {
            int temp = rand() % 9999;
            if (temp < 9999 && temp > 1900) {
                oss << temp;
                break;
            } else {
                continue;
            }
        }
        int temp = rand();
        for (int i = 0; i < 4; i++) {
            oss << 
        }
    }
    string str = oss.str();
    cout << str << endl;

    return 0;
}
