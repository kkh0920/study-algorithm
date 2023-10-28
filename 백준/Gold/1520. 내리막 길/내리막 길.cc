#include <bits/stdc++.h>
using namespace std;

int arr[500][500], dp[500][500], M, N;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1};
bool visited[500][500];

void init(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = false;
            dp[i][j] = 0;
        }
    }
}

void dfs(){
    init();
    stack< pair<int, int> > s;
    s.push(make_pair(0, 0));
    visited[0][0] = true;
    dp[M - 1][N - 1] = 1;
    while(!s.empty()){
        int I = s.top().first;
        int J = s.top().second;
        
        if(I == M - 1 && J == N - 1){
            s.pop();
            continue;
        }

        int i, temp = 0;
        for(i = 0; i < 4; i++){
            int nI = I + dx[i];
            int nJ = J + dy[i];
            if(nI < 0 || nI >= M || nJ < 0 || nJ >= N)
                continue;
            if(arr[nI][nJ] >= arr[I][J])
                continue;
            if(visited[nI][nJ]){
                temp += dp[nI][nJ];
                continue;
            }
            visited[nI][nJ] = true;
            s.push(make_pair(nI, nJ));
            break;
        }

        if(i == 4){
            dp[I][J] += temp;
            s.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    dfs();

    cout << dp[0][0] << '\n';
}