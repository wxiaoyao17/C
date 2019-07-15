#include <stdio.h>

int main()
{
    char i;
    char *p = NULL;

    p = &i;
    *p = 0x12345678L;
}