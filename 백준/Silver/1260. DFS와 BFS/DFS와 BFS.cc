#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001] = { false };
int N, M, V, s, e;

void dfs(){
    stack<int> st;
    cout << V << ' ';
    st.push(V);
    visited[V] = true;
    while(!st.empty()){
        int i, size = graph[st.top()].size();
        for(i = 0; i < size; i++){
            if(!visited[graph[st.top()][i]]){
                cout << graph[st.top()][i] << ' ';
                visited[graph[st.top()][i]] = true;
                st.push(graph[st.top()][i]);
                break;
            }
        }
        if(i == size)
            st.pop();
    }
    cout << '\n';
}

void bfs(){
    queue<int> q;
    q.push(V);
    visited[V] = true;
    cout << V << ' ';
    while(!q.empty()){
        int size = graph[q.front()].size();
        for(int i = 0; i < size; i++){
            if(!visited[graph[q.front()][i]]){
                q.push(graph[q.front()][i]);
                visited[graph[q.front()][i]] = true;
                cout << graph[q.front()][i] << ' ';
            }
        }
        q.pop();
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for(int i = 1; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs();
    fill_n(visited, N + 1, false);
    bfs();
}