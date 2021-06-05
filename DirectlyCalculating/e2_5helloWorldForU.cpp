#include <iostream>
#include <cstdio>

using namespace std;

int computeN1(int N){
    int n1=2;
    int n2;
    for (int i=(N+2)/3; i >= 2; i--){
        n2 = N + 2 - 2*i;
        if (n2 >= i) {
            n1 = i;
            break;
        }
    }
    return n1;
}

int main(){
    char strs[80];
    int n1, n2, n3;
    int N;
    scanf("%s", &strs);
    for (int i=0; i<80; i++){
        if (strs[i] == '\0') break;
        N = i + 1;
    }

    //compute n1,n2,n3
    n1 = computeN1(N);
    n2 = n1;
    n3 = N + 2 - n1 - n1;

    // //debug
    // printf("N=%d n1=%d n2=%d n3=%d", N, n1, n2, n3);

    //print
    for (int i=0; i<n1; i++){
        //left side
        printf("%c", strs[i]);


        //middle
        for (int j=1; j<n3-1 ;j++){
            //bottom
            if (i == n1-1)
            printf("%c", strs[i+j]);
            //others
            else printf("%c", ' ');
        }

        //right side
        printf("%c", strs[N-1-i]);
        printf("\n");

    }
    
    return 0;
}