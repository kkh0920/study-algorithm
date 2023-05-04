#include <bits/stdc++.h>
using namespace std;

// BOJ 3109

int R, C, result = 0;
int dx[3] = { -1, 0, 1 }, dy[3] = { 1, 1, 1 };
char arr[10000][501];

bool dfs(int curI, int curJ){
    if(curJ == C - 1){
        result++;
        return true;
    }

    for(int i = 0; i < 3; i++){
        int nI = curI + dx[i];
        int nJ = curJ + dy[i];
        if(nI < 0 || nI >= R)
            continue;
        if(arr[nI][nJ] == 'x')
            continue;

        arr[nI][nJ] = 'x';

        if(dfs(nI, nJ))
            return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < R; i++){
        dfs(i, 0);
    }

    cout << result << '\n';
}
