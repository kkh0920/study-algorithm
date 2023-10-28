#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    
    int sum = 0, cnt = 0, a;
    for(int i = 0; i < N; i++){
        cin >> a;
        sum += a;
        cnt += a / 2;
    }
    
    if(sum % 3 == 0 && sum / 3 <= cnt)
        cout << "YES\n";
    else
        cout << "NO\n";
}