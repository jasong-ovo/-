#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

// priority_queue<int, vector<int>, greater<int>> a;

struct Int
{
    int a;
    Int(int b) {
        a = b;
    }
    bool operator<( Int tmp) const {
        if (a > tmp.a) return true;
        return false;
    }
};

priority_queue<Int> nums;
int order = 0;
int last = 0;
int main(){
    int N;
    scanf("%d", &N);
    while(N--) {
        int tmp;
        scanf("%d", &tmp);
        nums.push(tmp);
    }

    // while (nums.size() > 0)
    // {
    //     printf("%d ", nums.top());
    //     nums.pop();
    // }
    while(1) {
        int tmp = nums.top().a;
        nums.pop();
        if (tmp == last) continue;
        order ++;
        last = tmp;
        if (order == 3) {
            printf("%d ",tmp);
            return 0;
        }
    }
    return 0;
}