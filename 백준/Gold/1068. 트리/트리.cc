#include <bits/stdc++.h>
using namespace std;

int N, root, removedNode, result = 0;
vector<int> graph[50];

void bfs(){
    if(root == removedNode)
        return;

    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int size = graph[cur].size();
        int s = size;
        for(int i = 0; i < size; i++){
            int next = graph[cur][i];
            if(next == removedNode){
                s--;
                continue;
            }
            q.push(next);
        }

        if(s == 0)
            result++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int n;
    for(int i = 0; i < N; i++){
        cin >> n;
        if(n == -1){
            root = i;
            continue;
        }
        graph[n].push_back(i);
    }
    cin >> removedNode;

    bfs();

    cout << result << '\n';
}