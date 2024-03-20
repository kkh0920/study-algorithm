#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector< pair< int, pair<int, int> > > road;
int n, m, sum = 0, parent[100001], largestCost;

int getRoot(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = getRoot(parent[node]);
}

void kruskal() {
    int cnt = 0;
    for(int i = 0; i < m && cnt < n - 1; i++) {
        int cost = road[i].first;
        int node1 = road[i].second.first;
        int node2 = road[i].second.second;
        
        int root1 = getRoot(node1);
        int root2 = getRoot(node2);
        if(root1 == root2)
            continue;
        
        if(node1 > node2)
            parent[root1] = root2;
        else
            parent[root2] = root1;
        
        sum += cost;
        largestCost = cost;
        cnt++;
    }
    sum -= largestCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        road.push_back(make_pair(c, make_pair(a, b)));
    }

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    sort(road.begin(), road.end());

    kruskal();

    cout << sum << '\n';

    return 0;
}