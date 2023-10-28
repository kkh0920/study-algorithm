#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, arr[50];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> S;

    for(int i = 0; i < N && S > 0; i++){
        int max = 0;
        int max_idx;
        for(int j = i; j < N && j <= i + S; j++){
            if(arr[j] > max){
                max = arr[j];
                max_idx = j;
            }
        }
        S -= max_idx - i;
        for(int j = max_idx; j > i; j--){
            arr[j] = arr[j - 1];
        }
        arr[i] = max;
    }

    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}