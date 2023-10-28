#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, arr[100000], result = 0;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    for(int i = 0; i < n; i++){
        result = max(result, arr[i] * (n - i));
    }
    
    cout << result << '\n';
}