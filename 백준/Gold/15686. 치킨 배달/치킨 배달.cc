#include <iostream>
#include <vector>
using namespace std;

int n, m, result = 99999;
vector< pair<int, int> > chicken, home, selected;

int getChickenRoad() {
    int sum = 0;
    for(auto h : home) {
        int cr = 99999;
        for(auto s : selected) {
            cr = min(cr, abs((s.first - h.first)) + abs(s.second - h.second));
        }
        sum += cr;
    }
    return sum;
}

void solution(int index, int size, int cnt) {
    if(cnt == 0) {
        result = min(result, getChickenRoad());
        return;
    }
    for(int i = index; i < size; i++) {
        selected.push_back(chicken[i]);
        solution(i + 1, size, cnt - 1);
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int num;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> num;
            if(num == 1) home.push_back(make_pair(i, j));
            else if(num == 2) chicken.push_back(make_pair(i, j));
        }
    }

    solution(0, chicken.size(), m);

    cout << result << '\n';

    return 0;
}