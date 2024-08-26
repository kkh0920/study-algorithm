#include <iostream>
#include <queue>
using namespace std;

struct State {
    int x, y;
    int m, s, d;
};

int N, M, K;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector<State> cluster[50][50];
queue< pair<int, int> > point;

queue<State> fire;

void moveAll() {
    while(!fire.empty()) {
        State fireball = fire.front();
        fire.pop();
        
        int nX = fireball.x + dx[fireball.d] * fireball.s;
        if(nX < 0) {
            nX = nX % N + N;
            if(nX == N) nX = 0;
        }
        else if(nX >= N) nX %= N;
        
        int nY = fireball.y + dy[fireball.d] * fireball.s;
        if(nY < 0) {
            nY = nY % N + N;
            if(nY == N) nY = 0;
        }
        else if(nY >= N) nY %= N;
        
        fireball.x = nX; fireball.y = nY;

        point.push(make_pair(nX, nY));
        cluster[nX][nY].push_back(fireball);
    }
}

void mergeAndDivide() {
    while(!point.empty()) {
        int x = point.front().first;
        int y = point.front().second;
        point.pop();

        int size = cluster[x][y].size();
        if(size == 0) continue;

        if(size >= 2) {
            int mSum = 0, sSum = 0;
            int even = 0, odd = 0;
            for(auto c : cluster[x][y]) {
                mSum += c.m; sSum += c.s;
                c.d % 2 == 0 ? even++ : odd++;
            }
            int d = !even || !odd ? 0 : 1;
            int m = mSum / 5, s = sSum / size;
            if(m > 0) {
                for(; d < 8; d += 2) {
                    fire.push({ x, y, m, s, d });
                }
            }
        } else {
            fire.push(cluster[x][y][0]);
        }
        cluster[x][y].clear();
    }
}

int simulation() {
    int time = 0;
    while(!fire.empty() && time < K) {
        moveAll();
        mergeAndDivide();
        time++;
    }
    
    int result = 0;
    while(!fire.empty()) {
        result += fire.front().m;
        fire.pop();
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    int r, c, m, s, d;
    for(int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        fire.push({ r - 1, c - 1, m, s, d });
    }

    cout << simulation() << '\n';

    return 0;
}