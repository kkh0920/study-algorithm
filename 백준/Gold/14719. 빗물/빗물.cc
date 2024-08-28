#include <iostream>
using namespace std;

int h, w;
bool arr[500][500];

int solution(int x, int y) {
    arr[x][y] = 1;
    int cnt = 1;

    bool isPossible = true;
    int y1 = y - 1;
    while(1) {
        if(y1 < 0) {
            isPossible = false;
            break;
        }
        if(arr[x][y1]) break;
        arr[x][y1--] = 1;
        cnt++;
    }

    int y2 = y + 1;
    while(1) {
        if(y2 >= w) {
            isPossible = false;
            break;
        }
        if(arr[x][y2]) break;
        arr[x][y2++] = 1;
        cnt++;
    }

    return isPossible ? cnt : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    int num;
    for(int i = 0; i < w; i++) {
        cin >> num;
        for(int j = 0; j < num; j++) {
            arr[j][i] = 1;
        }
    }

    int result = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!arr[i][j]) {
                result += solution(i, j);
            }
        }
    }

    cout << result << '\n';

    return 0;
}