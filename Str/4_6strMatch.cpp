#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int nextTable[100] = {0};
const char *pattern;
const char *text;


void getNextTable(int m){
    int i=-1;
    int j=0;
    nextTable[j] = i;
    while (j < m)
    {
        if (i == -1 || pattern[i] == pattern[j]){
            i++;
            j++;
            nextTable[j] = i; 
        }
        else {
            i = nextTable[i];
        }
    }
    return;
}

int KMP(int n, int m){
    int num = 0;
    int i = 0;
    int j = 0;
    while(i<n && j<=m){
        if (j==-1 || text[i] == pattern[j]){
            j++;
            i++;
        }
        else {
            j = nextTable[j];
        }
        if (j==m){
            num ++;
            j=nextTable[j];
        }
    }

    return num;
}


int main (){
    string message;
    getline(cin, message);
    text = message.c_str();
    string origin;
    getline(cin, origin);
    int n_start, n_end;
    int N = 1;
    n_start = origin.find('[');
    n_end = origin.find(']');
    N = n_end - n_start - 1;
    string modes[N];
    for (int i=0; i<N; i++){
        modes[i] = origin.substr(0, n_start) + origin.substr(n_start + 1 + i, 1) + origin.substr(n_end+1);
        //string 类型只能用cout输出
        pattern = modes[i].c_str();
        getNextTable(modes[i].size());
        printf("nums:%d\n", KMP(message.size(), modes[i].size()));
    }

    return 0;
}