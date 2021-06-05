#include <cstdio>
#include <iostream>
#include <memory.h>
//错误，对所有根1根2的所有节点更新距离

#define MAXN 100
#define MOD 100000

using namespace std;

int N;
int M;
int sPath[MAXN];
int dis[MAXN][MAXN];
int father[MAXN];
int height[MAXN];

int findRoot(int x) {
    if (x != father[x]) {
        father[x] = findRoot(father[x]);
    }
    return father[x];
}

int get2MOD(int x) {
    int out = 1;
    for (int i=0; i<x; i++) {
        out *= 2;
        out %= MOD;
    }
    return out;
}

void init(){
    memset(sPath, 0, sizeof(sPath));
    memset(dis, 0, sizeof(dis));
    memset(father, 0, sizeof(father));
    memset(height, 0, sizeof(height));
    for (int i=0; i<MAXN; i++){
        father[i] = i;
        for (int j=0; j<MAXN; j++){
            dis[i][j] = -1;
            if (i == j) dis[i][j] = 0;
        }
    }
}

void dump() {
    for (int i=1; i<M; i++) printf("%d\n", dis[0][i]);
    printf("\n");
}

int main(){
    init();
    scanf("%d%d", &N, &M);
    int s = 0;

    //read data and update
    for (int i=0; i<M; i++){
        int city1, city2;
        scanf("%d%d", &city1, &city2);

        // if they belong to different sets
        int root1, root2;
        root1 = findRoot(city1);
        root2 = findRoot(city2);
        // printf("city1:%d,city2:%d\n", city1, city2);

        if (root1 != root2) {
            for (int j=0; j<N; j++){
                // printf("root1:%d,root2:%d\n", findRoot(city1), findRoot(city2));
                if (findRoot(j) == root1) {
                    for (int k=0; k<N; k++) {
                        // printf("j:%d k:%d root:%d %d\n", j, k, root1, findRoot(k));
                        if (findRoot(k) == root2) {
                            int tmp;
                            tmp = (get2MOD(i) + dis[j][city1] + dis[city2][k]) % MOD;
                            dis[j][k] = tmp;
                            dis[k][j] = tmp;
                            // printf("j:%d k:%d tmp:%d\n", j, k, tmp);
                        }
                    }
                }
            }
            father[root2] = root1;
        }
    }
        
        // //debug:是city1,2连接不是root1,2连接
        // if (root1 != root2) {

        //     if (root1 == s) {
        //         father[root2] = s;
        //         for (int j=0; j<N; j++) {
        //             if (dis[city2][j] != -1) {
        //                     sPath[j] = (sPath[city1] + get2MOD(i) + dis[city2][j]) % MOD;
        //                 }
        //         }
        //     }

        //     else if (root2 == s) {
        //         father[root1] = s;
        //         for (int j=0; j<N; j++){
        //             if (dis[city1][j] != -1) {
        //                 sPath[j] = (sPath[city2] + get2MOD(i) + dis[city1][j]) % MOD;
        //             }
        //         }
        //     }

        //     else {
        //         father[root2] = root1;
        //         // printf("city1:%d,city2:%d\n", city1, city2);
        //         for (int j=0; j<N; j++) {
        //             if (dis[city2][j] != -1) {
        //                 //root1 到 city1 到新增边 到 city2 到 root2 （因为只有root2记录了所有边）不合理路径 
        //                 dis[root1][j] = (dis[city2][j] + get2MOD(i) + dis[root1][city1]) % MOD;
        //                 // printf("city[j]:%d[%d], dis:%d\n", city1, j, dis[city1][j]);
        //             }
        //         }
        //     }
        // }

    dump();
    return 0;
}