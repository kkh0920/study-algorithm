#include <bits/stdc++.h>
using namespace std;

int graph[101] = { 0 };
bool visited[101] = { false };
int N, M, result = 0;

void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int curNum = q.front();
            q.pop();

            for(int j = 1; j <= 6; j++){
                int nextNum = curNum + j;
                if(visited[nextNum])
                    continue;
                if(graph[nextNum])
                    nextNum = graph[nextNum];
                if(nextNum == 100){
                    result++;
                    return;
                }
                visited[nextNum] = true;
                q.push(nextNum);
            }
        }
        result++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    int s, e;
    for(int i = 0; i < N + M; i++){
        cin >> s >> e;
        graph[s] = e;
    }

    bfs();

    cout << result << '\n';
}