#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
//数组越界

#define MAXN 27

using namespace std;

struct edge{
    int villageA;
    int villageB;
    int cost;
    edge(int a, int b, int c) {
        villageA = a;
        villageB = b;
        cost = c;
    }
};

int N;
int villages[MAXN];  //store numbers of connected villages
int father[MAXN];
int height[MAXN];
bool visit[MAXN]; // store if the villlage is declared
int sumNumberOfRoads;
int sumCost;
vector<edge> edges;

void init(){
    sumCost = 0;
    sumNumberOfRoads = 0;
    for (int i=0; i<MAXN; i++) {
        villages[i] = 0;
        father[i] = i;
        height[i] = 0;
        visit[i] = false;
    }
}

int find(int x) {
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
    else if (height[rootB] > height[rootA]){
        father[rootA] = rootB;
    }
    else {
        father[rootB] = rootA;
        height[rootA] ++;
    }
}

bool compare(edge a, edge b) {
    return a.cost < b.cost;
}

bool check_connected(){
    int cnt = 0;
    for (int i=0; i<MAXN; i++){
        if (visit[i] && father[i]==i) cnt++;
    }

    return cnt == 1;
}

int main(){
    while(scanf("%d", &N) != EOF) {
        if (N == 0) break;

        //init
        init();
        getchar(); //clear \n

        //read N-1 lines
        for (int i=0; i<N-1; i++) {
            printf("i:%d\n", i);
            int startVillage, connectedNum;
            scanf("%c %d", &startVillage, &connectedNum);
            getchar();
            startVillage -= 'A'; 
            printf("startV:%c, connectedNum:%d\n", startVillage+'A', connectedNum);

            //record connectedNum roads
            for (int j=0; j<connectedNum; j++) {
                printf("j:%d\n", j);
                int endVillage, cost;
                scanf("%c %d", &endVillage, &cost);
                getchar();
                endVillage -= 'A';
                edges.push_back(edge(startVillage, endVillage, cost));
            }
        }

        //kruskal computes the minimal tree
        // 1. sort
        sort(edges.begin(), edges.end(), compare);
        // 2. union and find
        int lOfEdges = edges.size(); 

        //loop the shortest edge in the set
        for (int k=0; k<lOfEdges; k++) {

            int v1, v2, cost;
            v1 = edges[k].villageA;
            v2 = edges[k].villageB;
            cost = edges[k].cost;

            //determine if they are in the same set
            if (find(v1) != find(v2) && villages[v1]<15 && villages[v2]<15) {
                cUnion(v1, v2);
                villages[v1] ++;
                villages[v2] ++;
                sumNumberOfRoads ++;
                sumCost += cost;
                visit[v1] = true;
                visit[v2] = true;
            }
        }

        if (check_connected()){
            // int root;
            // for (int i=0; i<MAXN; i++) {
            //     if (i == father[i] && visit[i]) {
            //         root = i;
            //         break;
            //     }
            // }
            printf("%d\n", sumCost);
        }
    }

    ////debug
    // int a ,b;
    // scanf("%c %d", &a, &b);
    // printf("%d %d\n", a, b);

    return 0;
}


// #include <iostream>
// #include <algorithm>
// #define N 27
// using namespace std;
// int Tree[N];
// int findRoot(int x){
//     if(Tree[x]==-1) return x;
//     int temp=findRoot(Tree[x]);
//     Tree[x]=temp;
//     return temp;
// }
// struct Edge{
//     int x,y;
//     int cost;
// };
// int cmp(Edge a,Edge b){
//     return a.cost<b.cost;
// }
// int main(){
//     int n;
//     while(cin>>n){
//         if(n==0) break;
//         Edge e[300];
//         int cnt,len=0;
//         char x;
//         int cc;char xb;
//         for(int i=0;i<n;i++) Tree[i]=-1;
//         for(int i=0;i<n-1;i++){
//             cin>>x>>cnt;
//             int aa=x-'A';
//             for(int j=0;j<cnt;j++){
//                 cin>>xb>>cc;
//                 int bb=xb-'A';
//                 e[len].x=aa;e[len].y=bb;e[len].cost=cc;
//                 len++;
//             }
//         }
//         sort(e,e+len,cmp);
//         int ans=0;
//         for(int i=0;i<len;i++){
//             int a=findRoot(e[i].x);
//             int b=findRoot(e[i].y);
//             if(a!=b){Tree[a]=b;ans+=e[i].cost;}
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }