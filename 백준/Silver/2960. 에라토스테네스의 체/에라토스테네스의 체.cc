#include <iostream>
#include <cmath>
using namespace std;

int n, k;
bool removed[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    int num;
    for(int i = 2; i <= n; i++) {
        if(removed[i]) continue;
        for(int j = i; j <= n; j += i) {
            if(!removed[j]) {
                removed[j] = true;
                if(--k == 0) {
                    num = j;
                    break;
                }
            }
        }
    }

    cout << num << '\n';

    return 0;
}