#include <bits/stdc++.h>
using namespace std;

//BOJ 1967
vector< pair<int, int> > graph[10001];
int n, result = 0;

bool compare(int a, int b){
    return a > b;
}

int dfs(int cur){
    vector<int> temp;
    int maxWeight = 0;
    int size = graph[cur].size();
    for(int i = 0; i < size; i++){
        int nextNode = graph[cur][i].first;
        int nextWeight = graph[cur][i].second;

        if(graph[nextNode].empty()){
            temp.push_back(nextWeight);
            continue;
        }

        temp.push_back(dfs(nextNode) + nextWeight);
    }
    
    sort(temp.begin(), temp.end(), compare);
  
    int diameter = 0;

    if(temp.empty())
        return 0;

    diameter += temp[0];
    if(temp.size() >= 2)
        diameter += temp[1];

    result = max(result, diameter);

    return temp[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int s, e, w;
    for(int i = 0; i < n - 1; i++){
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
    }

    dfs(1);

    cout << result << '\n';
}