#include <iostream>
#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

//init
stack<char> sign_stack;
string str;
stack<int> num_stack;



int priority(char sign) {
    if (sign == '#') return 1;
    else if (sign == '$') return 0;
    else if (sign == '+' || sign == '-') return 2;
    else if (sign == '*' || sign == '/' ) return 3;
    return -1;
}


int compute(char sign, int num1, int num2){
    if (sign == '+') return num1 + num2;
    else if (sign == '-') return num1 - num2;
    else if (sign == '*') return num1 * num2;
    else if (sign == '/') return num1 / num2;
    return -1;
}


int getNum(int *id){
    int i;
    i = *id;
    int sum = 0;
    while (str[i]>='0' && str[i]<='9'){
        sum *= 10;
        sum += str[i] - '0';
        i++;
        // printf("getNum:%c", str[i]);
    }
    // printf("\n");
    *id = i - 1; //fix the i++ in main
    return sum;
}




int main(){
    getline(cin, str);
    str.insert(str.size(), 1, '$');
    sign_stack.push('#');
    int size = str.size();
    int sign;
    int sum = 0, num1, num2;

    for (int i=0; i<size; i++){

        if (str[i] == ' ') continue;

        if (str[i] >= '0' && str[i] <= '9') {
            num_stack.push(getNum(&i));
        }
        else if (priority(str[i]) <= priority(sign_stack.top())) {
            while ((sign_stack.top() != '#')&& priority(str[i]) <= priority(sign_stack.top())){
                sign = sign_stack.top();
                sign_stack.pop();
                num2 = num_stack.top();
                num_stack.pop();
                num1 = num_stack.top();
                num_stack.pop();
                num_stack.push(compute(sign, num1, num2));
                printf("num1:%d, num2:%d, sum:%d\n", num1, num2, num_stack.top());
            }
            sign_stack.push(str[i]);
        }
        else sign_stack.push(str[i]);
    }

    printf("%d\n", num_stack.top());

    return 0;
}
