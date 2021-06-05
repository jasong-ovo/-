#include <cstdio>
#include <iostream>
#include <memory.h>

#define MIN(a,b) a<b?a:b
using namespace std;

int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    int stamps[N];
    int dp[M+1];
    memset(stamps, 0, N*sizeof(int));

    for (int i=0; i<N; i++){
        scanf("%d", &stamps[i]);
    }
    
    for (int i=0; i<M+1; i++){
        dp[i] = 101;
    }

    dp[0] = 0;
    for (int i=0; i<N; i++){
        for (int j=M; j>=stamps[i]; j--){
            dp[j] = MIN(dp[j], dp[j-stamps[i]]+1);
        }
    }

    if (dp[M] == 101) dp[M]=0;
    printf("%d", dp[M]);
    return 0;
}