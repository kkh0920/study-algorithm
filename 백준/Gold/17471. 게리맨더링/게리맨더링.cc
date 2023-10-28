#include <bits/stdc++.h>
using namespace std;

vector<int> graph[11];
int N, people[11], result = 10000;
bool visited[11], checked[11] = { false };

void bfs(int s){
    queue<int> q;
    q.push(s);

    fill(visited, visited + (N + 1), false);
    visited[s] = true;
    
    // 선택된 노드 연결체크
    while(!q.empty()){
        int curNode = q.front();
        q.pop();

        int size = graph[curNode].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[curNode][i];
            if(visited[nextNode] || !checked[nextNode])
                continue;

            visited[nextNode] = true;
            q.push(nextNode);
        }
    }

    int res = 0;
    for(int i = 1; i <= N; i++){
        if(!visited[i] && checked[i])
            return;

        if(!visited[i]){
            if(q.empty())
                q.push(i);
        }
        else
            res += people[i];
    }

    visited[q.front()] = true;

    // 선택되지 않은 노드 연결체크
    while(!q.empty()){
        int curNode = q.front();
        q.pop();

        int size = graph[curNode].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[curNode][i];
            if(visited[nextNode] || checked[nextNode])
                continue;

            visited[nextNode] = true;
            q.push(nextNode);
        }
    }

    for(int i = 1; i <= N; i++){
        if(!visited[i])
            return;
        if(!checked[i])
            res -= people[i];
    }

    result = min(result, abs(res));
}

void select(int n, int idx){
    if(n == 0){
        bfs(idx - 1);
        return;
    }

    for(int i = idx; i <= N; i++){
        checked[i] = true;

        select(n - 1, i + 1);

        checked[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> people[i];
    }

    int n, node;
    for(int i = 1; i <= N; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> node;
            graph[i].push_back(node);
            graph[node].push_back(i);
        }
    }
    
    for(int i = 1; i <= N; i++){
        select(i, 1);
    }

    if(result == 10000)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}   
