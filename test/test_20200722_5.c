#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 字符串按单词逆序，比如 My name is Tom，转换为 Tom is name My */
/* 1. 先将整个字符串逆序，方法是左右两边依次互换，然后向中间移动，直到两个指针相遇
 * 2. 以空格为单位，将单词逆序回来
 */
char *reverse(char *str)
{
    char *result = str;
    char *left = str;
    char *right = str + strlen(str) - 1;

    while (left < right)
    {
        // char *tmp = left; // 错误写法，因为 tmp 和 left 指向同一个地址，*left 改变后，*tmp 也改变了
        char tmp;
        tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }

    return result;
}

char *reverseWords(char *str)
{
    char *ptr = str;
    int start = 0; // 记录下一个单词开始的地址
    int i = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (*ptr == ' ') // 分割单词
        {
            *ptr = '\0'; // 空格替换为字符串终止符，方便调用 char *reverse(char *str)
            reverse(str + start); // 将单个单词逆序回来
            *ptr = ' '; // 还原空格
            start = i + 1; // 记录下一个单词开始的地址
        }
        else if (i == strlen(str) - 1) // 最后一个单词的处理，没有空格
        {
            reverse(str + start);
            break;
        }
        ptr++;
    }

    return str;
}

int main()
{
    char str[] = "You love China";

    // printf("%s\n", reverse(str));
    printf("%s", reverseWords(reverse(str)));

    return 0;
}
