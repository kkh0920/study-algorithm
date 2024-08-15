#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> home;
int n, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;

    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        home.push_back(x);
    }
    sort(home.begin(), home.end());

    int size = home.size(), result = 0;
    int start = 1, end = (home.back() - home.front()) / (c - 1);
    while(start <= end) {
        int middle = (start + end) / 2;
        int remain = c - 1, prev = 0;
        for(int i = 1; i < size; i++) {
            if(home[i] >= home[prev] + middle) {
                if((--remain) == 0) break;
                prev = i;
            }
        }
        if(remain > 0) {
            end = middle - 1;
        } else {
            result = middle;
            start = middle + 1;
        }
    }

    cout << result << '\n';

    return 0;
}