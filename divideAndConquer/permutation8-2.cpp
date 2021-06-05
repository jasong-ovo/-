#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
//八皇后问题深度优先遍历，用树的模型思考。#复习时可以看看
using namespace std;

string printStr;


void permutation(string alphas){
    int len = alphas.length();
    if (len == 1) {
    printStr.push_back(alphas[0]);
    cout<<printStr<<endl;
    printStr.pop_back();
    return ;
    }
    for (int i=0; i<len; i++){
        char tmp = alphas[i];
        printStr.push_back(alphas[i]);
        alphas.erase(i, 1);
        permutation(alphas);
        alphas.insert(i, 1, tmp);
        printStr.pop_back();
    }
}

int main(){
    string in;
    getline(cin, in);
    sort(in.begin(), in.end());
    permutation(in);
    // sort()
    return 0;
}