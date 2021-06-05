#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void dump(float*p, int N);
struct  country
{
    int goldenMedal, medal, rank, way, idx;
    float population;
    country(){
        idx = 0;
        goldenMedal = 0;
        medal = 0;
        population = 0;
        rank = 100;
        way = 0;
    }
};


void gatherRanks(int N, int way, country *players, int* pi = NULL, float* pf = NULL){
    //1,2
    if(pi != NULL) {
        int idx = 1;
        int last = -1;
        int counter = 0;

        //1
        if (way == 1){
            for (int i=0; i<N; i++){
                // printf("i:%d\t%d\t%d\n", i, pi[i], last);
                //skip same nums
                if (last == pi[i]) continue;
                //refresh
                for (int j=0; j<N; j++){
                    // printf("j:%d\trank:%d\n", j, players[j].rank);
                    if (players[j].goldenMedal == pi[i]) {
                        // printf("%d",idx);
                        counter ++;
                        if(players[j].rank > idx ){
                        players[j].rank = idx;
                        players[j].way = way;
                        }
                    }
                }
                idx += counter;
                counter = 0;
                last = pi[i];
            }
        }

        //2
        if (way == 2){
            for (int i=0; i<N; i++){
                //skip same nums
                if (last == pi[i]) continue;
                //refresh
                for (int j=0; j<N; j++){
                    if ( players[j].medal == pi[i]) {
                        counter ++;
                        if(players[j].rank > idx ){
                        players[j].rank = idx;
                        players[j].way = way;
                        }
                    }
                }
                idx += counter;
                counter = 0;
                last = pi[i];
            }
        }

    }
    //3,4
    else {
        // printf("mark0\n");
        int idx = 1;
        int last = -1;
        int counter = 0;

        //3
        if (way == 3){
            for (int i=0; i<N; i++){
                //skip same nums
                // printf("i:%d\n", i);
                if (last == pf[i]) continue;
                
                //refresh
                for (int j=0; j<N; j++){
                    // printf("j:%d\n", j);
                    if ( (players[j].goldenMedal / players[j].population) == pf[i]) {
                        counter ++;
                        if(players[j].rank > idx ){
                        players[j].rank = idx;
                        players[j].way = way;
                        }
                    }
                }
                idx += counter;
                counter = 0;
                last = pf[i];
            }
        }

        //4
        if (way == 4){
            // dump(pf, N);
            for (int i=0; i<N; i++){
                //skip same nums
                if (last == pf[i]) continue;
                //refresh
                for (int j=0; j<N; j++){
                    if ((players[j].medal / players[j].population) == pf[i]) {
                        // printf("j:%d\tpf[i]:%f\n", j, pf[i]);
                        counter ++;
                        if(players[j].rank > idx ){
                        players[j].rank = idx;
                        players[j].way = way;
                        }
                    }
                }
                idx += counter;
                counter = 0;
                last = pf[i];
            }
        }
    }
    // printf("ranking:%d\n", way);
}


bool compare1(int a, int b){
    if (a>b) return true;
    return false;
}

bool compare2(float a, float b){
    if (a>b) return true;
    return false;
}

void dump(float *p, int N){
    for (int i=0; i < N; i++){
        printf("%f\t", p[i]);
    }
    printf("\n");
}


int main(){
    //init
    int N, M;
    scanf("%d %d", &N, &M);
    country players[N];
    for (int i=0; i<N; i++){
        players[i].idx = i;
        scanf("%d", &players[i].goldenMedal);
        scanf("%d", &players[i].medal);
        scanf("%f", &players[i].population);
    }
    int prints[M];
    for (int i=0; i<M; i++){
        scanf("%d", &prints[i]);
    }

    //sort
    int gMedals[N];
    int medals[N];
    float gMedalsPropertion[N];
    float medalsPropertion[N];
    for (int i=0; i<N; i++){
        gMedals[i] = players[i].goldenMedal;
        medals[i] = players[i].medal;
        gMedalsPropertion[i] = float(players[i].goldenMedal) / players[i].population;
        medalsPropertion[i] = float(players[i].medal) / players[i].population;
    }
    // dump(gMedalsPropertion, N);
    sort(gMedals, gMedals+N, compare1);
    gatherRanks(N, 1, players, gMedals);
    sort(medals, medals+N, compare1);
    gatherRanks(N, 2, players, medals);
    sort(gMedalsPropertion, gMedalsPropertion+N, compare2);
    gatherRanks(N, 3, players, NULL, gMedalsPropertion);
    sort(medalsPropertion, medalsPropertion+N, compare2);
    gatherRanks(N, 4, players, NULL, medalsPropertion);

    //print
    for (int i=0; i<M; i++){
        printf("%d:%d\n", players[prints[i]].rank, players[prints[i]].way);
    }

    return 0;
}