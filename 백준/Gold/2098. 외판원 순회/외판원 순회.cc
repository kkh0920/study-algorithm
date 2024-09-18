#include <iostream>
using namespace std;

int N, cost[16][16], minCost[16][1 << 16];
int visited = 0;

int travel(int node) {
    if(minCost[node][visited] != 0) {
        return minCost[node][visited];
    }
    if(visited == (1 << N) - 1) {
        return cost[node][0] == 0 ? 1000000000 : cost[node][0];
    }
  
    int c = 1000000000;
    for(int i = 0; i < N; i++) {
        if(cost[node][i] == 0 || visited & (1 << i)) continue;
        visited += (1 << i);
        c = min(c, cost[node][i] + travel(i));
        visited -= (1 << i);
    }

    return minCost[node][visited] = c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    visited = 1;
    cout << travel(0) << '\n';

    return 0;
}