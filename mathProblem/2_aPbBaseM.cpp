#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    //init
    int m;
    long long A, B;
    while (1){
        scanf("%d", &m);
        if (!m) break;
        scanf("%I64d%I64d", &A, &B);

        A += B;
        vector<int> baseM_nums;
        while (A!=0){
            baseM_nums.push_back(A%m);
            A /= m;
        }
        if (baseM_nums.empty()) {
            printf("0\n");
            continue;
        }
        for (int i=baseM_nums.size(); i>0; i--){
            printf("%d", baseM_nums[i-1]);
        }
        printf("\n");
    }
    return 0;
}