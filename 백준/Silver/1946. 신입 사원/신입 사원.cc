#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> arr[100000];
    int T, N;

    cin >> T;

    for(int i = 0; i < T; i++){
        int result = 1;
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> arr[j].first >> arr[j].second;
        }

        sort(arr, arr + N, compare);

        int temp = arr[0].second;
        for(int j = 1; j < N; j++){
            if(arr[j].second <= temp){
                result++;
                temp = arr[j].second;
            }
        }
    
        cout << result << '\n';
    }
}