#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int N, M, K, visited[1001][1001];
char arr[1001][1002];

int bfs(){ 
    queue< pair<int, pair<int, int> > > q;
    q.push(make_pair(K, make_pair(1, 1)));

    visited[1][1] = K;
    int dist = 1;
    while(!q.empty()){
        int size = q.size();
        for(int I = 0; I < size; I++){
            int curI = q.front().second.first;
            int curJ = q.front().second.second;
            int breakableCount = q.front().first;
            q.pop();

            if(curI == N && curJ == M)
                return dist;

            for(int i = 0; i < 4; i++){
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                int nbreakableCount = breakableCount;
                if(nI <= 0 || nI > N || nJ <= 0 || nJ > M)
                    continue;
                if(arr[nI][nJ] == '1'){
                    if(nbreakableCount > 0)
                        nbreakableCount--;
                    else
                        continue;
                }
                if(visited[nI][nJ] >= nbreakableCount)
                    continue;

                visited[nI][nJ] = nbreakableCount;
                q.push(make_pair(nbreakableCount, make_pair(nI, nJ)));
            }
        }
        dist++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
            visited[i][j] = -1;
        }
    }

    cout << bfs() << '\n';
}