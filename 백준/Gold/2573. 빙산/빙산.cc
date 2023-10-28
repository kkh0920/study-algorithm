#include <bits/stdc++.h>
using namespace std;

queue< pair<int, int> > q;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int N, M, arr[300][300], temp[300][300], result = 0, cnt = 0, tempCnt = 0;
bool visited[300][300];

void initVisited(){
    tempCnt = 1;
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            visited[i][j] = false;
        }
    }
    visited[q.front().first][q.front().second] = true;
}

void dfs(int curI, int curJ){
    for(int i = 0; i < 4; i++){
        int nI = curI + dx[i];
        int nJ = curJ + dy[i];
        if(visited[nI][nJ])
            continue;
        if(arr[nI][nJ] <= 0)
            continue;
        visited[nI][nJ] = true;
        tempCnt++;
        dfs(nI, nJ);
    }
}

void bfs(){
    while(!q.empty()){
        initVisited();
        dfs(q.front().first, q.front().second);
        if(tempCnt < cnt)
            return;

        int size = q.size();
        for(int i = 0; i < size; i++){
            int curI = q.front().first;
            int curJ = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(arr[nI][nJ] == 0) // 배열의 모든 가장자리는 0 이므로, outOfBound X
                    temp[curI][curJ]++;
            }
        }

        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                arr[i][j] -= temp[i][j];
                if(arr[i][j] <= 0){
                    cnt -= temp[i][j] != 0 ? 1 : 0;
                    arr[i][j] = 0;
                }
                if(arr[i][j] > 0)
                    q.push(make_pair(i, j));
                temp[i][j] = 0;
            }
        }
        result++;
    }
    result = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            temp[i][j] = 0;
            if(arr[i][j] != 0){
                q.push(make_pair(i, j));
                cnt++;
            }
        }
    }

    bfs();

    cout << result << '\n';
}