#include <iostream>
#include <cstdio>

using namespace std;

bool checkDivide(int y, int x){
    if (x * (y/x) == y) return true;

    return false;
}

int main(){
    int N;
    int x, y, z;
    int a, b;
    int price = 0;
    int sum;

    scanf("%d\n", &N);
    scanf("%d %d %d", &x, &y, &z);

    for (int i=1; i<=9; i++){
        for (int j=0; j<=9; j++){
            sum = 10000*i + 1000*x + 100*y + 10*z + j; 
            if (checkDivide(sum, N)) {
                price = sum/N;
                a=i, b=j;
                }
        }
    }

    if (price == 0) printf("0");
    else printf("%d %d %d", a, b, price);

    return 0;
}