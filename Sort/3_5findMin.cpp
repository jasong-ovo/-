#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //init
    int n;
    scanf("%d", &n);
    int arr[2][n];
    for (int i=0; i<n; i++){
        scanf("%d %d", &arr[0][i], &arr[1][i]);
    }
    // //debug
    // for (int i=0; i<n; i++){
    //     printf("%d %d", arr[0][i], arr[1][i]);
    // }

    //sort x
    int x = arr[0][0], y;
    for (int i=0; i<n; i++){
        if (arr[0][i] < x) 
        {x = arr[0][i];
         y = arr[1][i];
        }
    }
    for (int i=0; i<n; i++){
        if (arr[0][i] == x && arr[1][i] < y) {
            y = arr[1][i];
        }
    }

    //print
    printf("%d %d", x, y);
    return 0;
}