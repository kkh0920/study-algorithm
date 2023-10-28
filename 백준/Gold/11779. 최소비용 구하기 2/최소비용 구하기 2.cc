#include <iostream>
#include <queue>
#include <vector>
#define INF 500000000
#define MAXN 1001

using namespace std;

vector< pair<int, int> > graph[MAXN];
int n, m, s, e, w, prevNode[MAXN] = { 0, }, dist[MAXN];

void dijkstra(){
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        if(curWeight > dist[curNode])
            continue;

        for(int i = 0; i < graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].first;
            int nextWeight = graph[curNode][i].second;
            if(dist[nextNode] > curWeight + nextWeight){
                dist[nextNode] = curWeight + nextWeight;
                prevNode[nextNode] = curNode;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
    }
    cin >> s >> e;

    fill_n(dist, n + 1, INF);

    dijkstra();

    vector<int> route;
    int temp = e;
    while(temp != s){
        route.push_back(temp);
        temp = prevNode[temp];
    }

    cout << dist[e] << '\n';
    cout << route.size() + 1<< '\n';
    cout << s <<  ' ';
    for(int i = route.size() - 1; i >= 0; i--){
        cout << route[i] << ' ';
    }
    cout << '\n';
}