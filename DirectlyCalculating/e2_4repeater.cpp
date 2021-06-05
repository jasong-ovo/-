#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

char **scalePattern(int size, char **p, int N){
    if (size == 1) return p;

    char ** o_p;
    char ** p_p;
    o_p = scalePattern(size-1, p, N);

    //create a dynamic array
    int _N = N;
    for (int i=1; i<size; i++){
        _N *= N;
    }

    p_p = (char**)malloc(_N*sizeof(char *));
    for (int i=0; i<_N ;i++){
        *(p_p+i) = (char *)malloc(_N*sizeof(char));
        memset(*(p_p+i), ' ', _N);
    }

    //memCOPY
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            //space case
            if (p[i][j] == ' ')  continue;

            //spot case :left-upper corner
            else {
                int row_loc = i * (_N/N);
                int line_loc = j * (_N/N);
                for (int _i=row_loc; _i<(i+1) * (_N/N); _i++){
                    for (int _j=line_loc; _j<(j+1) * (_N/N); _j++){
                        p_p[_i][_j] = o_p[_i%(_N/N)][_j%(_N/N)];
                    }
                }
            }
        }
    }

    // release mem
    if (size > 2){
        for (int i=0; i<(_N/N); i++){
            free(*(o_p+i));
        }
        free(o_p);
    }

    return p_p;
}

int main(){
    int N;
    int Q;
    while (scanf("%d", &N) != EOF){
        //clear the \n in stdin buffer
        getchar();
        //exit
        if (N == 0) break;

        //create a dynamic array
        char **p;
        p = (char **)malloc(N*(sizeof(char *)));
        for (int i=0; i<N; i++){
            *(p+i) = (char*)malloc(N*sizeof(char));
        }

        //input the basic pattern
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (j == N-1) 
                {
                    scanf("%c", &p[i][j]);
                    getchar();
                }
                else scanf("%c", &p[i][j]);
            }
        }

        // //dispaly
        // for (int i=0; i<N; i++){
        //     for (int j=0; j<N; j++){
        //         if (j == N-1) printf("%c\n", p[i][j]);
        //         else printf("%c", p[i][j]);
        //     }
        // }

        //scale the pattern
        scanf("%d", &Q);
        char **p_p;
        p_p = scalePattern(Q, p, N);

        int _N = N;
        for (int i=1; i<Q; i++){
        _N *= N;
        }

        //print
        for (int i=0; i<_N; i++){
            for (int j=0; j<_N; j++){
                    if (j == _N-1) printf("%c\n", p_p[i][j]);
                    else printf("%c", p_p[i][j]);
            }
        //release
        free(*(p_p+i));
        }
        free(p_p);

        //release
        for (int i=0; i<N ;i++){
            free(*(p+i));
        }
        free(p);
    }
}