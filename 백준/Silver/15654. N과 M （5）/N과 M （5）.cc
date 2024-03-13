#include <iostream>
#include <algorithm>
using namespace std;

int arr[8], result[8], n, m;
bool checked[8];

void print() {
    for(int i = 0; i < m; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
}

void permutation(int cnt) {
    if(cnt == m) {
        print();
        return;
    }

    for(int i = 0; i < n; i++) {
        if(checked[i])
            continue;
        
        result[cnt] = arr[i];
        checked[i] = true;
        
        permutation(cnt + 1);
        
        checked[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    permutation(0);

    return 0;
}