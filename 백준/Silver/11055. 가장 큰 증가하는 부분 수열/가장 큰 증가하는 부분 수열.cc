#include <iostream>
using namespace std;

int n, arr[1000], dp[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int result = dp[0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result << '\n';

    return 0;
}