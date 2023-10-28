#include <bits/stdc++.h>
using namespace std;

vector<int> graph[3001];
int n, visited[3001] = { 0 }, result = 0;
bool isCycle[3001] = { false }, visited2[3001];

bool dfs(int cur, int cnt){
    int size = graph[cur].size();
    bool cycle = false;
    for(int i = 0; i < size; i++){
        int next = graph[cur][i];
        if(visited[next]){
            if(visited[cur] - visited[next] >= 2){
                isCycle[cur] = true;
                isCycle[next] = true;
                cycle =  true;
            }
            continue;
        }
        visited[next] = cnt + 1;
        if(dfs(next, cnt + 1) && !isCycle[cur]){
            isCycle[cur] = true;
            cycle = true;
        }
    }
    return cycle;
}

void bfs(int cur){
    for(int i = 1; i <= n; i++){
        visited2[i] = false;
    }
    queue<int> q;
    q.push(cur);
    visited2[cur] = true;
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int curNode = q.front();
            q.pop();

            if(isCycle[curNode]){
                result = time;
                return;
            }

            int gSize = graph[curNode].size();
            for(int j = 0; j < gSize; j++){
                int nextNode = graph[curNode][j];
                if(visited2[nextNode])
                    continue;
                visited2[nextNode] = true;
                q.push(nextNode);
            }
        }
        time++;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int s, e;
    for(int i = 0; i < n; i++){
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    visited[1] = 1;
    dfs(1, 1);

    for(int i = 1; i <= n; i++){
        bfs(i);
        cout << result << ' ';
    }
    cout << '\n';
}