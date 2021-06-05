#include <cstdio>
#include <iostream>
#include <memory.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define MAXN 100
using namespace std;

struct edge{
    int node1Id;
    int node2Id;
    float lenth;
    edge(int a, int b, float c) {
        node1Id = a;
        node2Id = b;
        lenth = c;
    }
};

float freckles[MAXN][2];
float dis[MAXN][MAXN];
int father[MAXN];
int height[MAXN];
int N;
float sum = 0;
vector<edge> edges;

int find(int x){
    if (father[x] != x) {
        father[x] = find(father[x]);
    }
    return father[x];
}

void cUnion(int a, int b){
    int rootA, rootB;
    rootA = find(a);
    rootB = find(b);

    if (height[rootA] > height[rootB]) {
        father[rootB] = rootA;
    }
    else if (height[rootA] < height[rootB]){
        father[rootA] = rootB;
    }
    else {
        father[rootB] = rootA;
        height[rootA] ++;
    }
    return;
}

bool compare(edge a, edge b) {
    return a.lenth > b.lenth;
}

void dump(int *arr){
    for (int i=0; i<MAXN; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main(){
    for (int i=0; i<MAXN; i++) {
        height[i] = 0;
        father[i] = i;
    }
    memset(freckles, 0, sizeof(freckles));
    scanf ("%d", &N);

    for (int i=0; i<N; i++){
        scanf("%f %f", &freckles[i][0], &freckles[i][1]);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            dis[i][j] = sqrt(
            (freckles[i][0] - freckles[j][0])*(freckles[i][0] - freckles[j][0]) + (freckles[i][1] - freckles[j][1])*(freckles[i][1] - freckles[j][1])
            );
            edges.push_back(edge(i, j, dis[i][j]));
        }
    }

    sort(edges.begin(), edges.end(), compare);

    while (!edges.empty())
    {   
        // printf("len:%d\n", edges.size());
        edge curEdge = edges[edges.size() - 1];
        edges.pop_back();

        int v1, v2; 
        float curLen;
        v1 = curEdge.node1Id;
        v2 = curEdge.node2Id;
        curLen = curEdge.lenth;
        // printf("v1:%d v2:%d\n", v1, v2);
        // dump(father);
        if (find(v1) != find(v2)) {
            sum += curLen;
            cUnion(v1, v2);
        }
    }
    
    printf("%.2f\n", sum);
    return 1;
}
