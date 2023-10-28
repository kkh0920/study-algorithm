#include <bits/stdc++.h>
using namespace std; 

queue< pair<int, int> > air;
int N, M, arr[100][100], resultTime = 0, resultCnt = 0, cnt = 0;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool visited[100][100];

bool bfs(){
    if(cnt == 0)
        return true;

    queue< pair<int, int> > temp = air;

    while(!air.empty()){
        air.pop();
    }

    while(!temp.empty()){
        int curI = temp.front().first;
        int curJ = temp.front().second;
        temp.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= M)
                continue;
            if(visited[nI][nJ]) 
                continue;
            if(arr[nI][nJ] == 1){
                visited[nI][nJ] = true;
                air.push(make_pair(nI, nJ));
                continue;
            }
            visited[nI][nJ] = true;
            temp.push(make_pair(nI, nJ));
        }
    }

    int size = air.size();

    if(size == cnt)
        resultCnt = cnt;

    while(size--){
        arr[air.front().first][air.front().second] = 0;
        cnt--;

        air.push(air.front());
        air.pop();
    }

    resultTime++;

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
            if(arr[i][j] == 1)
                cnt++;
            if(i == 0 || i == N - 1 || j == 0 || j == M - 1){
                air.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    while(1){
        if(bfs())
            break;
    }

    cout << resultTime << '\n';
    cout << resultCnt << '\n';
}