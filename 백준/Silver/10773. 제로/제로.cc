#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 0, n, arr[100000], result = 0;
    
    cin >> n;
    
    while(n--){
        cin >> arr[i];
        result += arr[i];
        if(arr[i] == 0){
            result -= arr[i - 1];
            i -= 2;
        }
        i++;
    }

    cout << result << '\n';
}