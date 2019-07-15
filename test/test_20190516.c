#include <stdio.h>

static char buff[5] = {5, 4, 3, 2, 1};

void fun(char *p)
{
    p = buff;
}

int main()
{
    char *p = NULL;
    fun(p); // 为什么执行完后，p还是指向NULL？
    *p = 1;
    
    return 0;
}