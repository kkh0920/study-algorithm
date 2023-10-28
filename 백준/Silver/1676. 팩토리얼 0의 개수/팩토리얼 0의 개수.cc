#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, res = 0;

    cin >> n;

    for(int i = 5; i <= n; i += 5){
        if(i % 125 == 0)
            res += 3;
        else if(i % 25 == 0)
            res += 2;
        else
            res++;
    }

    cout << res << '\n';
}