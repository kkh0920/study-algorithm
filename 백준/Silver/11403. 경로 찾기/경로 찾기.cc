#include <iostream>
using namespace std;

int N, arr[101][101];

int main(){
    
    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                arr[i][j] = 123456789;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(arr[i][j] == 123456789)
                cout << 0 << ' ';
            else
                cout << 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}