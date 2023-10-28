#include <iostream>
#include <queue>
using namespace std;

char arr[50][50];
int N, visited[50][50], dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void bfs(){
    queue< pair< int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(0, 0)));

    visited[0][0] = 0;
    while(!q.empty()){
        int breakCnt = q.front().first;
        int curI = q.front().second.first;
        int curJ = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nCnt = breakCnt;
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                continue;
            if(arr[nI][nJ] == '0')
                nCnt++;
            if(visited[nI][nJ] <= nCnt)
                continue;
            visited[nI][nJ] = nCnt;
            q.push(make_pair(nCnt, make_pair(nI, nJ)));
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
            visited[i][j] = 2500;
        }
    }

    bfs();

    cout << visited[N - 1][N - 1] << '\n';
}