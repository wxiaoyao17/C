#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 在一个 N 个整数数组里面，有多个奇数和偶数，设计一个排序算法，令所有的奇数都在左边。
请完成 sort 的代码实现
例如： 当输入 a = {8,4,1,6,7,4,9,6,4}，
a = {1,7,9,8,4,6,4,6,4} 为一种满足条件的排序结果 */
/* 从数组的左右两边开始往中间扫，左边遇到偶且右边遇到奇，则左右调换，若一边遇到奇或偶则继续往前走，知道左右相遇结束。最差时间复杂度 O (N), 最好在 O (N/2) 能完成 */
void sort(int N, int a[])
{
    int left = 0;
    int right = N - 1;
    int tmp = 0;
    while (left < right)
    {
        if ((a[left] % 2 == 0) && (a[right] % 2 == 1))
        {
            tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
            left++;
            right--;
        }
        else if ((a[left] % 2 == 0) && (a[right] % 2 == 0))
        {
            right--;
        }
        else if ((a[left] % 2 == 1) && (a[right] % 2 == 1))
        {
            left++;
        }
        else
        {
            left++;
            right--;
        }
    }
}

int main()
{
    int a[9] = {8, 4, 1, 6, 7, 4, 9, 6, 4};
    int i = 0;

    sort(sizeof(a) / sizeof(int), a);
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
