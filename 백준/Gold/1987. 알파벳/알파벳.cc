#include <bits/stdc++.h>
using namespace std;

int R, C, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[20][21];
bool visited[26] = { false };

int result = 0;

void dfs(int si, int sj, int cnt){
    for(int i = 0; i < 4; i++){
        int nI = si + dx[i];
        int nJ = sj + dy[i];
        if(nI < 0 || nI >= R || nJ < 0 || nJ >= C)
            continue;
        if(visited[arr[nI][nJ] - 'A'])
            continue;
        
        visited[arr[nI][nJ] - 'A'] = true;

        dfs(nI, nJ, cnt + 1);

        visited[arr[nI][nJ] - 'A'] = false;
    }
    result = max(result, cnt);
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

    visited[arr[0][0] - 'A'] = true;
    
    dfs(0, 0, 1);

    cout << result << '\n';
}