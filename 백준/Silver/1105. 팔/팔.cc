#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string L, R;

    cin >> L >> R;

    if(L.size() != R.size()){
        cout << 0 << '\n';
        return 0;
    }

    int result = 0;
    for(int i = 0; i < L.size(); i++){
        if(L[i] == '8' && R[i] == '8')
            result++;
        if(L[i] != R[i])
            break;
    }

    cout << result << '\n';
}