#include <iostream>
using namespace std;

int main(){
    int n, m, cost[101][101];

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = 100000 * 100;
        }
    }

    int s, e, c;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> c;
        cost[s][e] = cost[s][e] > c ? c : cost[s][e];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] >= 100000 * 100)
                cost[i][j] = 0;
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}