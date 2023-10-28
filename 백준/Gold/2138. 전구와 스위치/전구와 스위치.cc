#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string before, after;

    cin >> N >> before >> after;

    for(int i = 0; i < 2; i++){
        int cnt = 0;
        string temp = before;

        if(i == 1){
            temp[0] = temp[0] == '0' ? '1' : '0';
            temp[1] = temp[1] == '0' ? '1' : '0';
            cnt++;
        }

        for(int i = 1; i < N; i++){
            if(after[i - 1] != temp[i - 1]){
                temp[i - 1] = temp[i - 1] == '0' ? '1' : '0';
                temp[i] = temp[i] == '0' ? '1' : '0';
                if(i < N - 1)
                    temp[i + 1] = temp[i + 1] == '0' ? '1' : '0';
                cnt++;
            }
        }
        
        if(temp == after){
            cout << cnt << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}