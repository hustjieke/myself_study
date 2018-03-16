// More complex shared_ptr using 

#include <boost/shared_ptr.hpp>

using boost::shared_ptr;

class shared {
    private:
        shared_ptr<int> m_p;  // one class member of shared_ptr

    public:
        shared(shared_ptr<int> p_):m_p(p_) { } // constructor init m_p

        void print() {
            std::cout << "count:" << m_p.use_count()
                << " v = " << *m_p << std::endl;
        }
};

void print_func(shared_ptr<int> p) {
    std::cout << "count: " << p.use_count() 
        << " v = " << *p << std::endl;
}

int main()
{
    shared_ptr<int> p(new int(100));
    shared s1(p), s2(p);

    s1.print();
    s2.print();

    *p = 20;
    print_func(p);

    s1.print();

    return 0;
}
