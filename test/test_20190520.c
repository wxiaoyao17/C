#include <stdio.h>

void fun(int i, int j)
{
    printf("%d, %d\n", i, j);
}

int main()
{
    int k = 1;
    fun(k, k++);
    printf("%d\n", k);

    k = 1;
    fun(k++, k);
    printf("%d\n", k);
    
    return 0;
}