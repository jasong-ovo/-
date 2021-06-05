#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
#define MAXN 31

struct BigInt{
    int lenth;
    int digit[MAXN];

    BigInt(string str);
    int operator%(int k);
    void dump();
};

BigInt::BigInt(string str){
    memset(digit, 0, sizeof(digit));
    int size = str.size();
    lenth = size;
    
    //最高位在最后面
    for (int i = 0; i < size; i++){
        digit[i] = str[size - 1 - i] - '0';
    }
}

int BigInt::operator%(int k) {
    int remainder = 0;
    for (int i=0; i<lenth; i++){
        int current = remainder * 10 + digit[lenth - 1 - i];
        remainder = current % k; 
    }
    return remainder;
}

void BigInt::dump(){
    for (int i=0; i<lenth; i++){
        printf("%d", digit[lenth - 1 -i]);
    }  
    printf("\n");
}


int main(){
    //init
    string str;
    cin>>str;
    if (str[0] == '-') return 0;
    BigInt num(str);
    bool flag = false;
    for (int i=2; i<10; i++){
        if (!(num%i)) {
            flag = true;
            printf("%d ", i);
        }
    }
    if (!flag) printf("none");

    return 0;
}