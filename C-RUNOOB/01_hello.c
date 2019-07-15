#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// struct tm
// {
//     int tm_sec; /* 秒，正常范围 0-59， 但允许至 61*/
//     int tm_min; /* 分钟，0-59*/
//     int tm_hour; /* 小时， 0-23*/
//     int tm_mday; /* 日，即一个月中的第几天，1-31*/
//     int tm_mon; /* 月， 从一月算起，0-11*/
//     int tm_year; /* 年， 从 1900 至今已经多少年 */
//     int tm_wday; /* 星期，一周中的第几天， 从星期日算起，0-6*/
//     int tm_yday; /* 从今年 1 月 1 日到目前的天数，范围 0-365*/
//     int tm_isdst; /* 日光节约时间的旗标 */
// };

int main()
{
    time_t time1 = 0;
    struct tm *tmp_time1;
    char s[100] = {0};

    /* 我的第一个 C 程序 */
    printf("Hello World!\n");
    tmp_time1 = gmtime(&time1);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", tmp_time1);
    printf("%d:%s\n", (int)time1, s);

    printf("%d\n", sizeof(s));
    memset(s, 0, sizeof(s));
    
    struct tm *tmp_time2 = (struct tm *)malloc(sizeof(struct tm));
    // strptime("19700101080000", "%Y%m%d%H%M%S", tmp_time2); // can't use strptime
    tmp_time2->tm_sec = 0;
    tmp_time2->tm_min = 0;
    tmp_time2->tm_hour = 8;
    tmp_time2->tm_mday = 1;
    tmp_time2->tm_mon = 0;
    tmp_time2->tm_year = 70;
    // tmp_time2->tm_wday = 0;
    // tmp_time2->tm_yday = 0;
    // tmp_time2->tm_isdst = 0;
    time_t time2 = mktime(tmp_time2);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", tmp_time2);
    printf("%d:%s\n", (int)time2, s);
    free(tmp_time2);

    return 0;
}