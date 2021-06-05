#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;


int checkIn(char **p, char target, int loc, int counter){
    int idx = -1;
    for (int i=0; i<counter ; i++){
        if (p[i][0] == target) {
            p[i][p[i][101]] = loc;
            p[i][101] ++;
            return 0;
        }
        idx = i;
    }
    idx ++;

    // printf("idx:%d\n", idx);
    p[idx] = (char*) malloc(102*sizeof(char));
    memset(p[idx], '\0', 102);
    p[idx][0] = target;
    p[idx][101] = 2;
    p[idx][1] = loc;
    // printf("new\n");
    return 1;
}


void dump(char* p){
    for (int i=0; i<102 ; i++){
        printf("%c\t", p[i]);
    }
    printf("\n");
}

int main(){
    //init
    char arr[100] = {'\0'};
    scanf("%s", arr);

    //find and insert repeative char
    char **repeatChars;
    int idx_rC = 0;
    int counter = 0;
    repeatChars = (char **) malloc(100*sizeof(char *));
    memset(repeatChars, '\0', 400);
    for (int i=0; arr[i] != '\0'; i++){
        counter += checkIn(repeatChars, arr[i], i, counter);
    }

    //debug
    // for (int i=0; i<counter; i++){
    //     dump(repeatChars[i]);
    // }

    //print
    // printf("0:1char:%d\n",repeatChars[0][1]);
    for (int i=0; i<counter; i++){
        if (repeatChars[i][101] == 2) continue;
        for (int j=1; (repeatChars[i][j] != '\0' || (i == 0 && j == 1)) && j<101; j++) {
            printf("%c:%d", repeatChars[i][0], repeatChars[i][j]);
            if (repeatChars[i][j+1] != '\0') printf(",");
        }
        printf("\n");

    }
    return 0;
}