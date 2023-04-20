#include <bits/stdc++.h>
using namespace std;

// BOJ 1600

// visited 변수를 int형으로 선언, -1로 초기화
// movableHorseCnt 혹은 nextHorseCnt(movableHorseCnt - 1)을 방문하는 노드마다 저장.
// 방문하는 다음 노드에 저장될 Cnt값이, 이미 저장된 Cnt보다 작으면 패스한다.
// 백트래킹 -> 남아있는 Cnt가 작으면 목표 노드까지 갈 수 있는 가능성이 적음

int visited[200][200];
int arr[200][200], k, w, h, result = -1;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int horseX[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int horseY[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

void bfs(){
    queue< pair< int, pair<int, int> > > q;
    q.push(make_pair(k, make_pair(0, 0)));
    visited[0][0] = k;
    int moveCnt = 0;
    while(!q.empty()){
        int size = q.size();
        for(int j = 0; j < size; j++){
            int movableHorseCnt = q.front().first;
            int curI = q.front().second.first;
            int curJ = q.front().second.second;
            q.pop();

            if(curI == h - 1 && curJ == w - 1){
                result = moveCnt;
                return;
            }

            for(int i = 0; i < 4; i++){
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(nI < 0 || nI >= h || nJ < 0 || nJ >= w)
                    continue;
                if(visited[nI][nJ] >= movableHorseCnt || arr[nI][nJ] == 1)
                    continue;
                visited[nI][nJ] = movableHorseCnt;
                q.push(make_pair(movableHorseCnt, make_pair(nI, nJ)));
            }

            if(!movableHorseCnt)
                continue;

            for(int i = 0; i < 8; i++){
                int nI = curI + horseX[i];
                int nJ = curJ + horseY[i];
                int nextHorseCnt = movableHorseCnt - 1;
                if(nI < 0 || nI >= h || nJ < 0 || nJ >= w)
                    continue;
                if(visited[nI][nJ] >= nextHorseCnt || arr[nI][nJ] == 1)
                    continue;
                visited[nI][nJ] = nextHorseCnt;
                q.push(make_pair(nextHorseCnt, make_pair(nI, nJ)));
            }
        }
        moveCnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> w >> h;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> arr[i][j];
            visited[i][j] = -1;
        }
    }

    bfs();

    cout << result << '\n';
}