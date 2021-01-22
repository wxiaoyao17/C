#include <stdio.h>

int main(void)
{
    unsigned char arr[] = "0123456789abcdefghijk";

    struct A
    {
        int a;
        char b;
        char c;
        char d;
        int e;
    } p, *pp;

    struct B
    {
        int a;
        char b;
        int c;
    };

    p.a = 1;
    p.b = '2';
    p.c = '3';
    p.d = '4';
    p.e = 5;

    pp = &p;
    printf("pp->a: %d\npp->b: %c\npp->c: %c\npp->d: %c\npp->e: %d\n", pp->a, pp->b, pp->c, pp->d, pp->e);

    printf("**********\n");

    pp = (struct A *)arr;
    printf("pp->a: %d\npp->b: %c\npp->c: %c\npp->d: %c\npp->e: %d\n", pp->a, pp->b, pp->c, pp->d, pp->e);

    return 0;
}