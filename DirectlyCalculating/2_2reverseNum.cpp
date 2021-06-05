#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    for (int a=1; a<10; a++){
        for (int b=0; b<10; b++){
            for(int c=0; c<10; c++){
                for (int d=1; d<10; d++){
                    if (8999*a + 890*b - 10*c -991*d == 0){
                        printf("%d\n", 1000*a + 100*b + 10*c + d);
                    }
                }
            }
        }
    }
    return 0;
}