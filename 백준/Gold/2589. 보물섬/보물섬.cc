#include <iostream>
#include <queue>
using namespace std;

int N, M, result = 0, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[50][51];
bool visited[50][50];

void initVisited(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(int si, int sj){
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));

    initVisited();
    visited[si][sj] = true;

    int maxDist = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int curI = q.front().first;
            int curJ = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(nI < 0 || nI >= N || nJ < 0 || nJ >= M)
                    continue;
                if(visited[nI][nJ] || arr[nI][nJ] == 'W')
                    continue;
                visited[nI][nJ] = true;
                q.push(make_pair(nI, nJ));
            }
        }
        maxDist++;
    }

    result = max(result, maxDist - 1);
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
            if(arr[i][j] == 'L')
                bfs(i, j);
        }
    }

    cout << result << '\n';
}
