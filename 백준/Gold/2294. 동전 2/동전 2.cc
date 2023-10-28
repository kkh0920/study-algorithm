#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, arr[101], dp[10001] = { 0, };

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= k; i++){
        dp[i] = 10001;
    }

    for(int i = 1; i <= n; i++){
        for(int j = arr[i]; j <= k; j++){
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
    
    if(dp[k] == 10001)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';
}