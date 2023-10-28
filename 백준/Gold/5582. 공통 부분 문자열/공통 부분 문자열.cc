#include <iostream>
using namespace std;

int dp[4001][4001], result = 0;
string str1, str2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str1 >> str2;

    int len1 = str1.length(), len2 = str2.length();
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
        }
    }

    cout << result << '\n';
}
