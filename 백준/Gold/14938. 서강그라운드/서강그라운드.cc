#include <bits/stdc++.h>
using namespace std;

int cost[101][101];
int n, m, r, a, b, l, item[101];

void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = 1000000;
        }
    }
}

void floydWarshall(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;

    init();

    for(int i = 1; i <= n; i++){
        cin >> item[i];
    }

    for(int i = 1; i <= r; i++){
        cin >> a >> b >> l;
        cost[a][b] = l;
        cost[b][a] = l;
    }

    floydWarshall();
    
    int result = 0;
    for(int i = 1; i <= n; i++){
        int temp = 0;
        for(int j = 1; j <= n; j++){
            if(cost[i][j] <= m)
                temp += item[j];
        }
        result = max(result, temp);
    }

    cout << result << '\n';
}