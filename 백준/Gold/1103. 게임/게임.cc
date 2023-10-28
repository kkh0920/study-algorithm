#include <iostream>
using namespace std;

int N, M, dp[50][50];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[50][51];
bool visited[50][50];

bool dfs(int curI, int curJ){
    for(int i = 0; i < 4; i++){
        int nI = curI + dx[i] * (arr[curI][curJ] - '0');
        int nJ = curJ + dy[i] * (arr[curI][curJ] - '0');
        
        if(nI < 0 || nI >= N || nJ < 0 || nJ >= M || arr[nI][nJ] == 'H')
            continue;
        if(visited[nI][nJ])
            return true;
        if(dp[nI][nJ] > 0){
            dp[curI][curJ] = max(dp[curI][curJ], dp[nI][nJ]);
            continue;
        }
        
        visited[nI][nJ] = true;

        if(dfs(nI, nJ))
            return true;

        dp[curI][curJ] = max(dp[curI][curJ], dp[nI][nJ]);
        visited[nI][nJ] = false;
    }
    dp[curI][curJ]++;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    visited[0][0] = true;
    if(dfs(0, 0))
        dp[0][0] = -1;

    cout << dp[0][0] << '\n';
}