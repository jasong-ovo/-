#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN  34000
vector<int> primes;
bool isPrimes[MAXN];

void Initial(){
    for (int i=0; i<MAXN; i++){
        isPrimes[i] = true;
    }

    for (int i=2; i<MAXN; i++){
        if (!isPrimes[i]) continue;
        primes.push_back(i);

        for (int j=i*2; j<MAXN; j=j+i){
            isPrimes[j] = false;
        }
    }
}

int divisors(int x){
    int i = 0;
    int size = primes.size();
    int answer = 1;
    while (x>primes[i] && i<size) {
        int kind = 0;
        while (x%primes[i] == 0) {
            x /= primes[i];
            kind ++;
        }
        answer += answer * kind;

        i++;
    }
    // printf("X:%d\n", x);
    // printf("primes:%d\n", primes[0]);

    if (x > 1) answer *= 2;
    return answer;
}

int main(){
    Initial();
    int N;
    scanf("%d", &N);
    int nums[N];
    
    for (int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    for (int i=0; i<N; i++){
        printf("%d\n", divisors(nums[i]));
    }
}