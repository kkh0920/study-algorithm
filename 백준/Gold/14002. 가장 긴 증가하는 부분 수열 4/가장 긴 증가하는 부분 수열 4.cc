#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
int N, arr[1001], dp[1001], pre[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    int maxNum = 1, idx = 1;
    for(int i = 2; i <= N; i++){
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if(dp[i] > maxNum){
            maxNum = dp[i];
            idx = i;
        }
    }

    while(idx != 0){
        result.push_back(arr[idx]);
        idx = pre[idx];
    }

    cout << maxNum << '\n';
    for(int i = maxNum - 1; i >= 0; i--){
        cout << result[i] << ' ';
    }
    cout << '\n';
}