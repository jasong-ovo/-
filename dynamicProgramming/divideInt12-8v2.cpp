//时间复杂度N，空间复杂度N

#include <iostream>
#include <cstdio>
#include <memory.h>

#define MAXN 1000001

using namespace std;

int M = 1000000000;
int dp[MAXN];

void init(){
    memset(dp, 0, MAXN * sizeof(int));
    dp[1] = 1;
    for (int i=2; i<MAXN; i++) {
        if (i%2 == 0){
            dp[i] = (dp[i-1] + dp[i/2]) % M;
        }
        else {
            dp[i] = dp[i-1];
        }
    }
}

int main(){
    init();
    int N;
    while (scanf("%d", &N) != EOF) {
        printf("%d\n", dp[N]);
    }
    return 0;
}