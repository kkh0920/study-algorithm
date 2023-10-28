#include <bits/stdc++.h>
using namespace std;

int n, board[14], result = 0;

bool isAttack(int r){
    for(int i = 0; i < r; i++){
        if(board[r] == board[i] || r - i == abs(board[r] - board[i]))
            return true;
    }
    return false;
}

void N_Queen(int r){
    if(r == n){
        result++;
        return;
    }
    for(int i = 0; i < n; i++){
        board[r] = i;
        if(!isAttack(r))
            N_Queen(r + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    N_Queen(0);

    cout << result << '\n';
}