#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    for (int a=1; a<10; a++){
        for (int b=0; b<10; b++){
            for (int c=0; c<10; c++){
                if(100*a + 110*b + 12*c == 532){
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}

