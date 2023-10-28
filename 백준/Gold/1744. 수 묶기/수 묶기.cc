#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[50], result = 0;
    bool isNotExist[50] = { false };

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N, compare);

    for(int i = 0; i < N - 1; i += 2){
        if(arr[i] <= 1 || arr[i + 1] <= 1)
            break;

        result += arr[i] * arr[i + 1];
        
        isNotExist[i] = true;
        isNotExist[i + 1] = true;
    }

    for(int i = N - 1; i > 0; i -= 2){
        if(arr[i] > 0 || arr[i - 1] > 0)
            break;
            
        result += arr[i] * arr[i - 1];

        isNotExist[i] =  true;
        isNotExist[i - 1] =  true;
    }

    for(int i = 0; i < N; i++){
        if(!isNotExist[i])
            result += arr[i];
    }

    cout << result << '\n';
}
