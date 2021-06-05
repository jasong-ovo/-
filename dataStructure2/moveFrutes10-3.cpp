#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> fruites;
int sum = 0;
int main(){
    int N;
    scanf("%d", &N);
    while (N -- >0)
    {   int tmp;
        scanf("%d", &tmp);
        fruites.push(tmp);
    }

    while(fruites.size() > 1) {
        int a = fruites.top();
        fruites.pop();
        int b = fruites.top();
        fruites.pop();
        sum += a + b;
        fruites.push(a+b);
    }

    printf("%d", sum);
    // while (!fruites.empty())
    // {   
    //     printf("%d ", fruites.top());
    //     fruites.pop();
    // }
    
    return 0;
}