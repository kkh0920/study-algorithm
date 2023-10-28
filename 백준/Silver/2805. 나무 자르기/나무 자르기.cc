#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int arr[1000000], i, n, m, sum = 0, max = 0;
    long long cnt = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        if(max <= arr[i])
            max = arr[i];   
    }
    int bottom = 0, top = max, middle = (top + bottom) / 2;
    while(bottom <= top){
        cnt = 0;
        for(i = 0; i < n; i++){
            if(arr[i] > middle){
                cnt += arr[i] - middle;
            }
        }
        if(cnt > m){
            bottom = middle + 1;
            middle = (top + bottom) / 2;
        }
        else if(cnt < m){
            top = middle - 1;
            middle = (top + bottom) / 2;
        }
        else    
            break;
    }
    cout << middle << '\n';
}