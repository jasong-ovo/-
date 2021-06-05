#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;


int month_day[2][12] ={
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


bool isLeapYear(int year){
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}


int monthTranslater(char *p){
    if (!strcmp(p, "January")) {
        return 1;
    }
    else if (!strcmp(p, "February")){
        return 2;
    }
    else if (!strcmp(p, "March")){
        return 3;
    }
    else if (!strcmp(p, "April")){
        return 4;
    }
    else if (!strcmp(p, "May")){
        return 5;
    }
    else if (!strcmp(p, "June")){
        return 6;
    }
    else if (!strcmp(p, "July")){
        return 7;
    }
    else if (!strcmp(p, "August")){
        return 8;
    }
    else if (!strcmp(p, "September")){
        return 9;
    }
    else if (!strcmp(p, "October")){
        return 10;
    }
    else if (!strcmp(p, "November")){
        return 11;
    }
    else if (!strcmp(p, "December")){
        return 12;
    }

    return 0;
}


void weekDaysTrans(int weekDay) {
    switch (weekDay)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 4:
        printf("Thursday");
        break;            
    case 3:
        printf("Wednesday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    default:
        break;
    }
}


int main (){
    char month[10];
    int month_i;
    int day;
    int year;
    int days = 0;
    int weekDays;
    scanf("%d ", &day);
    for (int i=0; i<10; i++){
        month[i] = getchar();
        if (month[i] == ' ') {month[i] = '\0'; break;}
    }
    scanf("%d", &year);

    //base on 1 1 1
    month_i = monthTranslater(month);
    for (int i=1; i<year; i++) {
        if (isLeapYear(i)) days++;
        days += 365;
    }
    // printf("%d\n", days);
    for (int i=0; i<month_i-1; i++) {
        days += month_day[isLeapYear(year)][i];
    }
    // printf("%d\n", days);
    days += day - 1;
    // printf("%d\n", days);
    
    weekDays = 1 + days%7;
    weekDaysTrans(weekDays);
    return 0;
}