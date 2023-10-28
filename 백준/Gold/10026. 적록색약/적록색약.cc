#include <bits/stdc++.h>
using namespace std;

queue< pair<int, int> > q;
char grid[100][101];
int N, result1 = 0, result2 = 0;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool visited[100][100], visited2[100][100];

void bfs(){
    visited[q.front().first][q.front().second] = true;
    result1++;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                continue;
            if(visited[nI][nJ])
                continue;
            if(grid[nI][nJ] != grid[curI][curJ])
                continue;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
}

void bfs2(){
    visited2[q.front().first][q.front().second] = true;
    result2++;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                continue;
            if(visited2[nI][nJ])
                continue;
            if(grid[curI][curJ] != 'B' && grid[nI][nJ] == 'B')
                continue;
            if(grid[curI][curJ] == 'B' && grid[nI][nJ] != 'B')
                continue;
            visited2[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
            visited2[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                q.push(make_pair(i, j));
                bfs();
            }
            if(!visited2[i][j]){
                q.push(make_pair(i, j));
                bfs2();
            }
        }
    }

    cout << result1 << ' ' << result2 << '\n';
}