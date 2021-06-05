#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int dp[N];
    memset(dp, 0, N * sizeof(int));
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i<N ;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("%d\n", dp[N-1]);
    return 0;
}