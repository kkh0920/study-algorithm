#include <bits/stdc++.h>
using namespace std;

int N, M, visited[101][101];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[101][102]; 

void bfs(){
    queue< pair<int, int> > q;
    q.push(make_pair(1, 1));
    visited[1][1] = 0;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            int next = visited[curI][curJ];
            if(nI < 1 || nI > N || nJ < 1 || nJ > M)
                continue;
            if(arr[nI][nJ] == '1')
                next++;
            if(next >= visited[nI][nJ])
                continue;
            
            visited[nI][nJ] = next;
            q.push(make_pair(nI, nJ));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
            visited[i][j] = 100 * 100;
        }
    }

    bfs();

    cout << visited[N][M] << '\n';
}