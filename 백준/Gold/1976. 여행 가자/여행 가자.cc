#include <bits/stdc++.h>
using namespace std;

int N, M, graphInfo[201][201];
bool visited[201] = { false };

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next = 1; next <= N; next++){
            if(visited[next] || graphInfo[cur][next] == 0)
                continue;
            visited[next] = true;
            q.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> graphInfo[i][j];
        }
    }

    int n;
    cin >> n;
    bfs(n);

    for(int i = 0; i < M - 1; i++){
        cin >> n;
        if(!visited[n]){
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
}