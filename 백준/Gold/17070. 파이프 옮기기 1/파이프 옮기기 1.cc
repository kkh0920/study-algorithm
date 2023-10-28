#include <bits/stdc++.h>
using namespace std;

int N, arr[16][16], visited[3][16][16];
int dx[3] = { 0, 1, 1 }, dy[4] = { 1, 1, 0};

int dfs(int state, int curI, int curJ){
    if(curI == N - 1 && curJ == N - 1)
        return 1;

    for(int i = 0; i < 3; i++){
        if((i == 0 && state == 2) || (i == 2 && state == 0))
            continue;

        int nI = curI + dx[i];
        int nJ = curJ + dy[i];
        if((nI < 0 || nI >= N || nJ < 0 || nJ >= N) || arr[nI][nJ] == 1)
            continue;
        if(i == 1 && (arr[nI - 1][nJ] == 1 || arr[nI][nJ - 1] == 1))
            continue;
        if(visited[i][nI][nJ] > 0){
            visited[state][curI][curJ] += visited[i][nI][nJ];
            continue;
        }
        
        visited[state][curI][curJ] += dfs(i, nI, nJ);
    }

    return visited[state][curI][curJ];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    cout << dfs(0, 0, 1) << '\n';
}