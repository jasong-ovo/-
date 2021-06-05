#include <iostream>
#include <cstdio>
#include <map>

using namespace std;


int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        if (N==0) break;
        map<int, int> scores;
        while(N--){
            int tmp;
            scanf("%d", &tmp);
            scores[tmp] ++;
        }
        for (map<int, int>::iterator i = scores.begin(); i != scores.end(); i++){
            printf("%d ", i->first);
        }
        // int query;
        // scanf("%d", &query);
        // printf("%d\n", scores[query]);
    }
    return 0;
}