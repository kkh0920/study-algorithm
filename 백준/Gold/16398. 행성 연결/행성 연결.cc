#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, parent[1000];
vector< pair<int, pair<int, int> > > edges;

int getRoot(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = getRoot(parent[x]);
}

long long kruskal() {
    long long result = 0;
    
    int count = 0;
    int size = (int) edges.size();
    for(int i = 0; i < size && count < N - 1; i++) {
        int root1 = getRoot(edges[i].second.first);
        int root2 = getRoot(edges[i].second.second);

        if(root1 == root2) {
            continue;
        }

        if(root1 < root2) {
            parent[root2] = root1;
        } else {
            parent[root1] = root2;
        }

        result += edges[i].first;
        count++;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int cost;
    for(int i = 0; i < N; i++) {
        parent[i] = i;
        for(int j = 0; j < N; j++) {
            cin >> cost;
            if(i < j) {
                edges.push_back({cost, {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    cout << kruskal() << '\n';

    return 0;
}