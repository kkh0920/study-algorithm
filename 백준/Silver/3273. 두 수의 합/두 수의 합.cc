#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, arr[100000], result = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> x;

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        if(arr[i] > x / 2)
            break;
        if(x - arr[i] != arr[i] && binary_search(arr, arr + n, x - arr[i]))
            result++;
    }

    cout << result << '\n';
}