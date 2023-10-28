#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[50], b[50];
    int n, result = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n, compare);

    for(int i = 0; i < n; i++){
        result += a[i] * b[i];
    }

    cout << result << '\n';
}