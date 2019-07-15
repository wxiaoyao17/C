#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// struct tm
// {
//     int tm_sec; /* �룬������Χ 0-59�� �������� 61*/
//     int tm_min; /* ���ӣ�0-59*/
//     int tm_hour; /* Сʱ�� 0-23*/
//     int tm_mday; /* �գ���һ�����еĵڼ��죬1-31*/
//     int tm_mon; /* �£� ��һ������0-11*/
//     int tm_year; /* �꣬ �� 1900 �����Ѿ������� */
//     int tm_wday; /* ���ڣ�һ���еĵڼ��죬 ������������0-6*/
//     int tm_yday; /* �ӽ��� 1 �� 1 �յ�Ŀǰ����������Χ 0-365*/
//     int tm_isdst; /* �չ��Լʱ������ */
// };

int main()
{
    time_t time1 = 0;
    struct tm *tmp_time1;
    char s[100] = {0};

    /* �ҵĵ�һ�� C ���� */
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