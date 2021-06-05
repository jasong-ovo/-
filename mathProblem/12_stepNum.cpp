//也可以用数学的方法 a*n + 10*a*(n-1) + ....
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
#define MAXN 120

struct BigInteger {
    int digit[MAXN];
    int lenth;
    BigInteger ();
    BigInteger (string str);
    BigInteger operator+(BigInteger b);
    BigInteger operator=(BigInteger b);
    void dump();
};

BigInteger BigInteger::operator+(BigInteger b) {
    BigInteger answer;
    int carry = 0;
    for (int i=0; i<lenth || i<b.lenth; i++){
        int current = carry + b.digit[i] + digit[i];
        carry = current / 10;
        answer.digit[i] = current % 10;
        answer.lenth ++;
    }
    if (carry) {
        answer.digit[answer.lenth] = 1;
        answer.lenth ++;
    }
    return answer;
}

BigInteger BigInteger::operator=(BigInteger b){
    memset(digit, 0, sizeof(digit));
    lenth = b.lenth;
    for (int i=0; i<lenth; i++){
        digit[i] = b.digit[i];
    } 
    return *this;
}

BigInteger::BigInteger() {
    lenth = 0;
    for (int i=0; i<MAXN; i++){
        digit[i] = 0;
    }
}

BigInteger::BigInteger(string str) {
    lenth = str.size();
    for (int i=0; i<MAXN; i++){
        digit[i] = 0;
    }

    //最高位在最后,便于做加法
    for (int i = 0; i<lenth; i++){
        digit[i] = str[lenth - i - 1] - '0';
    }
}

void BigInteger::dump(){
    for (int i = 0; i<lenth; i++){
        printf("%d", digit[lenth - i - 1]);
    }
    printf("\n");
}

int main(){
    // string str;
    // cin>>str;
    // BigInteger bInt(str);
    // BigInteger x;
    // x = bInt;

    //init
    int a, n;
    scanf("%d%d", &a, &n);
    BigInteger sum;
    string num;
    for (int i = 0; i < n; i ++ ){
        num.insert(0, 1, a + '0');
        BigInteger tmp(num);
        sum = sum + tmp;
    }

    sum.dump();

    return 0;
}