#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout.precision(3);

    int t, n, arr[1000];

    cin >> t;

    for(int i = 0; i < t; i++){
        float sum = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> arr[j];
            sum += arr[j];
        }

        float aver = sum / n;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] > aver)
                cnt++;
        }
        
        cout << (float)cnt / n * 100 << "%\n";
    }
}