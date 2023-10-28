#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
int t, n, nextNode, arr[100001], result = 0;

void dfs(int i){
    stack<int> s;
    queue<int> q;
    s.push(i);
    visited[i] = true;
    bool isCycle = false;
    while(!s.empty()){
        int cur = s.top();
        q.push(cur);
        if(visited[arr[cur]]){
            while(!q.empty()){
                if(q.front() != arr[cur]){
                    result++;
                    q.pop();
                    continue;
                }
                return;
            }
            return;
        }
        visited[arr[cur]] = true;
        s.push(arr[cur]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> nextNode;
            arr[j] = nextNode;
        }
        result = 0;
        fill_n(visited, n + 1, false);
        for(int i = 1; i <= n; i++){
            if(!visited[i])
                dfs(i);
        }
        cout << result << '\n';
    }
}