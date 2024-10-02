#include <iostream>
#include <vector>
using namespace std;

#define INF 999999

int C, N, dp[1001][20];
vector< pair<int, int> > items;

int getMinCost(int customer, int index) {
    if(index >= N) return INF;
    if(customer <= 0) return 0;

    if(dp[customer][index] != -1) return dp[customer][index];

    int result = INF;
    for(int i = index; i < N; i++) {
        int cost = items[i].first;
        int value = items[i].second;
        result = min(result, cost + getMinCost(customer - value, i));
    }

    return dp[customer][index] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C >> N;

    int cost, value;
    for(int i = 0; i < N; i++) {
        cin >> cost >> value;
        items.push_back({cost, value});
    }

    for(int i = 0; i <= C; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    cout << getMinCost(C, 0) << '\n';

    return 0;
}