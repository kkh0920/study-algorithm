#include <iostream>
using namespace std;

bool A[100001];
int N, Q, dp[100001];

int solve(int l) {
    if(dp[l] >= 0) return dp[l];
    if(l == 1) return dp[l] = A[1] ? 1 : 0;
    
    int result = A[l] ? 1 : 0;
    result += solve(1);
    for(int k = 2; k * k <= l; k++) {
        if(l % k == 0) {
            result += solve(k);
            if(k != l / k) result += solve(l / k);
        }
    }

    return dp[l] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    cin >> N;

    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        A[a] = true;
    }

    for(int i = 0; i <= 100000; i++) {
        dp[i] = -1;
    }

    cin >> Q;

    int l;
    for(int i = 0; i < Q; i++) {
        cin >> l;
        cout << solve(l) << '\n';
    }

    return 0;
}