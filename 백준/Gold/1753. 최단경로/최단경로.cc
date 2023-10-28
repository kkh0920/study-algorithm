#include <iostream>
#include <queue>
#include <vector>
#define MAXV 20001
using namespace std;

vector< pair<int, int> > graph[MAXV];
int weight[MAXV];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
int V, E, K, u, v, w;

void initWeight(){
    for(int i = 1; i <= V; i++){
        weight[i] = 200001;
    }
}

void search(){
    int tempW = 0;
    while(!q.empty()){
        tempW = weight[q.top().second];
        int size = graph[q.top().second].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[q.top().second][i].first;
            int weightNum = tempW + graph[q.top().second][i].second;  
            if(weightNum < weight[nextNode]){
                q.push(make_pair(weightNum, nextNode));
                weight[nextNode] = weightNum;
            }
        }
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E >> K;

    initWeight();

    q.push(make_pair(0, K));
    weight[K] = 0;

    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }


    search();

    for(int i = 1; i <= V; i++){
        if(weight[i] == 200001)
            cout << "INF" << '\n';
        else
            cout << weight[i] << '\n';
    }
}