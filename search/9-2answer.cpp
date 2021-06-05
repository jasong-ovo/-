#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
/*
    深度搜索，我们如果找到一个解，那么直接种类加一，返回
*/
using namespace std;
const int MAXN = 25;
const int total = 40; // 总重量
bool visit[MAXN]; // 标记数组
int matter[MAXN]; // 存放物品
int kind = 0; // 记录一共有多少种
int n; // 物品的数量
int cnt =0;
 
void DFS(int sum,int position) { // sum为当前已经凑的质量
    cnt ++;
    if(sum==total) {
        kind++; // 种数增加
        return;
    }
    // 从第一件开始凑数
    // 这里是消除阶乘的关键
    for(int i=position; i<n; i++) {
        if(visit[i] || sum+matter[i]>total) {
            continue;
        }
        visit[i] = true;
        DFS(sum+matter[i],i);
        visit[i] = false; // 回溯
    }
}
 
int main() {
    cin>>n;
    int sum = 0; // 记录所有物品的质量总和
    for(int i=0; i<n; i++) {
        cin>>matter[i];
        sum+=matter[i];
    }
    sort(matter,matter+n);
    // 总和小于40或者最大的已经大于40了
    if(sum<40 || matter[0]>40) {
        cout<<kind<<endl;
        return 0;
    } else {
        memset(visit,false,sizeof(visit));
        DFS(0,0);
        cout<<kind<<endl;
    }
    printf("\ncnt:%d\n", cnt);
    return 0;
}
