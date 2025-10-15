#include <string>
#include <vector>

using namespace std;

bool is_correct(string str) {
    vector<char> v;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            v.push_back('(');
            continue;
        }
        if (v.empty()) {
            return false;
        }
        v.pop_back();
    }
    return v.empty() ? true : false;
}

string reverse(string u) {
    string result = "";
    int len = u.length();
    for (int i = 1; i < len - 1; i++) {
        result += (u[i] == '(' ? ')' : '(');
    }
    return result;
}

string solution(string p) {
    if (is_correct(p)) {
        return p;
    }
    
    int e = 0, len = p.length();
    int num1 = 0, num2 = 0;
    for (e = 0; e < len; e++) {
        if (p[e] == '(') {
            num1++;
        } else {
            num2++;
        }
        if (num1 == num2) {
            break;
        }
    }
    
    string u = p.substr(0, e + 1);
    string v = p.substr(e + 1, len - (e + 1));
    
    if (is_correct(u)) {
        return u + solution(v);
    }
    return "(" + solution(v) + ")" + reverse(u);
}