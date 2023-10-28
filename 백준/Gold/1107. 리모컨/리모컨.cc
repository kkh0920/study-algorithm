#include <bits/stdc++.h>
using namespace std;

bool isBroken[10] = { false };
int N, M, n, result = 500000;
string str = "";

void select(int n, int len){
    if(n == 0){
        int num = stoi(str);
        int res = N > num ? N - num : num - N;
        
        res += len;

        result = min(result, res);
        return;
    }

    for(char i = '0'; i <= '9'; i++){
        if(isBroken[i - '0'])
            continue;
            
        str += i;
        
        select(n - 1, len);

        str.erase(str.end() - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> n;
        isBroken[n] = true;
    }

    for(int i = 1; i <= 6; i++){
        select(i, i);
    }

    result = min(result, abs(N - 100));

    cout << result << '\n';
}   
