#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int N, S, D, result = 0;

int dfs(int cur, int prev){
    int size = graph[cur].size();
    int maxDepth = 0;
    for(int i = 0; i < size; i++){
        int next = graph[cur][i];
        if(next == prev)
            continue;
        maxDepth = max(maxDepth, dfs(next, cur) + 1);
    }
    if(cur != S && maxDepth >= D)
        result++;
    
    return maxDepth;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S >> D;

    int n1, n2;
    for(int i = 0; i < N - 1; i++){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    dfs(S, 0);

    cout << result * 2 << '\n';
}