#include <iostream>
#include <queue>
using namespace std;

queue<int> robot;

int N, K, d[201];
bool isRobot[101];

void rotate() {
    // rotate durability
    int temp = d[2 * N];
    for(int i = 2 * N; i > 1; i--) {
        d[i] = d[i - 1];
    }
    d[1] = temp;
    // rotate robot & remove robot on the last position
    for(int i = N - 1; i > 1; i--) {
        isRobot[i] = isRobot[i - 1];
    }
    isRobot[1] = false;
}

void moveRobot() {
    int size = robot.size();
    while(size--) {
        int cur = robot.front() + 1; // from rotate(), robot's position is changed
        robot.pop();

        if(cur == N) continue; // remove robot on the last position

        if(!isRobot[cur + 1] && d[cur + 1] > 0) {
            isRobot[cur] = false;
            if(--d[cur + 1] == 0) K--;
            if(cur + 1 < N) {
                isRobot[cur + 1] = true;
                robot.push(cur + 1);
            }
        } else {
            robot.push(cur); // can't move
        }
    }
}

void putRobot() {
    if(d[1] > 0) { 
        isRobot[1] = true;
        robot.push(1);
        if(--d[1] == 0) K--;
    }
}

void simulation() {
    int cnt = 0;
    while(K > 0) {
        cnt++;
        rotate();
        moveRobot();
        putRobot();
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= 2 * N; i++) {
        cin >> d[i];
    }

    simulation();

    return 0;
}