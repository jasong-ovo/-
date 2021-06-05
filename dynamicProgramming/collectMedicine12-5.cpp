#include <cstdio>
#include <iostream>
#include <memory.h>

#define MAXN 102
#define MAXT 1000
#define MAX(a,b) a>b?a:b

using namespace std;

int T, M;
int W[MAXN];
int V[MAXN];
int dp[MAXT];


void init(){
    memset(W, 0, sizeof(int) * MAXN);
    memset(V, 0, sizeof(int) * MAXN);
    memset(dp, 0, sizeof(int) * MAXT);
    return;
}


void collect(){
    for (int i=1; i<=M; i++){
        for (int j=T; j>0; j--){
            if (j>=W[i]) {
                dp[j] = MAX(dp[j-W[i]] + V[i], dp[j]);
            }
            else {
                dp[j] = dp[j];
            }
        }
    }
}

int main(){
    init();
    scanf("%d %d", &T, &M);
    for (int i=1; i<=M; i++){
        scanf("%d %d", &W[i], &V[i]);
    }

    collect();
    printf("%d\n", dp[T]);
    return 0;
}