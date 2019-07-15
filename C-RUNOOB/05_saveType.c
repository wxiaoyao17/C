#include <stdio.h>

/* 存储类：auto, register, static, extern */

/* 默认存储类为auto */
int mount;
// auto int mount1;

/* register存储用于定义存储在寄存器中而不是RAM中的局部变量，大小为一个寄存器的大小 WORD, 且不能用‘&’运算符，因为没有内存位置*/
// register int miles;

/* static静态变量，若是局部变量，可以在函数调用之间保持局部变量的值，若是全局变量，作用域就在声明它的文件中 */
static int count1 = 10; // 全局变量，默认static

void fun1(void)
{
    /* thingy 是局部变量，只初始化一次，每次调用fun1的时候，值不会重置 */
    static int thingy = 5;
    thingy++;
    printf("thingy 为 %d , count 为 %d \n", thingy, count1);
}

int main(void)
{
    while (count1--)
    {
        fun1();
    }
    return 0;
}

#if 0
int main(void)
{
    
    return 0;
}
#endif
