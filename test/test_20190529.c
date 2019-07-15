#include <stdio.h>

/* 同类型指针相减，并不是简单的地址值相减，而是指示两个指针之间包含的类型数据个数 */
int main()
{
    int a[10], i;
    int *p, *q;

    for (i = 0; i < 10; i++)
    {
        a[i] = i;    
    }

    p = a;
    q = &a[2];
    // q = a + 2;

    printf("%d \n", a[q-p]);
}