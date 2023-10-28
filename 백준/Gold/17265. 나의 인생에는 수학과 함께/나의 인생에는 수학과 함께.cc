#include <iostream>
using namespace std;

int N, dp_max[5][5], dp_min[5][5];
char arr[5][6];

pair<int, int> getMaxMinNumber(int i, int j){
    if(dp_max[i][j] != -10000 || dp_min[i][j] != 10000)
        return make_pair(dp_max[i][j], dp_min[i][j]);

    if(i >= 2){
        dp_max[i - 2][j] = getMaxMinNumber(i - 2, j).first;
        dp_min[i - 2][j] = getMaxMinNumber(i - 2, j).second;
    }
    if(j >= 2){
        dp_max[i][j - 2] = getMaxMinNumber(i, j - 2).first;
        dp_min[i][j - 2] = getMaxMinNumber(i, j - 2).second;
    }
    if(i >= 1 && j >= 1){
        dp_max[i - 1][j - 1] = getMaxMinNumber(i - 1, j - 1).first;
        dp_min[i - 1][j - 1] = getMaxMinNumber(i - 1, j - 1).second;
    }

    int curNum = arr[i][j] - '0';

    int prev1_max = -10000, prev2_max = -10000, prev3_max = -10000;
    int prev1_min = 10000, prev2_min = 10000, prev3_min = 10000;

    if(i >= 1){
        switch(arr[i - 1][j]){
            case '+':
                if(i >= 2){
                    prev1_max = dp_max[i - 2][j] + curNum;
                    prev1_min = dp_min[i - 2][j] + curNum;
                }
                if(i >= 1 && j >= 1){
                    prev2_max = dp_max[i - 1][j - 1] + curNum;
                    prev2_min = dp_min[i - 1][j - 1] + curNum;
                }
                break;
            case '-':
                if(i >= 2){
                    prev1_max = dp_max[i - 2][j] - curNum;
                    prev1_min = dp_min[i - 2][j] - curNum;
                }
                if(i >= 1 && j >= 1){
                    prev2_max = dp_max[i - 1][j - 1] - curNum;
                    prev2_min = dp_min[i - 1][j - 1] - curNum;
                }
                break;
            case '*':
                if(i >= 2){
                    prev1_max = dp_max[i - 2][j] * curNum;
                    prev1_min = dp_min[i - 2][j] * curNum;
                }
                if(i >= 1 && j >= 1){
                    prev2_max = dp_max[i - 1][j - 1] * curNum;
                    prev2_min = dp_min[i - 1][j - 1] * curNum;
                }
                break;
        }
    }

    if(j >= 1){
        switch(arr[i][j - 1]){
            case '+':
                if(i >= 1 && j >= 1){
                    prev2_max = max(prev2_max, dp_max[i - 1][j - 1] + curNum);
                    prev2_min = min(prev2_min, dp_min[i - 1][j - 1] + curNum);
                }
                if(j >= 2){
                    prev3_max = dp_max[i][j - 2] + curNum;
                    prev3_min = dp_min[i][j - 2] + curNum;
                }
                break;
            case '-':
                if(i >= 1 && j >= 1){
                    prev2_max = max(prev2_max, dp_max[i - 1][j - 1] - curNum);
                    prev2_min = min(prev2_min, dp_min[i - 1][j - 1] - curNum);
                }
                if(j >= 2){
                    prev3_max = dp_max[i][j - 2] - curNum;
                    prev3_min = dp_min[i][j - 2] - curNum;
                }
                break;
            case '*':
                if(i >= 1 && j >= 1){
                    prev2_max = max(prev2_max, dp_max[i - 1][j - 1] * curNum);
                    prev2_min = min(prev2_min, dp_min[i - 1][j - 1] * curNum);
                }
                if(j >= 2){
                    prev3_max = dp_max[i][j - 2] * curNum;
                    prev3_min = dp_min[i][j - 2] * curNum;
                }
                break;
        }
    }

    // cout << '\n';
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << dp_max[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return make_pair(dp_max[i][j] = max(prev1_max, max(prev2_max, prev3_max)),
                        dp_min[i][j] = min(prev1_min, min(prev2_min, prev3_min)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            dp_max[i][j] = -10000;
            dp_min[i][j] = 10000;
        }
    }
    dp_max[0][0] = arr[0][0] - '0';
    dp_min[0][0] = arr[0][0] - '0';

    pair<int, int> result = getMaxMinNumber(N - 1, N - 1);

    cout << result.first << ' ' << result.second << '\n';
}