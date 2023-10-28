#include <bits/stdc++.h>
using namespace std;

// BOJ 3197

// bfs를 여러번 수행 -> 매번 첫 위치부터 탐색하면 시간초과

/* 빙벽을 만났을 때 bfs가 끊기게 되는데, 
   다음 bfs를 수행할 때 끊긴 부분부터 다시 탐색할 수 있도록 
   전역으로 선언된 nextSwan과 water를 bfs내에서 복사해서 사용 */

vector< pair<int, int> > swans;

queue< pair<int, int> > nextSwan;
queue< pair<int, int> > water;

int R, C;
int dx[4] = { -1, 1, 0, 0, }, dy[4] = { 0, 0, -1, 1 };
char arr[1500][1501];

bool visited[1500][1500], visited2[1500][1500];

void remove(){
    queue< pair<int, int> > temp = water;

    while(!water.empty()){
        water.pop();
    }

    while(!temp.empty()){
        int curI = temp.front().first;
        int curJ = temp.front().second;
        temp.pop();

        arr[curI][curJ] = '.';
    
        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= R || nJ < 0 || nJ >= C)
                continue;
            if(visited[nI][nJ])
                continue;
            visited[nI][nJ] = true;
            water.push(make_pair(nI, nJ));
        }
    }
}

bool isMeet(){
    queue< pair<int, int> > swan = nextSwan;

    while(!nextSwan.empty()){
        nextSwan.pop();
    }

    while(!swan.empty()){
        int curI = swan.front().first;
        int curJ = swan.front().second;
        swan.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= R || nJ < 0 || nJ >= C)
                continue;
            if(visited2[nI][nJ])
                continue;
            if(arr[nI][nJ] == 'X'){
                visited2[nI][nJ] = true;
                nextSwan.push(make_pair(nI, nJ));
                continue;
            }
            if(nI == swans[1].first && nJ == swans[1].second)
                return true;
            visited2[nI][nJ] = true;
            swan.push(make_pair(nI, nJ));
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
            
            visited[i][j] = false; 
            visited2[i][j] = false;

            if(arr[i][j] == 'L'){
                swans.push_back(make_pair(i, j));
                arr[i][j] = '.';
            }

            if(arr[i][j] == '.'){
                water.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
    visited2[swans[0].first][swans[0].second] = true;
    nextSwan.push(swans[0]);

    remove();

    int time = 0;
    while(1){
        if(isMeet())
            break;

        remove(); 

        time++;
    }

    cout << time << '\n';
}