#include <bits/stdc++.h>
using namespace std;

vector<int> cnt;
int N, M, c = 1, temp[1000][1000], result[1000][1000];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[1000][1001];
bool visited[1000][1000];

void bfs(int si, int sj){
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));

    visited[si][sj] = true;
    int count = 1;

    temp[si][sj] = c;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= M)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] == '1')
                continue;
            count++;
            visited[nI][nJ] = true;
            temp[nI][nJ] = c;
            q.push(make_pair(nI, nJ));
        }
    }
    cnt.push_back(count);
    c++;
}

void search(int si, int sj){
    result[si][sj] = 1;
    map<int, int> m;
    for(int i = 0; i < 4; i++){
        int nI = si + dx[i];
        int nJ = sj + dy[i];
        if(arr[nI][nJ] == '0' && m.find(temp[nI][nJ]) == m.end()){
            result[si][sj] += cnt[temp[nI][nJ] - 1];
            m[temp[nI][nJ]] = 1;
        }
    }
    result[si][sj] %= 10;
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
            if(!visited[i][j] && arr[i][j] == '0')
                bfs(i, j);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == '1')
                search(i, j);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << result[i][j];
        }
        cout << '\n';
    }
}   