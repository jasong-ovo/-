#include <iostream>
#include <cstdio>

#define MAX(a,b) a>b?a:b
using namespace std;

const int MAXN = 100;
int incrementalDp[MAXN];
int decrementalDp[MAXN];
int students[MAXN];
int inverseStudents[MAXN];


void incrementalSeq(int n) {
    for (int i=0; i<n; i++){
        incrementalDp[i] = 1;
        for (int j=0; j<i; j++){
            if (students[i] > students[j])  incrementalDp[i] = MAX(incrementalDp[i], incrementalDp[j] + 1);
        }
    }
}


void decrementalSeq(int n) {
    for (int i=0; i<n; i++) {
        decrementalDp[i] = 1;
        for (int j=0; j<i; j++){
            if (inverseStudents[i] > inverseStudents[j]) decrementalDp[i] = MAX(decrementalDp[i], decrementalDp[j] + 1);
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &students[i]);
        inverseStudents[n-1-i] = students[i];
    }
    
    incrementalSeq(n);
    decrementalSeq(n);

    int max = 0;
    int max_id;
    for (int i=0; i<n; i++){
        if (incrementalDp[i] + decrementalDp[n-1-i] - 1 > max) {
            max_id = i;
            max = incrementalDp[i] + decrementalDp[n-1-i] - 1 ;
        }
    }

    printf("%d\n", n-max);
}