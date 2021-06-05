#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
//溢出 大于2^63
//解1：大整数
//解2：边长规律，前n-1条边长之和小于第n条边

#define MOD 100000
#define PMAXINT 1000000000
using namespace std;

struct edge{
    long long to;
    long long lenth;
    edge(long long a, long long b){
        to = a;
        lenth = b;
    }
};

struct cityDis
{
    long long city;
    long long dis;
    cityDis(long long a, long long b){
        city = a;
        dis = b;
    }
    //reload < to change the default max top in priority queue
    bool operator< (const cityDis& c) const {
        return dis > c.dis;
    }
};

long long pow2(long long x) {
    long long out = 1;
    while(x--){
        out *= 2;
    }

    return out;
}

long long N, M;

int main(){
    scanf("%d %d", &N, &M);
    long long dis[N];
    vector<edge> graph[N];
    priority_queue<cityDis> myCityPriorityQueue;

    //init
    for (int i=0; i<N; i++){
        dis[i] = PMAXINT;
    }

    //load roads
    for (int i=0; i<M; i++){
        long long city1, city2, lenth;
        scanf("%d %d", &city1, &city2);
        lenth = pow2(i);
        graph[city1].push_back(edge(city2, lenth));
        graph[city2].push_back(edge(city1, lenth));
    }

    //dijkstr
    long long s = 0;
    dis[s] = 0;
    myCityPriorityQueue.push(cityDis(s, dis[s]));
    while (!myCityPriorityQueue.empty())
    {
        long long curCity = myCityPriorityQueue.top().city;
        myCityPriorityQueue.pop();
        
        // loop the neiboure
        for (int i=0; i<graph[curCity].size(); i++) {
            
            long long toCity = graph[curCity][i].to;
            long long curLen = graph[curCity][i].lenth;
            // relaxation
            if (dis[toCity] > dis[curCity] + curLen) {
                dis[toCity] = dis[curCity] + curLen;
                myCityPriorityQueue.push(cityDis(toCity, dis[toCity]));
            }
        }
    }

    ////check whether the graph is connected
    // bool isConnected = true;
    // for (int i=0; i<N; i++) {
    //     if (dis[i] == PMAXINT) {
    //         isConnected = false;
    //         break;
    //     }
    // }


    for (int i=1; i<N; i++){
        if (dis[i] != PMAXINT) printf("%I64d\n", dis[i]%MOD);
        else printf("%d\n", -1);
    }



    return 0;
}