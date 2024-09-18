#include <iostream>
using namespace std;

int N, cost[16][16], minCost[16][16][1 << 16];
int visited = 0, start;

int travel(int node) {
    if(visited == (1 << N) - 1) {
        return cost[node][start] == 0 ? 1000000000 : cost[node][start];
    }
    if(minCost[start][node][visited] != 0) {
        return minCost[start][node][visited];
    }
    
    int c = 1000000000;
    for(int i = 0; i < N; i++) {
        if(cost[node][i] == 0 || visited & (1 << i)) continue;
        visited += (1 << i);
        c = min(c, cost[node][i] + travel(i));
        visited -= (1 << i);
    }

    return minCost[start][node][visited] = c;
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

    int result = 1000000000;
    for(int i = 0; i < N; i++) {
        start = i;
        visited = 1 << i;
        result = min(result, travel(i));
    }

    cout << result << '\n';

    return 0;
}