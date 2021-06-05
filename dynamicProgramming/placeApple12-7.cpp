#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int dp[11][11];

int main(){
    int C;
    scanf("%d", &C);

    for (int i=0; i<C; i++){
        memset(dp, 0, 11*11*sizeof(int));
        int M, N;
        scanf("%d %d", &M, &N);
        
        for (int i=1; i<M+1; i++){
            for (int j=1; j<N+1; j++){
                if (j==1){
                    dp[i][j] = 1;
                    continue;
                }
                if (i-j >= 0){
                    dp[i][j] = dp[i-j][j] + dp[i][j-1];
                    if (i == j) dp[i][j] ++;
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        printf("%d\n", dp[M][N]);
    }
    return 0;
}