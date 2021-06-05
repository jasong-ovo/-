#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
//递归太多，oj跑不动
using namespace std;

int N = 8;
int *ways[92];
bool board[8][8];
int cnt = 0; //mark how much sequences have been found
vector<int> tmp;
void setBoard(int r, int l);

// void boardCopy(bool *des[], bool *src[]){
//     for (int i=0; i<N; i++){
//         for (int j=0; j<N; j++){
//             des[i][j] = src[i][j];
//         }
//     }
// }

void dumpTmp(){
    for (int i=0; i<tmp.size(); i++){
        printf("%d", tmp[i]);
    }
    printf("\n\n");
}

void dumpBoard(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n######\n");
}


bool compare(int *a, int *b){
    for (int i=0; i<N; i++){
        if (a[i] < b[i]) return true;
    }
    return false;
}


void init(){
    // the wys
    for (int i=0; i<92; i++){
        ways[i] = (int *) malloc(sizeof(int) * 8);
        memset(ways[i], 0, sizeof(int) * 8);
    }
    //the board
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            board[i][j] = true;
        }
    }
    return;
}


void findQuenns(int row) {
    // dumpTmp();
    // dumpBoard();
    //check whether this row can hold a quuen
    for (int j=0; j<8; j++){
        if (board[row][j]) {
            //(i,j) can hold then set row and line
            tmp.push_back(j + 1);
            if (row == 7) {
                for (int k=0; k<8; k++){
                    ways[cnt][k] = tmp[k];
                }
                cnt ++;
                tmp.pop_back();
                return;
            }
            bool copy_board[8][8];
            // boardCopy(copy_board, board);
            for (int i1=0; i1<N; i1++){
                for (int j1=0; j1<N; j1++){
                    copy_board[i1][j1] = board[i1][j1];
                }
            }
            //******************************
            setBoard(row, j);
            findQuenns(row + 1);
            //recover
            for (int i1=0; i1<N; i1++){
                for (int j1=0; j1<N; j1++){
                    board[i1][j1] = copy_board[i1][j1];
                }
            }
            //******************************
            tmp.pop_back();
        }
    }

    return;
}


void setBoard(int row, int line){
    //row
    //line
    //dia
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (i == row) board[i][j] = false;
            if (j == line) board[i][j] = false;
            if ( (line - row) == (j - i)) board[i][j] = false;
            if ((line - 7 + row) == (j - 7 + i)) board[i][j] = false;
        }
    }
    
    return;
}


int main(){
    init();
    findQuenns(0);
    // printf("cnt:%d\n", cnt);
    // // sort((int**)ways, (int**)ways+92, compare);
    // printf("cnt:%d\n", cnt);

    int n;
    scanf("%d", &n);
    while (n-- > 0){
        int b;
        scanf("%d", &b);
        for (int i=0; i<8; i++){
            printf("%d", ways[b-1][i]);
        }
        printf("\n");
    }

    // for (int b=0; b<92; b++){
    //     for (int i=0; i<8; i++){
    //         printf("%d", ways[b][i]);
    //     }
    //     printf("\n");
    // }
    return 0;
}