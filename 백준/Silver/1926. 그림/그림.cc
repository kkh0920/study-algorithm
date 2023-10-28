#include <bits/stdc++.h>
using namespace std;

int N, M, arr[500][500], result = 0, c = 0;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 }; 
bool visited[500][500];

void bfs(int si, int sj){
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    int cnt = 1;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= M)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] == 0)
                continue;
            cnt++;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
    result = max(result, cnt);
    c++;
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

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && arr[i][j] == 1)
                bfs(i, j);
        }
    }

    cout << c << '\n';
    cout << result << '\n';
}