#include <stdio.h>
#include <stdint.h>

struct S
{
    int i;
    int *p;
};

int main(void)
{
    struct S s;
    int *p = &s.i;
    p[0] = 4;
    p[1] = 3;
    s.p[1] = 1;
    s.p[0] = 2;

    return 0;
}