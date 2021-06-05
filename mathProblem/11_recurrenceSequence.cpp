#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
#define N 10000;
int main(){
    int a0, a1, p, q, k;
    scanf("%d%d%d%d%d", &a0, &a1, &p, &q, &k);
    vector<int> a;
    a0 = a0 % N;
    a1 = a1 % N;
    p = p % N;
    q = q % N;
    a.push_back(a0);
    a.push_back(a1);

    int tmp;
    for (int i=2; i<=k; i++){
        tmp = (a[i-1] * p +a[i-2] * q) % N;
        a.push_back(tmp);
    }

    printf("%d", a.back());
}