#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAXN 28

using namespace std;

struct Gang {
    int head;
    int members;
    Gang (int a, int b) {
        head = a;
        members = b;
    }
};

int father[MAXN];
int height[MAXN];
int phoneTimeGang[MAXN];
int phoneTimePer[MAXN];

int CASE, K, I;

vector<Gang> GANGS;


int intName(string nameStr) {
    char nameInt = nameStr[0];
    return nameInt - 'A';
}


int find(int x) {
    if (father[x] != -1 && father[x] != x) {
        father[x] = find(father[x]);
    }
    if (father[x] == -1) {
        father[x] = x;
    }
    return father[x];
}


void cUnion(int a, int b, int time){
    int rootA, rootB;
    rootA = find(a);
    rootB = find(b);

    if (height[rootA] > height[rootB]) {
        father[rootB] = rootA;
        // printf("rootA:%d\n", phoneTimeGang[rootA]);
        phoneTimeGang[rootA] += (time + phoneTimeGang[rootB]);
        //printf("phoneTimeGang[rootA] += (time + phoneTimeGang[rootB]):%d %d %d\n", phoneTimeGang[rootA], time, phoneTimeGang[rootB]);
    }
    if (height[rootA] < height[rootB]) {
        father[rootA] = rootB;
        phoneTimeGang[rootB] += (time + phoneTimeGang[rootA]);
        //printf("phoneTimeGang[rootB] += (time + phoneTimeGang[rootA]):%d %d", time, phoneTimeGang[rootA]);
    }
    if (height[rootA] == height[rootB]) {
        father[rootB] = rootA;
        phoneTimeGang[rootA] = (time + phoneTimeGang[rootB]);
        height[rootA] ++;
        //printf("phoneTimeGang[rootA] += (time + phoneTimeGang[rootB]):%d %d\n", time, phoneTimeGang[rootB]);
    }
}


bool isGang(int id, int *pHead, int *pMembers){
    if (phoneTimeGang[id] <= K) return false;
    int member = 0;
    int maxPhoneTime = 0;

    for (int i=0; i<MAXN; i++){
        //loop all the name, find who's root is id
        if (find(i) == id) 
        {
            member ++;
            if (phoneTimePer[i] > maxPhoneTime) {
                maxPhoneTime = phoneTimePer[i];
                *pHead = i;
            }
        }
    }

    *pMembers = member;
    return member>2 ;
}


void check_gang(){
    for (int i=0; i<MAXN; i++){
        if (father[i] == i) {
            int head, members;
            if (isGang(i, &head, &members)) {
                Gang gangNow = Gang(head, members);
                GANGS.push_back(gangNow);
            }

        }
    }
    return;
}


void dump(int * arr) {
    for (int i=0; i<MAXN; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


bool compare(Gang a, Gang b) {
    if (a.head <= b.head) return true;
    return false;
}

int main(){
    for (int i=0; i<MAXN; i++){
        father[i] = -1;
        phoneTimeGang[i] = 0;
        phoneTimePer[i] = 0;
    }

    scanf("%d %d", &CASE, &K);
    getchar();

    for (int i=0; i<CASE; i++) {
        string name1, name2;
        int time, intName1, intName2;
        cin>>name1;
        cin>>name2;
        cin>>time;
        // cout<<name1<<' '<<name2<<" "<<time<<endl;
        intName1 = intName(name1);
        intName2 = intName(name2);
        // cout<<intName1<<' '<<intName2<<" "<<time<<endl;
        phoneTimePer[intName1] += time;
        phoneTimePer[intName2] += time;

        I = name1.size();

        cUnion(intName1, intName2, time);
    }
    // dump(phoneTimePer);
    // dump(father);
    // dump(phoneTimeGang);
    check_gang();
    // printf("%d", GANGS.size());

    sort(GANGS.begin(), GANGS.end(), compare);
    printf("%d\n", GANGS.size());
    for (int i=0; i<GANGS.size(); i++){
        char nameH = GANGS[i].head + 'A';
        for (int j=0; j<I; j++){
            printf("%c", nameH);
        }
        printf(" %d\n", GANGS[i].members);
    }
    return 0;
}