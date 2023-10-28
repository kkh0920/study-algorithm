#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str[50];

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    char temp;
    for(int i = 0; i < str[0].length(); i++){
        temp = str[0][i];
        for(int j = 1; j < n; j++){
            if(temp != str[j][i]){
                temp = '?';
                break;
            }
        }
        cout << temp;
    }
    cout << '\n';
}