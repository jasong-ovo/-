#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(){
    string str1;
    string str2;
    // string sum;
    int size1;
    int size2;
    int float_size1, float_size2;

    while(getline(cin, str1)){
        getline(cin, str2);
        char sum[100] = {'\0'};
        int dot1 = 0;
        int dot2 = 0;
        dot1 = str1.find('.');
        dot2 = str2.find('.');
        size1 = str1.size() - 1;
        size2 = str2.size() - 1;
        float_size1 = size1 - dot1;
        float_size2 = size2 - dot2;
        //compute
        int lenth = (float_size1<float_size2) ? float_size1 : float_size2;
        // printf("size1:%d, size2:%d; dot1:%d, dot2:%d\n", size1, size2, dot1, dot2);
        // printf("len:%d\n", lenth);
        int cout = 0;
        int sum_len = 0;
        //float part
        for (int i=0; i<lenth; i++){
            sum[i] = str1[dot1+lenth-i] - '0' + str2[dot2+lenth-i] - '0' + cout;
            // printf("%c\n", str1[dot1+lenth-i]);
            cout = sum[i]/10;
            sum[i] = sum[i]%10;
            // printf("sum[%d]:%d", i, sum[i]);
        }
        // printf("\n");
        //integer part sum[i+lenth]
        int lenth_int = (dot1<dot2)?dot1:dot2;
        for (int i=0; i<lenth_int; i++) {
            sum[i+lenth] = cout + str1[dot1-1-i] - '0' + str2[dot2-1-i] - '0';
            cout = sum[i+lenth]/10;
            sum[i+lenth] = sum[i+lenth]%10;
            // printf("sum[%d]:%d", i+lenth, sum[i+lenth]);
            sum_len = i + lenth;
        }
        // printf("\n");
        //remain part sum[i+lenth+lenth_int]
        if (dot1 > lenth_int) {
            for (int i=0; i<(dot1-lenth_int); i++){
                sum[i+lenth+lenth_int] = cout + str1[dot1 - lenth_int - 1 - i] - '0';
                cout = sum[i+lenth+lenth_int]/10;
                sum[i+lenth+lenth_int] = sum[i+lenth+lenth_int]%10;
                // printf("sum[%d]:%d", i+lenth+lenth_int, sum[i+lenth+lenth_int]);
                sum_len = i+lenth+lenth_int;
            }
        }
        if (dot2 > lenth_int){
            for (int i=0; i<(dot2-lenth_int); i++){
                sum[i+lenth+lenth_int] = cout + str2[dot2 - lenth_int - 1 - i] - '0';
                cout = sum[i+lenth+lenth_int]/10;
                sum[i+lenth+lenth_int] = sum[i+lenth+lenth_int]%10;
                sum_len = i+lenth+lenth_int;
            }
        }

        // printf("\n");

        //print cout at first
        if (cout) printf("1");

        for (int i=sum_len; i >= 0; i--){
            // printf("sum[%d]:%d\t", i, sum[i]);
            printf("%d", sum[i]);
            if (i == lenth) printf(".");
        }

        //print tail nums
        if (float_size1 > float_size2) {
            for (int i=1; i<=float_size1 - lenth; i++){
                printf("%c", str1[i + dot1 + lenth ]);
            }
        }
        else if(float_size2 > float_size1){
            for (int i=1; i<=float_size2 - lenth; i++){
                printf("%c", str2[i + dot2 + lenth ]);
            }
        }
        printf("\n");
        
    }
}