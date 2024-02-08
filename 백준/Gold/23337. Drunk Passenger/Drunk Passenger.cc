#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double result;

    cin >> n;

    if(n == 1)
        result = 0;
    else
        result = (1.0 + 0.5 * (n - 2)) / (n - 1);

    cout << fixed;
    cout.precision(10);

    cout << result << '\n';

    return 0;
}