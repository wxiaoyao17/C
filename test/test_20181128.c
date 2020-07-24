#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // char given_name[40];
    // char family_name[40];

    // char *given_name;
    // char *family_name;
    
    char *given_name = NULL;
    char *family_name = NULL;

    // char *given_name = "abc";
    // char *family_name = "xyz";

    /* 指针在使用的时候要初始化，给一个有效可用的地址进行存储 */
    given_name = (char*)malloc(10);
    family_name = (char*)malloc(10);

    printf("please enter your given_name:\n");
    scanf("%s", given_name);

    printf("please enter your family_name:\n");
    scanf("%s", family_name);

    /* *a只是指向一个字符 */
    printf("your name is %c,%c\n", *family_name, *given_name);
    
    printf("your name is %s,%s\n", family_name, given_name);

    return 0;
}
