#include <iostream>
#include <cstdio>

#define MAXN 1000

using namespace std;

int father[MAXN];
int height[MAXN];


int find(int a) {
    if (father[a] != -1 && father[a] != a) {
        return find(father[a]);
    }
    // printf("fathera:%d\n", father[a]);
    if (father[a] == -1) {
        father[a] = a;
    }
    return father[a];
}


void iUnion(int a, int b){
    int rootA, rootB;
    rootA = find(a);
    rootB = find(b);

    if (rootA == rootB) return;
    if (height[rootA] > height[rootB]){
        father[rootB] = rootA;
    }
    if (height[rootA] < height[rootB]){
        father[rootA] = rootB;
    }
    if (height[rootA] == height[rootB]){
        height[rootA] ++;
        father[rootB] = rootA;
    }
    return;
}


int main(){
    for (int i=0; i<MAXN; i++) {
        father[i] = -1;
        height[i] = 0;
    }
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {   
        iUnion(a, b);
    }
    
    int cnt = 0;
    for (int i=0; i<MAXN; i++){
        if (father[i] == i) cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}