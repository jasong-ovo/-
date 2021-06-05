#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 1001
#define MAXC  40
vector<int> primes;
bool isPrimes[MAXN];
int divisors_a[170], divisors_n[170];



void Init(){
    for (int i=0; i<MAXN; i++){
        isPrimes[i] = true; 
    }

    for (int i=2; i<MAXN; i++){
        if (!isPrimes[i]) continue;
        primes.push_back(i);

        for (int j=2*i; j<MAXN; j = j+i){
            isPrimes[j] = false;
        }
    }

    for (int i=0; i<170; i++){
        divisors_a[i] = 0;
        divisors_n[i] = 0;
    }
}

void load_n(int x){
    int i=0;
    int size = primes.size();
    while (primes[i]<x && i<size){
        int count = 0;
        while (x%primes[i] == 0){
            x /= primes[i];
            count ++;
        }
        divisors_n[i] += count;
        i++;

    }

    if (x>1) {
        int i = 0;
        while (x%primes[i] != 0) {
            i++;
        }
        divisors_n[i] += 1;
    }
}

void load_a(int a){
    int i=0;
    int size = primes.size();
    while (primes[i]<a && i<size){
        int count = 0;
        while (a%primes[i] == 0){
            a /= primes[i];
            count ++;
        }
        divisors_a[i] += count;
        i++;

    }

    if (a>1) {
        int i=0;
        while (a%primes[i] != 0)
        {
            i++;
        }
        divisors_a[i] += 1;
    }
}

void dump(int *p) {
    for (int i=0; i<170; i++){
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main(){
    Init();
    int n, a, k;
    k=100000;
    scanf("%d%d", &n, &a);

    //store as simple factors
    load_a(a);
    for (int i=1; i<=n; i++){
        load_n(i);
    }
    
    for (int i=0; i<170; i++){
        if (!divisors_a[i]) continue;
        k = (divisors_n[i]/divisors_a[i]) < k ? (divisors_n[i]/divisors_a[i]) : k;
    }
    printf("%d\n", k);

    //debug
    dump(divisors_a);
    dump(divisors_n);
    return 0;
}