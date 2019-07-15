#include <stdio.h>

int main()
{
    char tab[4] = {0x01, 0x02, 0x03, 0x04};
    int b;

    memcpy(&b, tab, sizeof(b));
    printf("b = %x \n", b);

    return 0;
}