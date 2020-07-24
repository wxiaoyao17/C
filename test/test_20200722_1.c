#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 计算二进制数 x 中 1 的个数 */
int foo(x)
{
    int count = 0;

    while (x)
    {
        count++;
        x = x & (x - 1); // 将 x 的二进制数最右边的 1 变成 0
    }

    return count;
}

int main()
{
    int num = 2015;
    int result = 0;

    result = foo(num);
    printf("%d", result);

    return 0;
}
