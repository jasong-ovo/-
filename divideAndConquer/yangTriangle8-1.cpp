#include <cstdio>
#include <iostream>


using namespace std;


int factorial(int n){
    int out = 1;
    for (int i=0; i<n; i++){
        out *= (i+1);
    }
    return out;
}


void yangTriangle(int N){
    if (N == 1) return;
    else {
        yangTriangle(N-1);
        for (int i=0; i<N; i++){
            printf("%d ", factorial(N-1)/(factorial(N-1-i)*factorial(i)));
        }
        printf("\n");
    }
}


int main(){
    int N;
    scanf("%d", &N);
    yangTriangle(N);
    return 0;
}