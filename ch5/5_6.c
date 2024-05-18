#include <stdio.h>

static int day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

day_of_year(year, month, day) /*  set day of year */
    int year,
    month, day; /* from month & day */
{
    int leap;
    int *p;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = day_tab[leap];    
    while (month--) {
        day += *p++;
    }
        
    return (day);
}

month_day(year, yearday, pmonth, pday) /* set month, day */
    int year,
    yearday, *pmonth, *pday; /* from day of year */
{
    int leap, *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = day_tab[leap];
    while (yearday > *p) {
        yearday -= *p++;
    }
    
    *pday = yearday;
    *pmonth = p - *day_tab;    
}

int main(int argc, char const *argv[])
{
    int year, month, day;
    year = 2011;
    month = 3;
    day = 1;
    printf("%d\n", day_of_year(year, month, day));
    month_day(2011, 60, &month, &day);
    printf("%d %d\n", month, day);

    return 0;
}
