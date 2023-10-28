#include <bits/stdc++.h>

#define MAXN 2001
#define INF 2000001

using namespace std;

// BOJ 9370
vector<int> result;
vector< pair<int ,int> > graph[MAXN], shortestDist;

int T; 
int n, m, t; 
int s, g, h;
int x;
int dist[MAXN];

// 다익스트라 알고리즘
void dijkstra(int start){
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, start));

    fill(dist, dist + (n + 1), INF);
    dist[start] = 0;

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        if(curWeight > dist[curNode])
            continue;

        int size = graph[curNode].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[curNode][i].second;
            int nextWeight = graph[curNode][i].first;
            if(dist[nextNode] > dist[curNode] + nextWeight){
                dist[nextNode] = dist[curNode] + nextWeight;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n >> m >> t; // 노드 개수, 간선 개수, 목적지 후보 개수.
        cin >> s >> g >> h; // 시작점, g와 h 사이를 지남.
        
        int a, b, d;
        for(int j = 0; j < m; j++){
            cin >> a >> b >> d;
            graph[a].push_back(make_pair(d, b));
            graph[b].push_back(make_pair(d, a));
        }

        dijkstra(s);
        // s -> goal (최단거리) 저장.
        for(int j = 0; j < t; j++){
            cin >> x;
            shortestDist.push_back(make_pair(x, dist[x]));
        }

        int sgh = dist[g]; // s -> g
        int shg = dist[h]; // s -> h

        dijkstra(g);
        sgh += dist[h]; // s -> g -> h
        
        dijkstra(h);
        // (s -> g -> h -> goal)과 (s -> goal)이 같으면(최단 거리이면), result에 push.
        for(int i = 0; i < shortestDist.size(); i++){
            int goal = shortestDist[i].first;
            int shortest = shortestDist[i].second;
            
            sgh += dist[goal];
            if(sgh == shortest)
                result.push_back(goal);
            sgh -= dist[goal];
        }

        shg += dist[g]; // s -> h -> g
        
        dijkstra(g);

        // (s -> h -> g -> goal)과 (s -> goal)이 같으면(최단 거리이면), result에 push.
        for(int i = 0; i < shortestDist.size(); i++){
            int goal = shortestDist[i].first;
            int shortest = shortestDist[i].second;
            
            shg += dist[goal];
            if(shg == shortest)
                result.push_back(goal);
            shg -= dist[goal];
        }
        
        // result 정렬 및 출력
        sort(result.begin(), result.end());
        for(auto x : result){
            cout << x << ' ';
        }
        cout << '\n';
        
        // 초기화
        result.clear();
        shortestDist.clear();
        for(int i = 1; i <= n; i++){
            graph[i].clear();
        }
    }
}