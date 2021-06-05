//宽度优先搜索，每一步分为一个子解空间
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct codes
{
    string cipher;
    int lastLoc;
    int rounds;
    codes(string c, int l, int r){
        cipher = c;
        lastLoc = l;
        rounds = r;
    }
};

queue <codes> search;

bool find2012(string cipher, int n){
    for (int i=0; i<n-3; i++){
        if (cipher[i] == '2' && cipher[i+1]=='0' && cipher[i+2]=='1' && cipher[i+3]=='2')
        return true;
    }
    return false;
}

int BFS (string cipher, int n){
    // printf("cipher in len:%d\n", cipher.length());

    //check the simplist condition
    if (n<4) return -1;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i=0; i<n; i++){
        switch (cipher[i])
        {
        case '0':
            cnt0 ++;
            break;
        case '1':
            cnt1 ++;
            break;
        case '2':
            cnt2 ++;
            break;        
        default:
            break;
        }
    }
    if (cnt0 < 1 || cnt1 < 1 || cnt2 < 2) {
        return -1;
    }

    //init state
    codes init(cipher, -1, 0);
    if(find2012(cipher, n)) return init.rounds;
    search.push(init);

    //bfs
    while(1){
        codes parent = search.front();
        search.pop();
        int lastLoc = parent.lastLoc;
        int rounds = parent.rounds + 1;
        for (int i=0; i<n-1; i++){
            if (i==lastLoc) continue;
            string tmpCipher = parent.cipher;
            char tmp = tmpCipher[i];
            // printf("len:%d\n", tmpCipher.length());
            tmpCipher.erase(i, 1);
            tmpCipher.insert(i+1, 1, tmp);
            if (find2012(tmpCipher, n)) return rounds;
            codes tmpCodes(tmpCipher, i, rounds);
            search.push(tmpCodes);
        }
    }
}
int main(){
    int N;
    scanf("%d", &N);
    getchar();
    string cipher;
    getline(cin, cipher);
    printf("%d", BFS(cipher, N));
    return 0;
}
