#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int P, T;
    float G1, G2, G3, GJ;
    float score;
    int diff12;

    //init
    scanf("%d %d %f %f %f %f", &P, &T, &G1, &G2, &G3, &GJ);

    diff12 = (G1-G2)>0 ? (G1-G2) : -(G1-G2);
    //case1
    if (diff12 <= T) {
        score = (G1 + G2) / 2;
    }
    //case2 import score G3
    else{
        int diff13, diff23;
        diff13 = (G1-G3)>0 ? (G1-G3) : -(G1-G3);
        diff23 = (G2-G3)>0 ? (G2-G3) : -(G2-G3);
        if (diff13 <= T && diff23 <= T) {
            int max_num;
            max_num = (G1 > G2) ? G1 : G2;
            max_num = (max_num > G3) ? max_num : G3;
            score = max_num;
        }
        else if(diff13 <= T) { 
            score = (G1 + G3) / 2;

        }
        else if(diff23 <= T) {
            score = (G2 + G3) / 2;
        }
        else {
            score = GJ;
        }
    }

    printf("%.1f", score);

    return 0;
}