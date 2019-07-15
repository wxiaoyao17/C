#include <stdio.h>
typedef long long int time64;
/* 
将64位时间戳转化为时间数组 
*/
void transformToDate(time64 timeStamp, time64 **dateArry)
{
    time64 low, high, mid, t;
    time64 year, month, day, hour, minute, second, milliSecond;
    time64 daySum[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    time64 milOfDay = 24 * 3600 * 1000;
    time64 milOfHour = 3600 * 1000;

    /*防止超过9999-12-31 23:59:59:999*/
    if (timeStamp > 315537897599999)
    {
        timeStamp = 315537897599999;
    }

    low = 1;
    high = 9999;

    while (low <= high)
    {
        mid = (low + high) >> 1;
        t = ((mid - 1) * 365 + (mid - 1) / 4 - (mid - 1) / 100 + (mid - 1) / 400) * milOfDay;

        if (t == timeStamp)
        {
            low = mid + 1;
            break;
        }
        else if (t < timeStamp)
            low = mid + 1;
        else
            high = mid - 1;
    }
    year = low - 1;
    timeStamp -= ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) * milOfDay;

    int isLeapYear = ((year & 3) == 0 && year % 100 != 0) || year % 400 == 0;

    for (month = 1; (daySum[month] + ((isLeapYear && month > 1) ? 1 : 0)) * milOfDay <= timeStamp && month < 13; month++)
    {
        if (isLeapYear && month > 1)
            ++daySum[month];
    }
    timeStamp -= daySum[month - 1] * milOfDay;

    day = timeStamp / milOfDay;
    timeStamp -= day * milOfDay;

    hour = timeStamp / milOfHour;
    timeStamp -= hour * milOfHour;

    minute = timeStamp / 60000;
    timeStamp -= minute * 60000;

    second = timeStamp / 1000;
    milliSecond = timeStamp % 1000;

    *dateArry[0] = year;
    *dateArry[1] = month;
    *dateArry[2] = day;
    *dateArry[3] = hour;
    *dateArry[4] = minute;
    *dateArry[5] = second;
    *dateArry[6] = milliSecond;
}
//将64位时间戳转化为时间字符串
void transformToDateString(time64 timeStamp, char *dateString)
{
    time64 year, month, day, hour, minute, second, milliSecond;
    time64 *intp[] = {&year, &month, &day, &hour, &minute, &second, &milliSecond};

    transformToDate(timeStamp, intp);

    sprintf(dateString, "%.4I64d-%.2I64d-%.2I64d %.2I64d:%.2I64d:%.2I64d:%.3I64d",
            year, month, day + 1, hour, minute, second, milliSecond);
}
int main()
{
    time64 time;
    char date[256];
    scanf("%lld", &time);
    transformToDateString(time, date);
    printf("date= %s\n", date);
    return 0;
}