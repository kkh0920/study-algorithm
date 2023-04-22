#include <bits/stdc++.h>
using namespace std;

// BOJ 17135

// visited[archer[idx].first][archer[idx].second] = true;
// 궁수가 있는 위치는 배열을 초과하는 곳.
// 따라서 해당 코드는 ouOfBound를 유발.
// 백준 시스템 상에서는 왜 '틀렸습니다'가 나오는지는 모르겠지만, 해당 코드를 지워줌으로써 AC를 받을 수 있었음.

vector< pair<int, int> > archer;
int N, M, D, originEnemyCount = 0, enemyCount, origin[15][15], arr[15][15];
int dx[3] = { 0, -1, 0 }, dy[3] = { -1, 0, 1 };
int result = 0, tempResult = 0;
bool visited[15][15], isSensed[15][15];

void init(){
    tempResult = 0;
    enemyCount = originEnemyCount;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            arr[i][j] = origin[i][j];
        }
    }
}

void initVisited(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = false;
        }
    }
}

void moveEnemy(){
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == 1){
                arr[i][j] = 0;
                if(i == N - 1)
                    enemyCount--;
                else
                    arr[i + 1][j] = 1;   
            }
        }
    }
}

void killEnemy(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(isSensed[i][j]){
                isSensed[i][j] = false;
                arr[i][j] = 0;
                tempResult++;
                enemyCount--;
            }
        }
    }
}

void senseEnemy(int idx){
    initVisited();
    queue< pair<int, int> > q;
    q.push(archer[idx]);

    int dist = 0;
    bool isEnd = false;
    while(!q.empty()){
        dist++;

        if(dist > D)
            return;

        int size = q.size();
        for(int i = 0; i < size; i++){
            int archerI = q.front().first;
            int archerJ = q.front().second;
            q.pop();

            for(int j = 0; j < 3; j++){
                int nextI = archerI + dx[j];
                int nextJ = archerJ + dy[j];
                if(nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= M)
                    continue;
                if(visited[nextI][nextJ])
                    continue;
                if(arr[nextI][nextJ] == 1){
                    isSensed[nextI][nextJ] = true;
                    return;
                }
                visited[nextI][nextJ] = true;
                q.push(make_pair(nextI, nextJ));
            }
        }
    }
}

void simulation(){
    while(enemyCount){
        for(int i = 0; i < 3; i++){
            senseEnemy(i);
        }
        killEnemy();
        moveEnemy();
    }
}   

void placeArcher(int num, int idx){
    if(num == 0){
        init();
        simulation();
        result = max(result, tempResult);
        return;
    }
    for(int i = idx; i < M; i++){
        archer.push_back(make_pair(N, i));

        placeArcher(num - 1, i + 1);
        
        archer.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> D;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> origin[i][j];
            if(origin[i][j] == 1)
                originEnemyCount++;
            isSensed[i][j] = false;
        }
    }

    placeArcher(3, 0);

    cout << result << '\n';
}