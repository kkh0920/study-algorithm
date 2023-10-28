#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > graph[100001];
bool visited[100001] = { false };
int v, result = 0;

bool compare(int a, int b){
    return a > b;
}

int dfs(int start){
    vector<int> temp;
    int size = graph[start].size();
    for(int i = 0; i < size; i++){
        int nextNode = graph[start][i].first;
        int nextWeight = graph[start][i].second;
        
        if(visited[nextNode])
            continue;

        if(graph[nextNode].empty()){
            temp.push_back(nextWeight);
            continue;
        }

        visited[nextNode] = true;
        temp.push_back(nextWeight + dfs(nextNode));
    }

    sort(temp.begin(), temp.end(), compare);

    if(temp.empty())
        return 0;

    if(temp.size() == 1)
        result = max(result, temp[0]);
        
    if(temp.size() >= 2)
        result = max(result, temp[0] + temp[1]);
    
    return temp[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v;

    int s, e, w;
    for(int i = 0; i < v; i++){
        cin >> s;
        while(1){
            cin >> e;
            if(e == -1)
                break;
            cin >> w;
            graph[s].push_back(make_pair(e, w));
                   
        }
    }

    visited[1] = true;
    dfs(1);

    cout << result << '\n';
}