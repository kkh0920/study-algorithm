#include <iostream>
#include <algorithm>
using namespace std;

int N, M, root[1001];
vector< pair< int, pair<int, int> > > v;

int getRoot(int node) {
    if(root[node] == node)
        return node;
    return root[node] = getRoot(root[node]);
}

// Minimum Spanning Tree(Kruskal Algorithm)
int getMinCost() { 
    int index = 0, cnt = 0, result = 0;

    while(cnt < N - 1) {
        int cost = v[index].first;
        int node1 = v[index].second.first;
        int node2 = v[index].second.second;
        index++;

        int root1 = getRoot(node1);
        int root2 = getRoot(node2);

        if(root1 == root2)
            continue;
        
        root1 < root2 ? root[root2] = root1 : root[root1] = root2;
        cnt++;
        result += cost;
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        root[i] = i;
    }

    int s, e, c;
    for(int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        v.push_back(make_pair(c, make_pair(s, e)));
    }

    sort(v.begin(), v.end());

    cout << getMinCost() << '\n';

    return 0;
}