#include <ctime>
#include <iostream>
#include <boost/random.hpp>

using namespace std;
int main()
{
    boost::mt19937 gen;                                     
    boost::uniform_int<> dist(1,6);
    boost::variate_generator<boost::mt19937&,boost::uniform_int<> > die(gen,dist);


    for( int i = 0; i < 10; ++i) {
        std::cout << die() <<std::endl;
    }
    return 0;
}
