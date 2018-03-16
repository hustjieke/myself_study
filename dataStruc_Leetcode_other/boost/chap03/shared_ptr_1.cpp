// simple using of shared_ptr 
//

#include <boost/shared_ptr.hpp>
#include <assert.h>

using boost::shared_ptr;

int main()
{
    shared_ptr<int> sp(new int(10)); // sp pointed to an int number 
    assert(sp.unique());

    shared_ptr<int> sp2 = sp; // using copy constructor function

    assert(sp == sp2 && sp.use_count() == 2); // quote counts:2

    *sp2 = 100;
    assert(*sp == 100);

    sp.reset();  // stop using shared_ptr
    assert(!sp);  // sp now is nullptr

    return 0;
}
