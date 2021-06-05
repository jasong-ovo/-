#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>

#define MAXN 101
#define MAX(a,b) a>b?a:b

using namespace std;

int dp[MAXN][MAXN];


void init(){
    memset(dp, 0, MAXN * MAXN * sizeof(int));
    return ;
}


int main(){
    init();
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    int l1, l2;
    l1 = str1.length();
    l2 = str2.length();

    for (int i=1; i<=l1; i++){
        for (int j=1; j<=l2; j++){
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    printf("%d", dp[l1][l2]);
    return 0;
}