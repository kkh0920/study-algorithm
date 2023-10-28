#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, num[100000], n, m, z, isExist = 0;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num, num + n);
    cin >> m;
    for(i = 0; i < m; i++){
        cin >> z;
        int start = 0, end = n - 1, middle;
        while(start <= end){
            middle = (start + end) / 2;
            if(z > num[middle]){
                start = middle + 1;
            }
            else if(z < num[middle]){
                end = middle - 1;
            }
            else{
                isExist++;
                break;
            }
        }
        if(isExist)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        isExist = 0;
    }
}