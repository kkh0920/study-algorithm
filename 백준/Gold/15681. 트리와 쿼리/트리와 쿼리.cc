#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int N, R, Q, subTree[100001];
bool visited[100001];

int dfs(int cur){
    int size = graph[cur].size();
    int cnt = 1;
    for(int i = 0; i < size; i++){
        int next = graph[cur][i];
        if(visited[next])
            continue;
        visited[next] = true;
        cnt += dfs(next);
    }
    return subTree[cur] = cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;

    int n1, n2;
    for(int i = 0; i < N - 1; i++){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    visited[R] = true;
    dfs(R);
    
    int U;
    for(int i = 0; i < Q; i++){
        cin >> U;
        cout << subTree[U] << '\n';
    }
}