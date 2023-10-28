#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > virus, temp;
int N, M, result = 2500, origin[50][50], arr[50][50], zeroCntOrigin = 0;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = origin[i][j];
        }
    }
}

void bfs(){
    queue< pair<int, int> > q;
    for(int i = 0; i < M; i++){
        q.push(temp[i]);
        arr[temp[i].first][temp[i].second] = 3;
    }

    int time = 0;
    int zeroCnt = zeroCntOrigin;
    while(!q.empty() && zeroCnt){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int curI = q.front().first;
            int curJ = q.front().second;
            q.pop();
            
            for(int j = 0; j < 4; j++){
                int nI = curI + dx[j];
                int nJ = curJ + dy[j];
                if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                    continue;
                if(arr[nI][nJ] == 1 || arr[nI][nJ] == 3)
                    continue;

                if(arr[nI][nJ] == 0)
                    zeroCnt--;
                arr[nI][nJ] = 3;
                q.push(make_pair(nI, nJ));
            }
        }
        time++;
    }
    if(!zeroCnt)
        result = min(result, time);
}

void placeVirus(int idx, int n){
    if(n == M){
        init();
        bfs();
        return;
    }
    for(int i = idx; i < virus.size(); i++){
        temp.push_back(virus[i]);
        placeVirus(i + 1, n + 1);
        temp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> origin[i][j];
            if(origin[i][j] == 2)
                virus.push_back(make_pair(i, j));
            if(origin[i][j] == 0)
                zeroCntOrigin++;
        }
    }

    placeVirus(0, 0);

    if(result == 2500)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}