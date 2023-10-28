#include <bits/stdc++.h>
using namespace std;

char arr[5][6];
bool visited[5][5], checked[5][5];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int result = 0;

void initVisited(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(int si, int sj){
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));

    initVisited();
    visited[si][sj] = true;

    int cnt = 1;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= 5 || nJ < 0 || nJ >= 5)
                continue;
            if(visited[nI][nJ] || !checked[nI][nJ])
                continue;
            cnt++;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }

    if(cnt == 7)
        result++;
}

void select(int n, int idx, int s_cnt, int X, int Y){
    if(n == 0){
        if(s_cnt >= 4)
            bfs(X, Y);
        return;
    }

    for(int i = idx; i < 5 * 5; i++){
        int x = i / 5;
        int y = i % 5;
        int s = s_cnt;

        if(arr[x][y] == 'S')
            s++;

        checked[x][y] = true;

        select(n - 1, i + 1, s, x, y);

        checked[x][y] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
            checked[i][j] = false;
        }
    }

    select(7, 0, 0, 0, 0);
    
    cout << result << '\n';
}