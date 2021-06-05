#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

struct studenTime
{
    string studen;
    string time;
    studenTime(string str1, string str2){
        studen = str1;
        time = str2;
    }
};

map<string, string> enterMap;
map<string, string> leaveMap;

int main(){
    int N;
    scanf("%d", &N);
    getchar();
    while (N--)
    {   string record;
        getline(cin, record);
        int space1 = record.find(' ');
        int space2 = record.find(' ', space1+1);
        enterMap[record.substr(space1+1, space2-space1-1)] = record.substr(0, space1);
        leaveMap[record.substr(space2+1)] = record.substr(0, space1);
    }
    // for (map<string, string>::iterator it = enterMap.begin(); it != enterMap.end(); it++){
    //     cout<<it->second<<endl;
    // }   

    cout<<enterMap.begin()->second<<' '<<(--leaveMap.end())->second;
    
    return 0;
}