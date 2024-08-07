#include <iostream>
using namespace std;

int n, s, arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;

    cin >> arr[1];
    for(int i = 2; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }  

    int start = 1, end = 1, result = 999999;
    while(start <= end && end <= n) {
        int sum = arr[end] - arr[start - 1];
        if(sum >= s) {
            result = min(result, end - start++ + 1);
        } else {
            end++;
        }
    }

    cout << (result == 999999 ? 0 : result) << '\n';

    return 0;
}