#include <iostream>
using namespace std;

#define INF 10000001

int n, cost[1000][3], s;
int dp[3][1000][3];

int select(int num, int color) {
    if(num == n) return 0;
    if(dp[s][num][color] < INF) return dp[s][num][color];

    for(int i = 0; i < 3; i++) {
        if(i != color) {
            if(num == n - 1 && color == s)
                continue; 
            dp[s][num][color] = min(dp[s][num][color], cost[num][color] + select(num + 1, i));
        }
    }

    return dp[s][num][color];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        for(int j = 0; j < 3; j++) {
            dp[0][i][j] = INF; dp[1][i][j] = INF; dp[2][i][j] = INF;
        }
    }
    
    int result = INF;
    for(int i = 0; i < 3; i++) {
        s = i;
        result = min(result, select(0, i));
    }
    cout << result << '\n';

    return 0;
}