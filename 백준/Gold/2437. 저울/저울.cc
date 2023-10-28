#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, arr[1000];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int num = arr[0];

    if(num > 1){
        cout << 1 << '\n';
        return 0;
    }

    for(int i = 1; i < N; i++){
        if(arr[i] > num + 1){
            break;
        }
        num += arr[i];
    }

    cout << num + 1 << '\n';
}