#include <iostream>
#include <cstdio>
#include <map>
#include <memory.h>

using namespace std;

struct studentBook
{
    int idx;
    int book;
    studentBook(int idx, int book){
        idx = idx;
        book = book;
    }
};

map<int, int> bookNums;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int * studentList;
    studentList = (int *) malloc(N*sizeof(int));
    memset(studentList, 0, N*sizeof(int));
    for (int i=0; i<N; i++){
        int book;
        scanf("%d", &book);
        studentList[i] = book;
        bookNums[book] ++;
    }

    // for (map<int, int>::iterator it=bookNums.begin(); it != bookNums.end(); it++){
    //     printf("%d\n", it->second);
    // }
    for (int i=0; i<N; i++){
        if (bookNums[studentList[i]]-1) {
            printf("%d\n", bookNums[studentList[i]]-1);
        }
        else printf("BeiJu\n");
    }
    
    return 0;
}

