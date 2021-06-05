#include <iostream>
#include <cstdio>

using namespace std;

void index(int n){
    if (n<2) {
        if (n == 0) printf("(0)");
        return;
    } 

    int loc = 0; 
    printf("(");
    while (n!=0) {
        int flag = 0;
        flag = n%2;
        n /= 2;
        if (flag){
            printf("2");
            index(loc);
            if (n/2 != 0  || n%2 != 0)
            {printf("+");}
        }
        loc ++;
    }
    printf(")");
}

int main(){
    int n;
    scanf ("%d", &n);
    index(n);
    return 0;
}