#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;

    if (n >= 500) n = 500;
    if (n <= 33 ) return 0;

    for (int x=0;  x <= 100; x++){
        for (int y=0; y <= 100; y++){
            for(int z=0; z <= 100; z++){
                if (x+y+z > 100) break;
                if (x+y+z == 100 && ((5*x + 3*y + z/3 < n) || (5*x + 3*y + z/3 == n && z%3 ==0)))
                    printf("x=%d,y=%d,z=%d\n", x, y, z); 
            }
        }
    }

    return 0;
}