#include <iostream>
using namespace std;

int T, N;
char op[3] = { ' ', '+', '-' };
string str = "";

int getResult() {
    int result = 0;
    char op = ' ';
    string num = "";
    for(int i = 0; i < (int) str.length(); i++) {
        if(str[i] == ' ') continue;

        if(str[i] == '+' || str[i] == '-') {
            result += (op == '-'? -stoi(num) : stoi(num));
            op = str[i];
            num = "";
        } else {
            num += str[i];
        }
    }
    result += (op == '-'? -stoi(num) : stoi(num));
    return result;
}

void solve(int cnt) {
    str += to_string(cnt + 1);

    if(cnt == N - 1) {
        if(getResult() == 0) {
            cout << str << '\n';
        }
        str.pop_back();
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        str += op[i];
        solve(cnt + 1);
        str.pop_back();
    }
    
    str.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> N;
        solve(0);
        cout << '\n';
    }

    return 0;
}