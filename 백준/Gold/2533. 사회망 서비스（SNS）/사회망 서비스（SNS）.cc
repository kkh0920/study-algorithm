#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[1000001];
int n, result = 0;
bool visited[1000001], earlyAdopter[1000001];

bool isEarlyAdopter(int node) {
    int child = 0, early = 0;
    for(auto nextNode : tree[node]) {
        if(!visited[nextNode]) {
            visited[nextNode] = true;
            child++;
            early += isEarlyAdopter(nextNode);
        }
    }
    if(child > early) {
        result++;
        return earlyAdopter[node] = true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int n1, n2;
    for(int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    visited[1] = true;
    isEarlyAdopter(1);
    
    cout << result << '\n';

    return 0;
}