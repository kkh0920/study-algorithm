#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string to_magic(long long n) {
    string result = "";
    while (n > 0) {
        result += 'a' + (--n % 26);
        n /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long to_number(string magic) {
    int len = magic.length();
    long long result = 0;
    for (int i = 0; i < len; i++) {
        result += (magic[i] - 'a' + 1) * pow(26, len - i - 1);
    }
    return result;
}

string solution(long long n, vector<string> bans) {
    sort(bans.begin(), bans.end(), [](string a, string b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    });
    for (auto ban : bans) {
        if (to_number(ban) <= n) {
            n++;
        }
    }
    return to_magic(n);
}