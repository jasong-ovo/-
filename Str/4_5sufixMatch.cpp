#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

bool compare(char *a, char *b){
    if (strcmp(a, b)<=0) return true;
    else return false;
}

int main(){
    string str;
    getline(cin, str);
    int size;
    size = str.size();
    char strs[size][size+1] = {{'\0'}};
    memset(strs, '\0', size*(size+1));
    for (int i=0; i<size; i++){
        str.copy(strs[i], size-i, i);
    }

    //compare
    int idx[size];
    for (int i=0; i<size; i++){
        int loc = size - 1;
        char *tmp = strs[i];
        for (int j = 0; j<size; j++){
            if (j == i) continue;
            if (compare(tmp, strs[j])) loc --;
        }
        idx[loc] = i;
    }

    for (int i=0; i<size; i++) {
        printf("%s\n", strs[idx[i]]);
    }
    // for (int i=0; i<size; i++){
    //     // for(int j=0; j<size; j++){
    //     //     printf("%c", strs[i][j]);
    //     // }
    //     // printf("\n");
    //     printf("%s\n", strs[i]);
    // }
    return 0;
}