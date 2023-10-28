#include <iostream>
using namespace std;

int N, dp[500][500];
pair<int, int> arr[500];

int getMin(int start, int end){
    for(int i = start; i < end; i++){
        if(dp[start][i] == INT32_MAX)
            dp[start][i] = getMin(start, i);
        if(dp[i + 1][end] == INT32_MAX)
            dp[i + 1][end] = getMin(i + 1, end);

        int currentCal = arr[start].first * arr[i].second * arr[end].second;

        dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + currentCal);
    }
    return dp[start][end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT32_MAX;
        }
    }

    cout << getMin(0, N - 1) << '\n';
}