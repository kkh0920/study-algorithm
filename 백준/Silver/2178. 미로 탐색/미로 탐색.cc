#include <bits/stdc++.h>
using namespace std;

int N, M, result = 1;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[100][101];
bool visited[100][100];

void bfs(){
    queue< pair<int, int> > q;
    q.push(make_pair(0, 0));

    visited[0][0] = true;
    while(!q.empty()){
        result++;
        int size = q.size();
        for(int i = 0; i < size; i++){
            int curI = q.front().first;
            int curJ = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(nI < 0 || nI >= N || nJ < 0 || nJ >= M)
                    continue;
                if(visited[nI][nJ] || arr[nI][nJ] == '0')
                    continue;
                if(nI == N - 1 && nJ == M - 1)
                    return;
                
                visited[nI][nJ] = true;
                q.push(make_pair(nI, nJ));
            }
        }
    }
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

    bfs();

    cout << result << '\n';
}