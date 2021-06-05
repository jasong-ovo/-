# include<iostream>
# include<cstdio>
# include<algorithm>
# include<string.h>

using namespace std;

struct rat
{   int w;
    char c[10] = {'\0'};
    rat (int weight=0){
        w = weight;
    }
};


bool compare(rat a, rat b){
    if (a.w > b.w) return true;
    return false;
}


int main(){
    //init
    int N;
    scanf("%d", &N);
    rat rats[N];
    for (int i=0; i<N; i++){
        scanf("%d", &rats[i].w);
        // getchar();
        scanf("%s", rats[i].c);
    }

    //sort
    sort(rats, rats+N, compare);

    //printf
    for (int i=0; i<N; i++){
        printf("%s\n", rats[i].c);
    }
    
    // //debug
    // for (int i=0; i<N; i++){
    //     printf("%s\n", rats[i].c);
    // }
    return 0;
}