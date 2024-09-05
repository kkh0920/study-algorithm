#include <iostream>
#include <vector>
using namespace std;

long long numMin, numMax;

bool v[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> numMin >> numMax;

    for(long long i = 2; i * i <= numMax; i++) {
        long long start;
        if(numMin % (i * i) == 0) {
            start = numMin;
        } else {
            start = (i * i) * (numMin / (i * i) + 1);
        }
        for(long long j = start; j <= numMax; j += i * i) {
            v[j - numMin] = true;
        }
    }

    int result = 0;
    for(int i = 0; i <= numMax - numMin; i++) {
        if(!v[i]) result++;
    }

    cout << result << '\n';

    return 0;
}