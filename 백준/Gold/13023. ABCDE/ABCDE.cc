#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2000];
int N, M;
bool visited[2000] = { false };

bool dfs(int cur, int cnt){
    if(cnt == 4)
        return true;

    int size = graph[cur].size();
    for(int i = 0; i < size; i++){
        int next = graph[cur][i];

        if(visited[next])
            continue;
        
        visited[next] = true;

        if(dfs(next, cnt + 1))
            return true;
        
        visited[next] = false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        visited[i] = true;
        if(dfs(i, 0)){
            cout << 1 << '\n';
            return 0;
        }
        visited[i] = false;
    }

    cout << 0 << '\n';
}   
