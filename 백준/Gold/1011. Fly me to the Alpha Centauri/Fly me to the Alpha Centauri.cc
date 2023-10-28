#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, s, e;

    cin >> t;

    while(t--){
        cin >> s >> e;

        int i, result = 0, dist = e - s;
        for(i = 1; dist >= i * 2; i++){
            result += 2;
            dist -= i * 2;
        }
        
        if(dist > i)
            result += 2;
        else if(dist > 0)
            result++;
        
        cout << result << '\n';
    }
}