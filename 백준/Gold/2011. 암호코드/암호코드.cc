#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int dp[2][5000];

    cin >> str;

    if(str[0] == '0'){
        cout << 0 << '\n';
        return 0;
    }

    dp[0][0] = 1;
    dp[1][0] = 0;
    
    int len =  str.length();
    for(int i = 1; i < len; i++){
        if(str[i] == '0')
            dp[0][i] = 0;
        else
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % 1000000;

        if((str[i - 1] == '0' || str[i - 1] >= '3') || (str[i - 1] == '2' && str[i] >= '7'))
            dp[1][i] = 0;
        else
            dp[1][i] = dp[0][i - 1];
    }

    cout << (dp[1][len - 1] + dp[0][len - 1]) % 1000000 << '\n';
}