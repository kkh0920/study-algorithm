#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101] = { false };
int N, M, s, e, result = 0;

void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int size = graph[q.front()].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[q.front()][i];
            if(!visited[nextNode]){
                q.push(nextNode);
                visited[nextNode] = true;
                result++;
            }
        }
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    bfs();

    cout << result << '\n';
}
