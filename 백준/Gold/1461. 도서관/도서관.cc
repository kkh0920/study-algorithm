#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, arr[50];

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int result = 0;
    for(int i = 0; i < N && arr[i] < 0; i += M){
        result += abs(arr[i]) * 2;
    }
    for(int i = N - 1; i >= 0 && arr[i] > 0; i -= M){
        result += abs(arr[i]) * 2;
    }
    result -= max(abs(arr[0]), abs(arr[N - 1]));

    cout << result << '\n';
}   
