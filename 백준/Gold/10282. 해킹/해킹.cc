#include <bits/stdc++.h>
using namespace std;

int t = 0, cnt = 1;
int n, d, c, a, b, s;
int dist[10001];
bool visited[10001];

void dijkstra(vector< pair<int, int> > graph[], int c){
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
    q.push(make_pair(0, c));

    fill(visited, visited + (n + 1), false);
    visited[c] = true;

    fill(dist, dist + (n + 1), 100000000);
    dist[c] = 0;

    t = 0;
    cnt = 1;
    while(!q.empty()){
        int curNode = q.top().second;
        int curCost = q.top().first;
        q.pop();

        if(curCost > dist[curNode])
            continue;

        int size = graph[curNode].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[curNode][i].first;
            int nextCost = graph[curNode][i].second;
            if(dist[nextNode] > curCost + nextCost){
                if(!visited[nextNode])
                    cnt++;
                visited[nextNode] = true;
                dist[nextNode] = curCost + nextCost;
                q.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for(int i = 0; i < T; i++){
        vector< pair<int, int> > graph[10001];

        cin >> n >> d >> c;

        for(int j = 0; j < d; j++){
            cin >> a >> b >> s;
            graph[b].push_back(make_pair(a, s));
        }

        dijkstra(graph, c);

        int maxDist = 0;
        for(int j = 1; j <= n; j++){
            if(dist[j] != 100000000)
                maxDist = max(maxDist, dist[j]);
        }

        cout << cnt << ' ' << maxDist << '\n';
    }
}