#include <iostream>
#include <cstdio>
#include <memory.h>
#include <string.h>

using namespace std;
int nodes[91];


void cUnion(char kid, char pl, char pr){
    if (pl != '-') nodes[pl] = kid;
    if (pr != '-') nodes[pr] = kid;
    return;
}

bool find(char node_start, char node_end, int *pCount) {
    if (nodes[node_start] == node_start) return false;
    *pCount = *pCount + 1;
    if (nodes[node_start] == node_end) return true;
    else return find(nodes[node_start], node_end, pCount);
}


void dump_OY(int n) {
    string prefix = "great-";
    if (n == 1) {
        printf("parent\n");
        return;
    }
    if (n == 2) {
        printf("grandparent\n");
        return;       
    }
    if (n>2) {
        for (int i=n; i>2; i--){
            cout<<prefix;
        }
        printf("grandparent\n");
    }
}


void dump_YO(int n) {
    string prefix = "great-";
    if (n == 1) {
        printf("child\n");
        return;
    }
    if (n == 2) {
        printf("grandchild\n");
        return;       
    }
    if (n>2) {
        for (int i=n; i>2; i--){
            cout<<prefix;
        }
        printf("grandchild\n");
    }
}


int main(){
    for (int i=0; i<91; i++){
        nodes[i] = i;
    }
    int N, Q;
    scanf("%d %d\n", &N, &Q);
    for (int i=0; i<N; i++){
        char k, pl, pr;
        scanf("%c%c%c\n", &k, &pl, &pr);
        // printf("%c%c%c\n", k, pl, pr);
        cUnion(k, pl, pr);
    }

    for (int i=0; i<Q; i++){
        char node1, node2;
        int count1, count2;
        count1 = 0;
        count2 = 0;
        scanf("%c%c", &node1, &node2);
        getchar();//读取回车
        // printf("%c,%c\n", node1, node2);
        if (find(node1, node2, &count1)){
            dump_OY(count1);
        }
        else if (find(node2, node1, &count2)) {
            dump_YO(count2);
        }
        else printf("-\n");
        
    }
    return 0;
}