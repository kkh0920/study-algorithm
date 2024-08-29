#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > dc;

int N;
bool grid[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void makeDragonCurve(int x, int y, int d, int g) {
    dc.push_back(make_pair(x, y));
    dc.push_back(make_pair(x + dx[d], y + dy[d]));
    
    grid[x][y] = true;
    grid[x + dx[d]][y + dy[d]] = true;

    while(g--) {
        int eX = dc.back().first;
        int eY = dc.back().second;
        for(int i = (int) dc.size() - 2; i >= 0; i--) {
            int rX = dc[i].first - eX;
            int rY = dc[i].second - eY;
            grid[eX - rY][eY + rX] = true;
            dc.push_back(make_pair(eX - rY, eY + rX));
        }
    }

    dc.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int x, y, d, g;
    for(int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        makeDragonCurve(x, y, d, g);
    }

    int result = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(grid[i][j] && grid[i][j + 1] && 
                grid[i + 1][j] && grid[i + 1][j + 1]) {
                result++;
            }
        }
    }

    cout << result << '\n';

    return 0;
}