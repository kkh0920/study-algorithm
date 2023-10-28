#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> arr[100];
    int N, dp[100] = { 1, };

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + N);

    int res = 1;
    for(int i = 1; i < N; i++){
        int num = 0;
        for(int j = 0; j <= i - 1; j++){
            if(arr[j].second < arr[i].second)
                num = max(num, dp[j]);
        }
        dp[i] = num + 1;
        res = max(res, dp[i]);
    }
    
    cout << N - res << '\n';
}