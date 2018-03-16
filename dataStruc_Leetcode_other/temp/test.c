#include <stdio.h>

int func () {
    const int src[16] = {0};
    int val1 = 0;
    int dst[16] = {0};
    int val2 = 0;
    fprintf(stdout, "size of src = %lu\n", sizeof (src));

    return 0;
}
int main()
{
    func();
    return 0;
}
