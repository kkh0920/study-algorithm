#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;

    cin >> s1 >> s2;

    int len1 = s1.length(), len2 = s2.length();
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(s1[i] == s2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[len1][len2] << '\n';
}