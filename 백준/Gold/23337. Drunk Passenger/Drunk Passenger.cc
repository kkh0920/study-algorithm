#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double result = 0;

    cin >> n;

    if(n >= 2) {
        result += 1.0;
    }

    for(int i = 0; i < n - 2; i++) {
        result += 0.5;
    }

    cout << fixed;
    cout.precision(10);

    cout << result / (n - 1) << '\n';

    return 0;
}