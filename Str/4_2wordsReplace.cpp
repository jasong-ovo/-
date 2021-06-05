#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(){
    string str, str1, str2;
    while (getline(cin, str)){
        getline(cin, str1);
        getline(cin, str2);
        // cout<<str<<endl;
        // cout<<str1<<endl;
        // cout<<str2<<endl;
        int position = 0;
        int size1 = str1.size();
        int size2 = str2.size();
        //insert
        //&& (str[position + size1] == ' ' || str[position + size1] == '\0')
        while ((position = str.find(str1, position)) != string::npos) {
            if ((str[position + size1] == ' ' || str[position + size1] == '\0') && (str[position - 1] == ' ' || position == 0))
            {str.erase(position, size1);
            str.insert(position, str2);
            position += size2;}
            else position += 1;
        }
        cout<<str<<endl;
    }
    return 0;
}