#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, parent[101];
pair<double, double> point[101];
vector< pair<double, pair<int, int> > > v;

int getRoot(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = getRoot(parent[node]);
}

double kruskal() {
    int cnt = 0;
    double sum = 0;
    for(int i = 0; cnt < n - 1 && i < v.size(); i++) {
        double dist = v[i].first;
        int node1 = v[i].second.first;
        int node2 = v[i].second.second;

        int root1 = getRoot(node1);
        int root2 = getRoot(node2);

        if(root1 == root2)
            continue;

        if(node1 < node2)
            parent[root2] = root1;
        else
            parent[root1] = root2;
        
        sum += dist;
        cnt++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> point[i].first >> point[i].second;
        parent[i] = i;
    }

    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            double x1 = point[i].first;
            double y1 = point[i].second;

            double x2 = point[j].first;
            double y2 = point[j].second;

            double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

            v.push_back(make_pair(distance, make_pair(i, j)));
        }
    }

    sort(v.begin(), v.end());

    cout << kruskal() << '\n';

    return 0;
}