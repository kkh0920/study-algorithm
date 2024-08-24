#include <iostream>
#include <vector>
using namespace std;

int c, p;

bool map[101][110];
int height[101];

int rotateNum[7] = { 1, 0, 1, 1, 3, 3, 3 };
int tetromino[7][4][2] = { { { 0, -1 }, { 0, 0 }, { 0, 1 }, { 0, 2 } },
                        { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } },
                        { { 0, -1 }, { 0, 0 }, { -1, 0 }, { -1, 1 } },
                        { { 0, -1 }, { 0, 0 }, { 1, 0 }, { 1, 1 } },
                        { { -1, 0 }, { 0, 0 }, { 1, 0 }, { 0, 1 } },
                        { { 1, -1 }, { 0, -1 }, { 0, 0 }, { 0, 1 } },
                        { { -1, -1 }, { 0, -1 }, { 0, 0 }, { 0, 1 } } };

void rotate(int shape[4][2]) {
    for(int i = 0; i < 4; i++) {
        swap(shape[i][0], shape[i][1]);
        shape[i][1] *= -1;
    }
}

bool canPlace(int curX, int curY) {
    vector< pair<int, int> > point;
    bool isPossible = true;
    for(int i = 0; i < 4; i++) {
        int x = curX + tetromino[p - 1][i][0];
        int y = curY + tetromino[p - 1][i][1];
        if(x < 0 || x >= c || y < 0 || map[x][y]) {
            isPossible = false;
            break;
        }
        map[x][y] = 1;
        point.push_back(make_pair(x, y));
    }

    if(isPossible) {
        for(int i = 0; i < point.size(); i++) {
            int x = point[i].first, y = point[i].second;
            if(y > 0 && !map[x][y - 1]) {
                isPossible = false;
                break;
            }
        }
    }

    for(int i = 0; i < point.size(); i++) {
        map[point[i].first][point[i].second] = 0;
    }

    return isPossible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> p;

    for(int i = 0; i < c; i++) {
        cin >> height[i];
        for(int j = 0; j < height[i]; j++) {
            map[i][j] = true;
        }
    }

    int result = 0;
    for(int r = 0; r <= rotateNum[p - 1]; r++) {
        for(int i = 0; i < c; i++) {
            for(int j = height[i]; j <= height[i] + 2; j++) {
                result += canPlace(i, j) ? 1 : 0;
            }
        }
        rotate(tetromino[p - 1]);
    }

    cout << result << '\n';

    return 0;
}