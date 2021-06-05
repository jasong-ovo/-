//时间复杂度N*logN, 空间复杂度N*logN
#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;


int M = 1000000000;

int pow2(int n){
    int out =1 ;
    while (n--) {
        out *= 2;
    }
    return out;
}

int main(){
    int N;
    scanf("%d", &N);
    int maxR = 1;
    int n=N;
    while (n /= 2) {
        maxR ++;
    }
    int dp[maxR+1][N+1];
    memset(dp, 0, (maxR+1) * (N+1) * sizeof(int));
    for (int i = 0; i<maxR+1; i++){
        dp[i][0] = 1;
    }

    for (int i=1; i<maxR+1; i++) {
        int maxInd = pow2(i-1);
        for (int j=1; j<N+1; j++){
            dp[i][j] = dp[i-1][j] % M;
            if (j >= maxInd) {
                dp[i][j] += dp[i][j-maxInd] % M;
                dp[i][j] = dp[i][j] % M;
            }
        }
    }

    printf("%d", dp[maxR][N]);

    return 0;
}