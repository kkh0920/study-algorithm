#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > road[10001];
bool visited[10001];
int n = 1;

int dfs(int node) {
    int maxDist = 0;
    for(auto next : road[node]) {
        int nextNode = next.first;
        int distance = next.second;
        if(!visited[nextNode]) {
            visited[nextNode] = true;
            maxDist = max(maxDist, distance + dfs(nextNode));
            visited[nextNode] = false;
        }
    }
    return maxDist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, d;
    while(1) {
        cin >> n1 >> n2 >> d;
        if(cin.eof()) break;
        road[n1].push_back(make_pair(n2, d));
        road[n2].push_back(make_pair(n1, d));
        n++;
    }

    int result = 0;
    for(int i = 1; i < n; i++) {
        visited[i] = true;
        result = max(result, dfs(i));
        visited[i] = false;
    }

    cout << result << '\n';

    return 0;
}