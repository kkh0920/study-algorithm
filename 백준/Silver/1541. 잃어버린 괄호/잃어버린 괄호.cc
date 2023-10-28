#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, num = "";
    int result = 0;
    bool trig = false;
    getline(cin, str);

    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            num += str[i];
            continue;
        }
        
        if(trig)
            result -= stoi(num);
        else
            result += stoi(num);

        if(str[i] == '-')
            trig = true;

        num = "";
    }

    if(trig)
        result -= stoi(num);
    else
        result += stoi(num);

    cout << result << '\n';
}