#include <iostream>
#include <cstdio>
#include <string.h>
// #include <math.h>
using namespace std;

unsigned int pow2(int ind){
    int out = 1;
    while (ind > 0)
    {
        out *= 2;
        ind --;
    }
    return out;
}

unsigned int convent(string skewNum){
    unsigned int out = 0;
    int size = skewNum.size();
    for (int i=0; i<size; i++){
        out += (pow2(size - i) - 1) * (skewNum[i] - '0');
        // printf("out:%d\n", out);
        // printf("ind:%d\n", pow2(size - i) );
    }
    return out;
}

int main(){
    string skewNum;
    unsigned int decimal = 0;
    while (getline(cin, skewNum)){
        decimal = convent(skewNum);
        printf("%u\n", decimal);
    }
    return 0;
}