#include <iostream>
using namespace std;

char arr[1001][1001];
int N, M, dp[1001][1001], result = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N >> M;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> arr[i][j];
			if(arr[i][j] == '1'){
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				result = max(result, dp[i][j] * dp[i][j]);
			}
		}
	}

	cout << result << '\n';
}