#include <iostream>
using namespace std;

int n, m, arr[8];

void print() {
    for(int i = 0; i < m; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void permutation(int cnt, int idx) {
    if(cnt == m) {
        print();
        return;
    }

    for(int i = idx; i < n; i++) {
        arr[cnt] = i + 1;
        permutation(cnt + 1, i + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    permutation(0, 0);

    return 0;
}