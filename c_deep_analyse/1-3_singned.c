#include <stdio.h>
#include <string.h>

int main()
{
    signed char a[1000];
    int i;
    int m = -20;
    unsigned int n = 10;

    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d\n", strlen(a));
    /* strlen是取字符串长度，直到结束符‘\0’（ASCII码为0），也就是说在数组a中遍历，直到0为止时的长度 
        a[i] = -1 - i = 0; => i = -1; => 0xFF(255)
     */

    printf("%d \n", m + n); // 自动类型转换？

    return 0;
}