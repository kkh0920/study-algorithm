#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num, sum = 0, result = -1001;

    cin >> N;


    for(int i = 0; i < N; i++){
        cin >> num;

        sum += num;
        result = max(result, sum);
        
        if(sum < 0){
            sum = 0;
        }
    }

    cout << result << '\n';
}