#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int GCD(int x1, int x2){
    int remainder = 0;
    remainder = x1 % x2;
    // printf("x1:%d, x2:%d\n",x1,x2);
    if (remainder == 0) return x2;
    else remainder = GCD(x2, remainder);

    return remainder;
}


int main(){
    //init
    int N;
    scanf("%d", &N);
    int nums[N] = {0};
    for (int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    sort(nums, nums + N);

    int answer = 0;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++) {
            if (GCD(nums[j], nums[i]) == 1) answer++;
            // printf("%d\n", GCD(nums[j], nums[i]));
        }
    }

    printf("%d", answer);


}