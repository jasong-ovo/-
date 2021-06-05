#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int N;
    // int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &N);
    getchar();
    while(N) {
        //init
        N--;
        int year, month, day;
        scanf("%d %d %d", &year, &month, &day);
        getchar();

        //caculate
        day ++;
        switch (day)
        {
        case 29:
            if (month == 2) {
                month ++;
                day = 1;
            }
            break;
        case 31:
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                month ++;
                day = 1;
            }
            break;
        case 32:
            month ++;
            day = 1;
            if (month == 13) {
                year ++;
                month = 1;
            }
            break;
        default:
            break;
        }

        //print
        printf("%d-%d-%d\n", year, month, day);
    }

    return 0;
}