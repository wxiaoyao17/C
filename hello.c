#include <stdio.h>

char string[] = {0b01110100, 0b01100001, 0b01101110, 0b01111001, 0b01110101, 0b01100111, 0b01100001, 0b01101110, 0b01100111, 0b01011111, 0b01100011, 0b01101111, 0b01101101};

// 此程序很简单，仅仅打印一个Hello World的字符串。
int main(void)
{
    printf("Hello World! \n");
    printf("wechat: %s \n", string);
    return 0;
}