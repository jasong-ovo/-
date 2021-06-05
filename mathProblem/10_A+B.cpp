#include <cstdio>
#include <iostream>

using namespace std;

// void reset(int **p){
//     for (int i=0; i<100; i++){
//         for(int j=0; j<100; j++){
//             p[i][j] = 0;
//         }
//     }
// }

int main(){
    int colums, rows;
    int A[100][100], B[100][100];

    while (scanf("%d%d", &rows, &colums) != EOF){
        int answer = 0;


        //init
        for (int i=0; i<rows; i++){
            for (int j=0; j<colums; j++){
                scanf("%d", &A[i][j]);
            }
        }

        for (int i=0; i<rows; i++){
            for (int j=0; j<colums; j++){
                scanf("%d", &B[i][j]);
            }
        }


        //compute
        for (int i=0; i<rows; i++){
            for (int j=0; j<colums; j++){
                A[i][j] += B[i][j];
            }
        }


        //check
        for (int i=0; i<rows; i++){
            bool flag = true;
            for (int j=0; j<colums; j++){
                if (A[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        }

        for (int j=0; j<colums; j++){
            bool flag = true;
            for(int i=0; i<rows; i++){
                if (A[i][j]) {
                    flag =false;
                    break;
                }
            }

            if (flag) answer++;
        }


        //print
        printf("%d\n", answer);

    }
}