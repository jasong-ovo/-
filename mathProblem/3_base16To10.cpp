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

int main(){
    string base8_num;
    while(getline(cin, base8_num)){

        int start = base8_num.find('x') + 1;
        string num = base8_num.substr(start);
        unsigned  int decimal = 0;
        int size = num.size();

        for (int i = 0; i < size; i++){
            decimal = decimal * 16;
            decimal += convert(num[i]);
            // printf("i:%d, decimal:%d", i, decimal);
        }

        printf("%d\n", decimal);
    }
}