#include <bits/stdc++.h>
using namespace std;

int n, arr[500][500], dp[500][500], result = 0;
bool visited[500][500];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

int dfs(int curI, int curJ){
    visited[curI][curJ] = true;
    for(int i = 0; i < 4; i++){
        int nI = curI + dx[i];
        int nJ = curJ + dy[i];
        if(nI < 0 || nI >= n || nJ < 0 || nJ >= n)
            continue;  
        if(arr[nI][nJ] <= arr[curI][curJ])
            continue;
        if(visited[nI][nJ]){
            if(dp[nI][nJ] >= dp[curI][curJ])
                dp[curI][curJ] = dp[nI][nJ] + 1;
            continue;
        }
        
        dfs(nI, nJ);
        
        if(dp[curI][curJ] <= dp[nI][nJ])
            dp[curI][curJ] = dp[nI][nJ] + 1;
    }

    return dp[curI][curJ];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            dp[i][j] = 1;
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j])
                result = max(result, dfs(i, j));
        }
    }

    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << result << '\n';
}