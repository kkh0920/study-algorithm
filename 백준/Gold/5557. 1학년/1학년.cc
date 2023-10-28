#include <iostream>
using namespace std;

long long dp[100][21];
int N, arr[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    dp[0][arr[0]]++;

    for(int i = 1; i < N - 1; i++){
        for(int j = 0; j <= 20; j++){
            if(j + arr[i] <= 20)
                dp[i][j + arr[i]] += dp[i - 1][j];
            if(j - arr[i] >= 0)
                dp[i][j - arr[i]] += dp[i - 1][j];
        }
    }

    cout << dp[N - 2][arr[N - 1]] << '\n';
}