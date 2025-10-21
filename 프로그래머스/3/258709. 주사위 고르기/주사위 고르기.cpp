#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dices;
vector<pair<int, vector<int>>> win_counts;
int sum_a_b[2][1001];

void init_sum() {
    for (int i = 0; i <= 1000; i++) {
        sum_a_b[0][i] = sum_a_b[1][i] = 0;
    }
}

void count_sum_all(vector<int> dice, int idx, int sum, int sum_idx) {
    if (idx == dice.size()) {
        sum_a_b[sum_idx][sum]++;
        return;
    }
    for (int i = 0; i < 6; i++) {
        count_sum_all(dice, idx + 1, sum + dices[dice[idx] - 1][i], sum_idx);
    }
}

void calculate(int dice_a) {
    vector<int> dices_a, dices_b;

    int N = dices.size();
    for (int i = 0; i < N; i++) {
        if (dice_a & (1 << i)) {
            dices_a.push_back(i + 1);
        } else {
            dices_b.push_back(i + 1);
        }
    }

    init_sum();
    count_sum_all(dices_a, 0, 0, 0);
    count_sum_all(dices_b, 0, 0, 1);

    int wins = 0;
    for (int i = 1; i <= 1000; i++) {
        sum_a_b[1][i] += sum_a_b[1][i - 1];
        wins += sum_a_b[0][i] * sum_a_b[1][i - 1];
    }
    win_counts.push_back({wins, dices_a});
}

void select_dice(int n, int r, int idx, int dice_a) {
    if (r == 0) {
        calculate(dice_a);
        return;
    }
    for (int i = idx; i < n; i++) {
        select_dice(n, r - 1, i + 1, dice_a | (1 << i));
    }
}

vector<int> solution(vector<vector<int>> dice) {
    dices = dice;
    select_dice(dices.size(), dices.size() / 2, 0, 0);
    sort(win_counts.begin(), win_counts.end());
    return win_counts.back().second;
}