#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001], result;
int N, M, n, s, e, cnt[1001] = { 0 }, node;

void topologicalSort(){
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(cnt[i] == 0)
            q.push(i);
    }
    for(int i = 0; i < N; i++){
        if(q.empty()){
            cout << 0 << '\n';
            return;
        }
        int num = q.front();
        q.pop();
        result.push_back(num);

        int size = graph[num].size();
        for(int j = 0; j < size; j++){
            if(--cnt[graph[num][j]] == 0){
                q.push(graph[num][j]);
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << result[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    queue<int> temp;
    for(int i = 0; i < M; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> node;
            temp.push(node);
            if(temp.size() == 2){
                int s = temp.front();
                temp.pop();
                int e = temp.front();
                graph[s].push_back(e);
                cnt[e]++;
            }
        }
        if(n != 0)
            temp.pop();
    }
    topologicalSort();
}