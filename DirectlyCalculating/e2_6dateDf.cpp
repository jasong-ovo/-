#include <iostream>
#include <cstdio>

using namespace std;

int month_day[2][12] ={
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool isLeapYear(int year){
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

int main(){
    int year1, month1, day1,
        year2, month2, day2;
    char date1[8], date2[8];
    int diff_days;
    bool leapYear;

    //wrong, using for/while to getchar
    // scanf("%s", date1);
    // getchar();
    // scanf("%s", date2);
    
    for (int i=0; i<8; i++) scanf("%c", &date1[i]);
    getchar();
    for (int i=0; i<8; i++) scanf("%c", &date2[i]);

    year1 = (date1[0]-48)*1000 + (date1[1]-48)*100 + (date1[2]-48)*10 + (date1[3]-48)*1;
    year2 = (date2[0]-48)*1000 + (date2[1]-48)*100 + (date2[2]-48)*10 + (date2[3]-48)*1;
    month1 = (date1[4]-48)*10 + (date1[5]-48)*1;
    month2 = (date2[4]-48)*10 + (date2[5]-48)*1;
    day1 = (date1[6]-48)*10 + (date1[7]-48)*1;
    day2= (date2[6]-48)*10 + (date2[7]-48)*1;

    //represent the minimal date
    bool min_year1 = false;

    //decide the minimal year
    if (year1 != year2) {
        min_year1 = (year1 > year2) ? false : true;

        int start_year, start_month, start_day, end_year, end_month, end_day;
        int days_min = 0, days_max = 0;
        start_year = (min_year1) ? year1 : year2;
        end_year = (min_year1) ? year2 : year1;
        start_month = (min_year1) ? month1 : month2;
        end_month = (min_year1) ? month2 : month1;
        start_day = (min_year1) ? day1 : day2;
        end_day = (min_year1) ? day2 : day1;

        //caculate days min
        leapYear = isLeapYear(start_year);
        for (int i=0; i<start_month-1; i++) days_min += month_day[leapYear][i];
        days_min += start_day;
        //caculate days max
        for (int i=start_year; i<end_year; i++) {
            leapYear = isLeapYear(i);
            if (leapYear) days_max += 1;
            days_max += 365;
        }
        leapYear = isLeapYear(end_year);
        for (int i=0; i<end_month-1; i++) days_max += month_day[leapYear][i];
        days_max += end_day;
        printf("days_max:%d\ndays_min:%d\n", days_max, days_min);
        diff_days = days_max - days_min + 1;
    }
    else if (month1 != month2) {
        min_year1 = (month1 > month2) ? false : true;
        leapYear = isLeapYear(year1);

        int days1 = 0, days2 = 0;
        for (int i=0; i<month1-1; i++) days1 += month_day[leapYear][i];
        days1 += day1;
        for (int i=0; i<month2-1; i++) days2 += month_day[leapYear][i];
        days2 += day2;

        diff_days = (min_year1) ? (days2-days1) : (days1-days2);
        diff_days += 1;
    }
    else{
        diff_days = (day1>day2) ? (day1-day2) : (day2-day1);
        diff_days += 1;
    }

    printf("%d", diff_days);



    return 0;
}