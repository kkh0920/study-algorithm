#include <bits/stdc++.h>
using namespace std;

int arr[128][128], N, white = 0, blue = 0;

void split(int n, int I, int J){
    int cnt0 = 0, cnt1 = 0;
    for(int i = I; i < I + n; i++){
        for(int j = J; j < J + n; j++){
            if(arr[i][j] == 0)
                cnt0++;
            else
                cnt1++;
        }
    }
    if(cnt0 == 0){
        blue++;
        return;
    }
    if(cnt1 == 0){
        white++;
        return;
    }

    split(n / 2, I, J);
    split(n / 2, I + n / 2, J);
    split(n / 2, I , J + n / 2);
    split(n / 2, I + n / 2, J + n / 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    split(N, 0, 0);

    cout << white << '\n';
    cout << blue << '\n';
}
