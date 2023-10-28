#include <bits/stdc++.h>
using namespace std;

vector<int> res;
int N, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[25][26];
bool visited[25][25];

void bfs(int si, int sj){
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));

    visited[si][sj] = true;

    int count = 1;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] == '0')
                continue;
            count++;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
    res.push_back(count);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == '1' && !visited[i][j]){
                bfs(i, j);
                result++;
            }
        }
    }

    sort(res.begin(), res.end());

    cout << result << '\n';
    for(auto x : res){
        cout << x << '\n';
    }
}   
