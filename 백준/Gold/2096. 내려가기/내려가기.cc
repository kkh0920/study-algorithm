#include <iostream>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, num, maxDP[3] = { 0, 0, 0 }, minDP[3] = { 0, 0, 0 };
    int temp[3], tempMax[3], tempMin[3], resultMax, resultMin;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp[0] >> temp[1] >> temp[2];

        tempMax[0] = max(maxDP[0], maxDP[1]) + temp[0];
        tempMin[0] = min(minDP[0], minDP[1]) + temp[0];
    
        tempMax[1] = max(max(maxDP[0], maxDP[1]), maxDP[2]) + temp[1];
        tempMin[1] = min(min(minDP[0], minDP[1]), minDP[2]) + temp[1];

        tempMax[2] = max(maxDP[1], maxDP[2]) + temp[2];
        tempMin[2] = min(minDP[1], minDP[2]) + temp[2];

        for(int j = 0; j < 3; j++){
            maxDP[j] = tempMax[j];
            minDP[j] = tempMin[j];
        }
    }

    resultMax = maxDP[0];
    resultMin = minDP[0];
    for(int i = 1; i < 3; i++){
        if(resultMax < maxDP[i])
            resultMax = maxDP[i];
        if(resultMin > minDP[i])
            resultMin = minDP[i];
    }
    
    cout << resultMax << ' ' << resultMin << '\n';
}