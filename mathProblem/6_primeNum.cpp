//200000size的筛子

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN  1000000
vector<int> primes;
bool isPrimes[MAXN] = {true};

void Initial(){
    for (int i=0; i<MAXN; i++){
        isPrimes[i] = true;
    }

    for (int i=2; i<100000; i++){
        // printf("%d\n", i);
        if (!isPrimes[i]) continue;
        for (int j = i * 2; j<MAXN; j = j+i){
            isPrimes[j] = false;
            // printf("%d\n", j);
        }
        // printf("%d\n", i);
        primes.push_back(i);
    }
    // printf("end\n");
}

int main(){
    int k;
    Initial();
    printf("%d\n", primes.size());
    while(scanf("%d", &k)!=EOF){
        printf("%d\n", primes[k-1]);
    }
    return 0;
}
