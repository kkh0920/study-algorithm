#include <bits/stdc++.h>
using namespace std;

int k, arr[500], sum[500], dp[500][500], result;

int split(int s, int e){
    if(s == e)
        return arr[s];
    if(dp[s][e] != -1)
        return dp[s][e];
    
    int hap = sum[e];
    if(s > 0)
        hap -= sum[s - 1];

    int tmp = 987654321;
    for(int i = s; i < e; i++){
        tmp = min(tmp, split(s, i) + split(i + 1, e) + hap);
    }

    dp[s][e] = tmp;

    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> k;

        result = 987654321;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                dp[i][j] = -1;
            }
        }
        
        cin >> arr[0];
        sum[0] = arr[0];
        for(int j = 1; j < k; j++){
            cin >> arr[j];
            sum[j] = arr[j] + sum[j - 1];
        }

        for(int j = 0; j < k - 1; j++){
            result = min(result, split(0, j) + split(j + 1, k - 1));
        }

        cout << result << '\n';
    }
}