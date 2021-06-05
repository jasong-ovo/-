#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    //init
    int odd[10] = {'\0'};
    int even[10] = {'\0'};
    int temp;
    int p_odd = 0, p_even = 0;

    //load
    for (int i=0; i<10; i++){
        scanf("%d", &temp);
        if (temp%2 == 0) {
            even[p_even] = temp;
            p_even ++;
        }
        else {
            odd[p_odd] = temp;
            p_odd ++;
        }
    }

    //sort
    sort(odd, odd+p_odd);
    sort(even, even+p_even);

    //print
    for (int i=p_odd-1; i>=0; i--){
        printf("%d ", odd[i]);
    }
    for (int i=0; i<p_even; i++){
        printf("%d ", even[i]);
    }

    return 0;
}