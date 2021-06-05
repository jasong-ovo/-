#include <iostream>
#include <cstdio>

using namespace std;

int reverseNum(int x){
    int rev = 0;
    while (x != 0)
    {
        rev *= 10;
        rev += x % 10;
        x /= 10;
    }
    
    return rev;
}

bool checkSymetric(int x){
    int square = x * x;
    int rev = reverseNum(square);

    if (rev == square) return true;
    else return false;
}

int main(){
    for (int i=0; i<257; i++){
        if (checkSymetric(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}