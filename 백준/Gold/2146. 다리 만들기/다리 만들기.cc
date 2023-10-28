#include <bits/stdc++.h>
using namespace std;

int N, arr[100][100], cnt = 0, result = 10000;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool visited[100][100];

void initVisited(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = false;
        }
    }
}

void bfs1(int curI, int curJ){
    queue< pair<int, int> > q;
    q.push(make_pair(curI, curJ));
    visited[curI][curJ] = true;
    arr[curI][curJ] += cnt;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] == 0)
                continue;
            visited[nI][nJ] = true;
            arr[nI][nJ] += cnt;
            q.push(make_pair(nI, nJ));
        }
    }
    cnt++;
}

void bfs2(int curI, int curJ, int num){
    queue< pair< int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(curI, curJ)));
    initVisited();
    visited[curI][curJ] = true;
    while(!q.empty()){
        int curCost = q.front().first;
        int curI = q.front().second.first;
        int curJ = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nCost = curCost + 1;
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                continue;
            if(visited[nI][nJ])
                continue;
            if(arr[nI][nJ] == num)
                continue;
            if(arr[nI][nJ] != 0 && arr[nI][nJ] != num){
                result = min(result, curCost);
                return;
            }
            visited[nI][nJ] = true;
            q.push(make_pair(nCost, make_pair(nI, nJ)));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] && !visited[i][j])
                bfs1(i, j);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j])
                bfs2(i, j, arr[i][j]);
        }
    }

    cout << result << '\n';
}