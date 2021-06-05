#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //init 
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    //find&print
    if (arr[0] != arr[1]) printf("%d ", 0);
    for (int i=1; i<N-1; i++){
        if ((arr[i]-arr[i-1]) * (arr[i]-arr[i+1]) > 0) printf("%d ", i);
    }
    if (arr[N-1] != arr[N-2]) printf("%d", N-1);
    return 0;
}