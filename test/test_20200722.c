#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 求程序运行结果 */
struct S
{
    int *p;
    int *p2;
};

int main()
{
    struct S mys;
    int *ｐ = &mys.p; // error, int *ｐ = mys.p
    p[0] = 1; // error，指针不能像数组这样操作
    p[1] = 2; // error

    return 0;
}

/* 编译不通过 */
