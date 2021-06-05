#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;



int main(){
    //init
    int N;
    scanf("%d", &N);
    int nums[N];
    for (int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }
    
    //sort and subscribe the biggest num
    if (N > 1){
        sort(nums, nums+N);
        printf("%d\n", nums[N-1]);

        for (int i=0; i<N-1; i++){
            printf("%d ", nums[i]);
        }
    }

    else printf("%d\n%d", nums[0], -1);
    // //debug
    // for (int i=0; i<N; i++){
    //     printf("%d ", nums[i]);
    // }
    return 0;
}