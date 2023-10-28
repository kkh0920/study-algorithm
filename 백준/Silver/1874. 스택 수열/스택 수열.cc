#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    int i, j, n, arr[100000], cnt = 1, count = 0;
    char result[200000];

    cin >> n;
    
    for(i = 0; i < n; i++){
        cin >> arr[i]; // 수열
    }

    for(i = 0; i < n; i++){
        for(j = cnt; j <= arr[i]; j++){
            s.push(j);
            result[count] = '+';
            count++;
            cnt++;
        }
        if(s.top() != arr[i]){
            cout << "NO" << '\n';
            return 0;
        }
        s.pop();
        result[count] = '-';
        count++;
    }
    for(i = 0; i < n * 2; i++){
        cout << result[i] << '\n';
    }
}