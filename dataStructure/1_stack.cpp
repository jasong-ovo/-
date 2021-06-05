#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    //init
    int n;
    stack<int> stack1;
    while(scanf("%d", &n)!=EOF){
        
        while (n>0) {
            n --;
            char cmd;
            int val;
            scanf("%*[\n' ']%c", &cmd);
            // printf("cmd:%c\n", cmd);
            switch (cmd)
            {
            case 'P':
                scanf("%d", &val);
                stack1.push(val);
                break;
            
            case 'O':
                if (!stack1.empty()) stack1.pop();
                break;

            case 'A':
                if (stack1.empty()) printf("E\n");
                else printf("%d\n", stack1.top());
                break;

            default:
                break;
            }
        }
        printf("\n");

        while (!stack1.empty())
        {
            stack1.pop();
        }
        
    }


    return 0;
}