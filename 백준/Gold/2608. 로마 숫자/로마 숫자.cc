#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
map<int, string> mr;

string str1, str2;

int to_number(string str) {
    int prev = 0, result = 0;
    for(int i = 1; i < str.length(); i++) {
        string s1 = "", s2 = "";
        s1 += str[i]; s2 += str[i - 1];
        if(m[s1] <= m[s2]) {
            string s = "";
            for(int j = prev; j < i; j++) {
                s += str[j];
            }
            result += m[s];
            prev = i;
        }
    }
    
    string s = "";
    for(int i = prev; i < str.length(); i++) {
        s += str[i];
    }
    result += m[s];

    return result;
}

string to_roman_number(int number) {
    string result = "";
    map<int, string>::reverse_iterator iter;
    for(iter = mr.rbegin(); iter != mr.rend(); iter++) {
        int n = (*iter).first;
        string s = (*iter).second;
        for(int i = 0; i < number / n; i++) {
            result += s;
        }
        number %= n;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    m["I"] = 1; m["IV"] = 4; m["V"] = 5; m["IX"] = 9;
    m["X"] = 10; m["XL"] = 40; m["L"] = 50; m["XC"] = 90;
    m["C"] = 100; m["CD"] = 400; m["D"] = 500; m["CM"] = 900;
    m["M"] = 1000;

    mr[1] = "I"; mr[4] = "IV"; mr[5] = "V"; mr[9] = "IX";
    mr[10] = "X"; mr[40] = "XL"; mr[50] = "L"; mr[90] = "XC";
    mr[100] = "C"; mr[400] = "CD"; mr[500] = "D"; mr[900] = "CM";
    mr[1000] = "M";

    cin >> str1 >> str2;

    int sum = to_number(str1) + to_number(str2);
    cout << sum << '\n' << to_roman_number(sum) << '\n';

    return 0;
}