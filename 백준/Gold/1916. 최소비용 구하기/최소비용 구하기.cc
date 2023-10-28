#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

vector< pair<int, int> > graph[1001];
int n, m, s, e, l, dist[1001];

void initDist(){
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }
}

void dijkstra(){
    initDist();
    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = -pq.top().first;
        pq.pop();

        if(curWeight > dist[curNode])
            continue;

        int size = graph[curNode].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[curNode][i].second;
            int nextWeight = graph[curNode][i].first;
            if(dist[nextNode] > dist[curNode] + nextWeight){
                dist[nextNode] = dist[curNode] + nextWeight;
                pq.push(make_pair(-dist[nextNode], nextNode));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> l;
        graph[s].push_back(make_pair(l, e));
    }
    cin >> s >> e;

    dijkstra();

    cout << dist[e] << '\n';
}