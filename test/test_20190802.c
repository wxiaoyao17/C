#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int val;
    char *str;
} test;

void fun(test *pTest);

void fun(test *pTest)
{
    test *pT1 = pTest;

    printf("long str = %llu\n", strlen(pT1->str));
    printf("str:%s,val = %d\n", pT1->str, pT1->val);
}

int main(int argc, char **argv)
{
    const char *str = "helloisme"; //argv[1];
    int val = 12;
    test T1;
    // T1.str = (char *)malloc(sizeof(char) * 10);
    T1.str = (char *)malloc(strlen(str) + 1);

    T1.val = val;
    // memcpy(&(T1.str), str, sizeof(str));
    strcpy(T1.str, str);
    fun(&T1);

    free(T1.str);
    return 1;
}
