#include <iostream>
using namespace std;

int dp[1001][1001], arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string str1, str2;

    cin >> str1 >> str2;

    int len1 = str1.length(), len2 = str2.length();
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(str1[i] == str2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
                arr[i + 1][j + 1] = 1;
            }
            else if(dp[i][j + 1] > dp[i + 1][j]){
                dp[i + 1][j + 1] = dp[i][j + 1];
                arr[i + 1][j + 1] = 2;
            }
            else{
                dp[i + 1][j + 1] = dp[i + 1][j];
                arr[i + 1][j + 1] = 3;
            }
        }
    }

    string result = "";
    int si = len1, sj = len2;
    while(si != 0 && sj != 0){
        if(arr[si][sj] == 1){
            result.insert(0, 1, str1[si - 1]);
            si--;
            sj--; 
        }
        else if(arr[si][sj] == 2){
            si--;
        }
        else{
            sj--;
        }
    }

    cout << dp[len1][len2] << '\n';
	cout << result << '\n';
}