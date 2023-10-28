#include <iostream>
using namespace std;

int N, M, number[2001];
bool isPal[2001][2001], check[2001][2001];

bool isPalindrome(int s, int e){
    if(check[s][e] == true)
        return isPal[s][e];

    check[s][e] = true;

    if(number[s] != number[e])
        return isPal[s][e] = false;
    if(e - s <= 1)
        return isPal[s][e] = true;
        
    return isPal[s][e] = isPalindrome(s + 1, e - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> number[i];
    }

    cin >> M;

    int s, e;
    for(int i = 0; i < M; i++){
        cin >> s >> e;
        cout << isPalindrome(s, e) << '\n';
    }
}