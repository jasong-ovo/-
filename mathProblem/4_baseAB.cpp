#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;


int convert(char x) {
    if (x>='0' && x<='9') return x - '0';
    switch (x)
    {
    case 'A':
        return 10;
        break;

    case 'B':
        return 11;
        break;

    case 'C':
        return 12;
        break;

    case 'D':
        return 13;
        break;

    case 'E':
        return 14;
        break;

    case 'F':
        return 15;
        break;

    default:
        break;
    }

    return -1;
}

char reconvert(int n){
    if (0<=n && n<=9) return n + '0';
    else return n - 10 + 'A';
}

char capital(char x){
    if (x >= 'a' && x <= 'z') return x + 'A' - 'a';
    else if (x >= 'A' && x <= 'Z') return x;
    else if (x >= '0' && x <= '9') return x;
    return 0;
}

int main(){
    string o_num;
    string m_num;
    int base_o, base_m;
    int num = 0;
    scanf("%d", &base_o);
    cin>>o_num;
    scanf("%d", &base_m);

    // //debug
    // printf("%d %d\n", base_o, base_m);
    // cout<<o_num;

    // to base 10
    int size = o_num.size();
    for (int i=0; i<size; i++){
        num *= base_o;
        num += convert(capital(o_num[i]));
        // printf("num:%d\n", num);
    }
    //to base m
    while (num != 0) {
        m_num.insert(0, 1, reconvert(num%base_m));
        num /= base_m;  
    }

    //print
    size = m_num.size();
    for (int i=0; i<size; i++){
        printf("%c", m_num[i]);
    }
    return 0;
}