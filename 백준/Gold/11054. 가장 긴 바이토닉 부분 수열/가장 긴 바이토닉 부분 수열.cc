#include <iostream>
using namespace std;

int n, arr[1000], asc[1000], desc[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                asc[i] = max(asc[i], asc[j] + 1);
            }
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(arr[i] > arr[j]) {
                desc[i] = max(desc[i], desc[j] + 1);
            }
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, asc[i] + desc[i]);
    }

    cout << result + 1 << '\n';

    return 0;
}