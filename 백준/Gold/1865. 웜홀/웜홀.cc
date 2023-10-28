#include <iostream>
#include <vector>
using namespace std;

vector< pair < int,  pair<int, int> > > graph;
int dist[501], tc, n, m, w, s, e, t;

bool bellmanFord(){
    int gSize = graph.size(), curNode, nextNode, nextWeight;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < gSize; j++){
            curNode = graph[j].first;
            nextNode = graph[j].second.first;
            nextWeight = graph[j].second.second;
            if(dist[nextNode] > dist[curNode] + nextWeight){
                if(i == n - 1)
                    return true;
                dist[nextNode] = dist[curNode] + nextWeight;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> tc;
    int c = 0;
    for(int i = 0; i  < tc; i++){
        cin >> n >> m >> w;

        graph.clear();
        fill_n(dist, n + 1, 0);

        for(int j = 0; j < m; j++){
            cin >> s >> e >> t;
            graph.push_back(make_pair(s, make_pair(e, t)));
            graph.push_back(make_pair(e, make_pair(s, t)));
        }

        for(int j = 0; j < w; j++){
            cin >> s >> e >> t;
            graph.push_back(make_pair(s, make_pair(e, -t)));
        }

        if(bellmanFord())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}