#include <iostream>
#include <algorithm>
using namespace std;

int N, height[50], cnt[50];

double line(int x, int i, int j) {
    return ((height[j] - height[i]) / double(j - i))
             * (x - i)
             + height[i];
}

bool notExistBetween(int i, int j) {
    for(int k = i + 1; k < j; k++) {
        if(height[k] >= line(k, i, j)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> height[i];
        cnt[i] = 2;
    }
    cnt[0] = cnt[N - 1] = N > 1 ? 1 : 0;
    
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 2; j < N; j++) {
            if(notExistBetween(i, j)) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    cout << *max_element(cnt, cnt + N) << '\n';

    return 0;
}