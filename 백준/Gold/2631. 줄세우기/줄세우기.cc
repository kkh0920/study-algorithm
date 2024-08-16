#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, arr[200], dp[200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int maxLen = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    cout << n - maxLen << '\n';

    return 0;
}