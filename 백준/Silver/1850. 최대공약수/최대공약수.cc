#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n1, n2;
    
    cin >> n1 >> n2;

    while(n1 % n2 != 0) {
        long long temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }

    for(int i = 0; i < n2; i++) {
        cout << 1;
    }
    cout << '\n';

    return 0;
}