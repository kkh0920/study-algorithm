#include <iostream>
#include <vector>
using namespace std;

int W, B;
vector<int> weight;
int dp[70010][31];

int solve(int bw, int index) {
    if(dp[bw + 15000][index] != 0) return dp[bw + 15000][index];
    if(bw == 0) return 1;
    for(int i = index; i < W; i++) {
        if(solve(bw - weight[i], i + 1) == 1 || 
           solve(bw + weight[i], i + 1) == 1) 
            return dp[bw + 15000][index] = 1;
    }
    return dp[bw + 15000][index] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W;

    int w;
    for(int i = 0; i < W; i++) {
        cin >> w;
        weight.push_back(w);
    }

    cin >> B;

    int bw;
    for(int i = 0; i < B; i++) {
        cin >> bw;
        cout << (solve(bw, 0) == 1 ? "Y" : "N") << '\n';
    }

    return 0;
}