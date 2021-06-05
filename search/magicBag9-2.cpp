#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

int content = 40;
int ans = 0;
vector<int> things; 
map<vector<char>, bool> legalCom;
vector<char> record; //record 中储存的是'0','1'....
int depth = 0;
int cnt = 0;
void dump();

void putInBag(int inBag ,int weigts, int position){
    cnt ++;
    // dump();
    //inBag + weights == 40
    if (inBag + weigts == 40) {
        if (legalCom.find(record) != legalCom.end()) return;
        ans ++;
        legalCom.insert(pair <vector<char>, bool> (record, true));
        return;
    }

    int curInBag = inBag + weigts;
    //cut2 
    if (curInBag > 40) return;

    //DFS
    //这个地方从0开始计数是阶乘出现的原因，但是不用从0开始，因为前面的在前面以经包括了
    for (int i=position; i<record.size(); i++){
        if (record[i] == '1') continue;

        record[i] = '1';
        putInBag(curInBag, things[i], i);
        record[i] = '0'; 
    }
    return ;

}


//debug
void dump(){
    for (int i=0; i<record.size(); i++){
        printf("%c ", record[i]);
    }

    printf("\n");
    return;
}


int main(){
    //init
    int N;
    int sum = 0;
    scanf("%d", &N);
    int n = N;
    while (n >0){
        n --;
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
        things.push_back(tmp);
    }

    //cut branch 1
    if (sum < content) {
        printf("0");
        return 0;
    }
    //choose
    for (int i=0; i<N; i++){
        record.push_back('0');
    }
    for (int i=0; i<N; i++){
        // printf("i:%d\n", i);
        // printf("%d\n", cnt);
        record[i] = '1';
        putInBag(0, things[i], i);
        record[i] = '0';
    }

    //print
    printf("%d", ans);
    return 0;
}