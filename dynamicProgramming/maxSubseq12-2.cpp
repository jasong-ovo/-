#include <iostream>
#include <cstdio>
#include <memory.h>


using namespace std;

int ht[2] = {0, 0};

int maxSubSequence(int *nums, int N) {
    int sub_max;
    int dp[N];
    bool is_only_n = true;
    int head;

    for (int i=0; i<N; i++){

        //compute max sub end with nums[i]
        is_only_n = true;
        if (i == 0) {
            dp[i] = nums[i];
            sub_max = dp[i];
            ht[0] = nums[i];
            ht[1] = nums[i];
            head = nums[i];
            continue;
        }
        else {
            if (dp[i-1] >= 0) {
                is_only_n = false;
                dp[i] = dp[i-1] + nums[i];
            }
            else {
                dp[i] = nums[i];
            }
        }

        // record current head loc
        if (is_only_n) {
            head = nums[i];
        }

        // compare with sub_max
        if (dp[i] > sub_max) {
            sub_max = dp[i];
            if (is_only_n) {
                ht[0] = nums[i];
                ht[1] = nums[i];
            }
            else {
                ht[1] = nums[i];
                ht[0] = head;
            }
        }
    }

    return sub_max;
}

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        if (N == 0) break;
        int nums[N];
        for (int i=0; i<N; i++){
            scanf("%d", &nums[i]);
        }

        int max = maxSubSequence(nums, N);
        if (max >= 0){
            printf("%d %d %d\n", max, ht[0], ht[1]);
        }
        else {
            printf("%d %d %d\n", 0, nums[0], nums[N-1]);
        }

    }
    return 0;
}