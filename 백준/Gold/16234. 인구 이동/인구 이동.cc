#include <bits/stdc++.h>
using namespace std;

int N, L, R, cnt;
int arr[50][50], visited[50][50];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int people[2501];

void init(){
    cnt = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = 0;
        }
    }
}

bool bfs(int si, int sj){
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));

    visited[si][sj] = cnt;

    int sum = arr[si][sj], count = 1;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N)
                continue;
            if(visited[nI][nJ])
                continue;
            
            int p = abs(arr[curI][curJ] - arr[nI][nJ]);

            if(p < L || p > R)
                continue;

            sum += arr[nI][nJ];
            count++;
            visited[nI][nJ] = cnt;
            q.push(make_pair(nI, nJ));
        }
    }
    
    people[cnt++] = sum / count;

    if(count == 1)
        return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;
    while(1){
        init();
        bool isChanged = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && bfs(i, j))
                    isChanged = true;
            }
        }

        if(!isChanged)
            break;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                arr[i][j] = people[visited[i][j]];
            }
        }

        result++;
    }

    cout << result << '\n';
}