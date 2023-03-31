#include <iostream>
#include <vector>
using namespace std;

vector< pair < int,  pair<int, int> > > graph;
int dist[501], tc, n, m, w, s, e, t;

//벨만 포드 알고리즘. (모든 간선을 탐색) * (N - 1). 

// 1.
//시작 지점이 있어도, 굳이 시작 지점 부터 queue를 이용해서 꼬리 물듯 찾아가지 않아도 됨.
//어차피 모든 간선을 탐색해야하니까.
//시작 지점만 0으로 초기화 해주고, 나머지는 충분히 큰 수로 초기화 해주면, 모든 간선을 탐색하면서 저절로 맞춰지게 됨. 

// 2.
//그런데? 최단 경로를 찾지 않고, 그냥 음의 사이클만 확인 한다고 치면,
//초기화 값은 적당한 수로 맞춰주고, 횟수만 1회 늘려서 N번 모든 간선을 탐색하면 됨.
//왜냐하면 음의 사이클을 통해 줄어드는 그 형태만 파악하면 되니까, 굳이 특정한 초기화 값을 생각해주지 않아도 된다.
//내가 푼 문제가 이와 같은 형태임.

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