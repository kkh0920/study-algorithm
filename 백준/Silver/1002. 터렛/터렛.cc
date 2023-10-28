#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t, x1, y1, r1, x2, y2, r2, maxr, minr;
    double distance, radius;
    cin >> t;
    while(t){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        radius = r1 + r2;
        maxr = r1 > r2 ? r1 : r2;
        minr = r1 < r2 ? r1 : r2;
        
        if(x1 == x2 && y1 == y2){
            if(r1 == r2 && r1 != 0)
                cout << -1 << '\n';
            else if(r1 == r2 && r1 == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(maxr - minr > distance)
            cout << 0 << '\n';
        else if(maxr - minr == distance)
            cout << 1 << '\n';
        else if(radius > distance)
            cout << 2 << '\n';
        else if(radius == distance)
            cout << 1 << '\n';
        else if(radius < distance)
            cout << 0 << '\n';
        t--;
    }
    return 0;
}