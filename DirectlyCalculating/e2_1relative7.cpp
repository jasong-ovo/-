#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;

    for (int i=1; i<=n; i++){
        if ((i%7) != 0 && (i/10 != 7) && (i%10 != 7)) sum += i*i;
    }

    printf("%d\n", sum);
    
    return 0;
}