#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, w, h;

    cin >> x >> y >> w >> h;

    cout << min(min(x, w - x), min(y, h - y)) << '\n';
}