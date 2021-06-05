#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

// void replace(string& str){
//     int size = (*str).size();
//     if (str[0] < 65 || str[0] > 90) {
//         str[0] += -32;
//         // cout<<str[0]<<endl;
//     }
//     for (int i=0; i<size; i++){
//         if (str[i] == 32) {
//             if (i+1 < size) {
//                     if (str[i+1] < 65 || str[i+1] > 90) {
//                         str[i+1] += -32;
//                         }
//             }
//         }
//     }
// }

int main(){
    string str;
    while (getline(cin, str))
    {
        int size = str.size();
        if (str[0] >= 97 && str[0] <= 122) {
            str[0] += -32;
            // cout<<str[0]<<endl;
        }
        for (int i=0; i<size; i++){
            if (str[i] == ' ' || str[i] == '\r' || str[i] == '\t') {
                if (i+1 < size) {
                        if (str[i+1] >= 97 && str[i+1] <= 122) {
                            str[i+1] += -32;
                            }
                }
            }
        }
        cout<<str<<endl;
    }
    
    return 0;
}