#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<string> agents;
vector<string> servers;


int agentForward(){
    int answer = 0;
    int requests = servers.size();

    vector<string> tmp_agents;
    string tmp;
    tmp_agents = agents;
    
    int loc = 0;
    int resources = agents.size();

    if (agents.size() == 1) {
        for (int i = 0; i<requests; i++){
            if (agents[0] == servers[i]) return -1;
        }
    }
    
    for (int i=0; i<requests; i++){
        for (int j=0; j<resources; j++){
            tmp = tmp_agents[j];
            if (tmp == servers[i]) {
                loc = i;
                tmp_agents.erase(tmp_agents.begin()+j);
                resources = tmp_agents.size();
                if (resources == 0) {
                    answer ++;
                    freopen("data.txt", "a", stdout);
                    printf("loc:%d\n", i);
                    // freopen(sstdou, "w", stdin);
                    int a_s = agents.size();
                    for (int i = 0; i < a_s; i++){
                        if (agents[i] == tmp) continue;
                        tmp_agents.push_back(agents[i]);
                    }
                    resources = tmp_agents.size();
                }
                break;
            }
        }

    }

    return answer;
}
int main(){
    //init
    int n, m;
    scanf("%d", &n);
    getchar();
    for (int i=0; i<n; i++){
        string tmp;
        getline(cin, tmp);
        agents.push_back(tmp);
        // cout<<"tmp:"<<tmp<<endl;
    }
    scanf("%d", &m);
    getchar();
    for (int i=0; i<m; i++){
        string tmp;
        getline(cin, tmp);
        servers.push_back(tmp);
        // printf("i:%d, m:%d\n", i, m);
    }

    //start to forward
    printf("%d", agentForward());
    return 0;
}