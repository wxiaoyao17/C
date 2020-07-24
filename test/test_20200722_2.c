#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
  * 一个长度为n的整数数组result，满足result[i]=除input[i]之外所有数的乘积（不溢出），比如 
  * 输入input={2,3,4,5};输出 result={60,40,30,24}; 
*/
/* 
  * 方法一：判断有0的情况，如果有0则其他都为0.如果没0,可使用先求全部乘积，再除以自身。 
  * 方法二：先保存i位置前的乘积到result[i]，再用一变量保存i位置后的乘积，结果相乘，即可。 
*/
int *cal(int *input, int n)
{
    int result[4] = {0};
    result[0] = 1;
    int back = 1;
    int i;

    if (n <= 0)
    {
        return 0;
    }

    for (i = 1; i < n; i++) // 从1位置开始，result[i]表示input i位置前的乘积
    {
        result[i] = result[i - 1] * input[i - 1];
    }
    for (i = n - 2; i >= 0; --i)
    {
        back *= input[i + 1];
        result[i] *= back;
    }

    for (i = 0; i < 4; i++) // 从倒数第二个开始，q表示input i位置后的乘积
    {
        printf("%d ", result[i]);
    }

    return 0;
}

int main()
{
    int input[] = {2, 3, 4, 5};
    int length = sizeof(input) / sizeof(int);
    *cal(input, length);

    return 0;
}
