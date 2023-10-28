#include <bits/stdc++.h>
using namespace std;

int dp[10001] = { 1, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, arr[100];

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= k; j++){
            dp[j] += dp[j - arr[i]];
        }
    }

    cout << dp[k] << '\n';
}