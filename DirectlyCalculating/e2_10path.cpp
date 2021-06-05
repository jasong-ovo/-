#include <iostream>
#include <cstdio>

using namespace std;
//用树？
int main (){
    //init
    int n;
    scanf("%d", &n);
    char path1[50] = {'\0'};
    char path2[50] = {'\0'};

    char * p_p, * o_p;
    
    p_p = path1;
    o_p = path2;

    while (getchar()) {
        scanf("%s", p_p);
        if (p_p[0] == '0') break;

        //standarlize
        for (int i=0; p_p[i] != '\0'; i++){
            if (p_p[i] != '\\' && p_p[i+1] == '\0') p_p[i+1] = '\\';
        }

        //debug
        // printf("%s\n", p_p);
        // printf("%s\n", o_p);

        //determine the same part
        int loc = -1; //the last location p_p and o_p have the same value
        for (int i=0; o_p[i] != '\0' && p_p[i] != '\0'; i++){
            if (p_p[i] != o_p[i]) break;
            loc = i;
        }

        //print
        int numSpace = 0;
        //1 compute the Space num comes from the same part
        for (int i=0;i < loc + 1; i++){
            if (p_p[i]=='\\') numSpace ++;
        }
        //2 print the left part
        int internal = 0;
        for (int i=loc + 1; p_p[i] != '\0'; i = i + internal){
            internal = 0;
            for (int j=0; j<numSpace; j++){
                printf(" ");
            }
            for (int j = i; p_p[j] != '\\'; j++) {
                printf("%c", p_p[j]);
                internal ++;
            }
            internal ++; //skip '\\'
            // printf("mark:%d",internal);
            printf("\n");
            numSpace ++;
        }

        //exchange the array to record the new input
        char * temp;
        temp = o_p;
        o_p = p_p;
        p_p = temp;    
        for (int i=0; p_p[i] != '\0'; i++){
            p_p[i] = '\0';
        }
    }
    return 0;
}



