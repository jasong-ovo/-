#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    //init
    int N;
    scanf("%d", &N);
    vector<int> base8_nums;
    while (N>0){
        // printf("N:%d\n", N);
        base8_nums.push_back(N%8);
        N /= 8;
    }
    for (int i=base8_nums.size()-1; i >= 0; i--){

        printf("%d", base8_nums[i]);
    }
    return 0;
}