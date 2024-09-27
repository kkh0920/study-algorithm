#include <iostream>
#include <map>
using namespace std;

string dna;
int dp[500][500];

map<char, char> complement = {
    {'a', 't'}, {'g', 'c'}
};

int getShortestRemove(int start, int end) {
    if(dp[start][end] != -1) {
        return dp[start][end];
    }

    int res = getShortestRemove(start + 1, end) + 1;
    if(dna[start] == 't' || dna[start] == 'c') {
        return dp[start][end] = res;
    }

    char cut = complement[dna[start]];
    for(int i = start + 1; i <= end; i++) {
        if(dna[i] == cut) {
            int remove = getShortestRemove(start + 1, i - 1) + getShortestRemove(i + 1, end);
            res = min(res, remove);
        }
    }

    return dp[start][end] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> dna;

    for(int i = 0; i < dna.size(); i++) {
        for(int j = 0; j < dna.size(); j++) {
            if(i > j) dp[i][j] = 0;
            else if(i == j) dp[i][j] = 1;
            else dp[i][j] = -1;
        }
    }

    int remove = getShortestRemove(0, dna.size() - 1);

    cout << dna.size() - remove << '\n';

    return 0;
}