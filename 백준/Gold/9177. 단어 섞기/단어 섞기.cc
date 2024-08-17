#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
string str[3];

bool checked[201][201];

void init(int len1, int len2) {
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            checked[i][j] = false;
        }
    }
}

bool solution() {
    queue< pair<int, int> > q;
    q.push(make_pair(0, 0));
    checked[0][0] = false;
    int cursor = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int idx1 = q.front().first;
            int idx2 = q.front().second;
            q.pop();

            if(cursor >= str[2].length()) {
                return true;
            }

            if(idx1 < str[0].length() && str[0][idx1] == str[2][cursor]) {
                if(!checked[idx1 + 1][idx2]) {
                    checked[idx1 + 1][idx2] = true;
                    q.push(make_pair(idx1 + 1, idx2));
                }
            }
            if(idx2 < str[1].length() && str[1][idx2] == str[2][cursor]) {
                if(!checked[idx1][idx2 + 1]) {
                    checked[idx1][idx2 + 1] = true;
                    q.push(make_pair(idx1, idx2 + 1));
                }
            }
        }
        cursor++;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> str[0] >> str[1] >> str[2];
        init(str[0].length(), str[1].length());
        string res = solution() ? "yes" : "no";
        cout << "Data set " << i << ": " << res << '\n';
    }

    return 0;
}