//蚂蚁作为存在的元素
//piece的3个指针指向蚂蚁或者空蚂蚁表示信息
#include <iostream>
#include <cstdio>

using namespace std;

struct ant
{
    int loc;
    int state;

    ant (int p=1, int s=0){
        loc = p;
        state = s;
    }
};

struct stickPiece
{
    ant * antsOn;
};


int main(){
    //init
    int N;
    int time = 0;
    bool activity_flag = false;
    scanf("%d", &N);

    //simulate the stick
    stickPiece stick[101];
    for (int i=0; i<101; i++) {
        stick[i].antsOn = (ant*) malloc(3*sizeof(ant));
        for (int j=0; j<3; j++){
            stick[i].antsOn[j] = ant(i, -2);
        }
    }

    //place the ants
    for (int i=0; i<N; i++){
        int P, S;
        scanf("%d %d", &P, &S);
        for (int j=0; j<3; j++)
        {
            if(stick[P].antsOn[j].state == -2){
                stick[P].antsOn[j] = ant(P, S);
                break;
                }
            }
    }

    //simulate the activity
    for (; ; time++){
        activity_flag = false;

        //loop all the piece
        //step 1:move
        for (int i=0; i<101; i++){
            if (i==0 || i==100) continue;
            for (int j = 3; j>=1; j--){
                int s, p, des;
                s = stick[i].antsOn[j].state;
                if(s != -2) {
                    if (s == 0) {
                        continue;
                    }
                    else {
                        activity_flag = true;
                        stick[i].antsOn[j].state = -2;
                        des = i + s;

                        //enter the destination
                        for (int k=0; k<3; k++){
                            if (stick[des].antsOn[k].state != -2) continue;
                            else {
                                stick[des].antsOn[k].loc = des;
                                stick[des].antsOn[k].state = s;
                                }
                        }

                    }
                }
            }

        }

        // if not activity
        if (!activity_flag) {
            
            break;}

        //step 2:clear
        for (int i=0; i<101; i++)
        {
           if (i == 0 || i == 100) {
               for (int j=0; j<3; j++){
                   stick[i].antsOn[j].state = -2;
               }
           }

           else {
               /**/
           }
        }
        
    }
    return 0;
}