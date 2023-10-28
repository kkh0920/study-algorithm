#include <iostream>
using namespace std;

int N, M, dp[10001], memory[100], cost[100], cost_sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> memory[i];
    }

    for(int i = 0; i < N; i++){
        cin >> cost[i];
        cost_sum += cost[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = cost_sum; j >= cost[i]; j--){
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    for(int i = 0; i <= cost_sum; i++){
        if(dp[i] >= M){
            cout << i << '\n';
            break;
        }
    }
}