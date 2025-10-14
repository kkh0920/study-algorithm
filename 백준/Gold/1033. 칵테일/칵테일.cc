#include <iostream>
#include <queue>
using namespace std;

long long N, result[10];
bool visited[10];
vector<int> adj[10];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void multiply(int index, long long value) {
    visited[index] = true;
    result[index] *= value;
    for (auto next : adj[index]) {
        if (!visited[next]) {
            multiply(next, value);
        }
    }
    visited[index] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    int a, b, p, q;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> p >> q;

        long long g = gcd(p, q);
        p /= g; 
        q /= g;

        if (result[a] == 0 && result[b] == 0) {
            result[a] = p; 
            result[b] = q;
        } else if (result[a] == 0) {
            long long gcd_val = gcd(result[b], q);
            result[a] = p * (result[b] / gcd_val);
            multiply(b, q / gcd_val);
        } else if (result[b] == 0) {
            long long gcd_val = gcd(result[a], p);
            result[b] = q * (result[a] / gcd_val);
            multiply(a, p / gcd_val);
        } else {
            long long gcd1 = gcd(result[a], p);
            long long gcd2 = gcd(result[b], q);

            long long val1 = (p / gcd1) * (result[b] / gcd2);
            long long val2 = (q / gcd2) * (result[a] / gcd1);

            multiply(a, val1);
            multiply(b, val2);
        }

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (result[0] == 0) {
        result[0] = 1;
    }

    int rgcd = gcd(result[0], result[1]);
    for (int i = 2; i < N; i++) {
        rgcd = gcd(rgcd, result[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] / rgcd << ' ';
    }
    cout << '\n';

    return 0;
}