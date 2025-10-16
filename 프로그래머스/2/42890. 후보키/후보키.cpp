#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool is_checked[1 << 8];

void check_all(int key_bit) {
    for (int i = 0; i < (1 << 8); i++) {
        if ((i | key_bit) == i) {
            is_checked[i] = true;
        }
    }
}

bool is_unique(vector<vector<string>> relation, int key_bit) {
    int rows = relation.size();
    int columns = relation[0].size();
    vector<string> s(rows, "");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (key_bit & (1 << j)) {
                s[i] += relation[i][j];
            }
        }
    }
    sort(s.begin(), s.end());

    for (int i = 1; i < rows; i++) {
        if (s[i] == s[i - 1]) {
            return false;
        }
    }

    return true;
}

int combination(vector<vector<string>> relation, int n, int r, int index, int key_bit) {
    if (r != 0) {
        int result = 0;
        for (int i = index; i < n; i++) {
            result += combination(relation, n, r - 1, i + 1, key_bit | (1 << i));
        }
        return result;
    }

    if (is_checked[key_bit]) {
        return 0;
    }
    if (is_unique(relation, key_bit)) {
        check_all(key_bit);
        return 1;
    }
    return 0;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int columns = relation[0].size();
    for (int i = 1; i <= columns; i++) {
        answer += combination(relation, columns, i, 0, 0);
    }
    return answer;
}