#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    int size;
    size = str.size();
    char strs[size][size] = {{'\0'}};
    memset(strs, '\0', size*(size));
    for (int i=0; i<size; i++){
        str.copy(strs[i], size, 0);
    }

    for (int i=0; i<size; i++){
        // for(int j=0; j<size; j++){
        //     printf("%c", strs[i][j]);
        // }
        // printf("\n");
        printf("%s\n", strs[i]);
    }
    return 0;
}