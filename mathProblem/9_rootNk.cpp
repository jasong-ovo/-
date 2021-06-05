#include <cstdio>
#include <iostream>

using namespace std;
int k;
unsigned long long fastExponential(unsigned long long x, unsigned long long y){
    unsigned long long N;
    N = 1;
    int i;
    while (y != 0){
        i = y%2;
        y /= 2;
        if (i == 1) N = (N*i*x) % (k-1);
        x = (x*x) % (k-1);
        // printf("N:%I64u  ", N);
    }
    if (N == 0) N = k-1; 
    return N;
}

// int root(unsigned long long N, int k){
//     unsigned long long n = N;
//     int n1 = 0;
//     while (n >= k) {
//         n1 += N%k;
//         N /= k;
//         if (N == 0) {
//             n = n1;
//             N = n1;
//             n1 = 0;
//         }
//     }

//     return n;
// }

int main(){
    unsigned long long x, y, N; 
    scanf("%I64u%I64u%d", &x, &y, &k);
    N = fastExponential(x, y);
    printf("%I64u", N);

    return 0;
}