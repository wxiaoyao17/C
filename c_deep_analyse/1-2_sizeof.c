#include <stdio.h>

int b[100];

void fun(int b[100])
{
    printf("size of b = %d\n", sizeof(b));
}

int main(void)
{
    int i;
    int *p = NULL;
    int a[100];

    printf("size of int = %d\n", sizeof(int));
    printf("size of i = %d\n", sizeof i); // i可以不带括号，但是int必须带
    printf("size of &i = %d\n", sizeof(&i)); // i可以不带括号，但是int必须带
    printf("size of p = %d\n", sizeof(p));
    printf("size of *p = %d\n", sizeof(*p));
    printf("size of a = %d\n", sizeof(a));
    printf("size of a[100] = %d\n", sizeof(a[100]));
    printf("size of &a = %d\n", sizeof(&a));
    printf("size of &a[0] = %d\n", sizeof(&a[0]));

    fun(b);

    return 0;
}
