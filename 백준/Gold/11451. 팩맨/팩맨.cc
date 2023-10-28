#include <iostream>
#include <queue>
using namespace std;

class Pacman{
public:
    int p1_x, p1_y, p2_x, p2_y;
    string route;
    Pacman(int x1, int y1, int x2, int y2, string r){
        p1_x = x1; p1_y = y1;
        p2_x = x2; p2_y = y2;
        route = r;
    }
};

queue<Pacman> q;
vector< pair<int, int> > pac;
string resultRoute;
int resultTime = 0, T, N, M, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[50][51], cp[4] = { 'N', 'S', 'W', 'E' };
bool visited[50][50][50][50];

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                for(int l = 0; l < M; l++){
                    visited[i][j][k][l] = false;
                }
            }
        }
    }
    pac.clear();
    while(!q.empty())
        q.pop();
}

void boundaryCheck(int& x, int& y){
    if(x < 0) x = N - 1;
    else if(x >= N) x = 0;
    else if(y < 0) y = M - 1;
    else if(y >= M) y = 0;
}

void bfs(){
    visited[q.front().p1_x][q.front().p1_y][q.front().p2_x][q.front().p2_y] = true;

    int t = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int p1_x = q.front().p1_x;
            int p1_y = q.front().p1_y;
            int p2_x = q.front().p2_x;
            int p2_y = q.front().p2_y;
            string route = q.front().route;
            q.pop();

            if(p1_x == p2_x && p1_y == p2_y){
                resultTime = t;
                resultRoute = route;
                return;
            }

            for(int i = 0; i < 4; i++){
                int next_p1_x = p1_x + dx[i];
                int next_p1_y = p1_y + dy[i];
                int next_p2_x = p2_x + dx[i];
                int next_p2_y = p2_y + dy[i];
                string nextRoute = route + cp[i];

                boundaryCheck(next_p1_x, next_p1_y);
                boundaryCheck(next_p2_x, next_p2_y);

                if(arr[next_p1_x][next_p1_y] == 'X'){
                    next_p1_x -= dx[i];
                    next_p1_y -= dy[i];
                    boundaryCheck(next_p1_x, next_p1_y);
                }
                if(arr[next_p2_x][next_p2_y] == 'X'){
                    next_p2_x -= dx[i];
                    next_p2_y -= dy[i];
                    boundaryCheck(next_p2_x, next_p2_y);
                }

                if(arr[next_p1_x][next_p1_y] == 'G' || arr[next_p2_x][next_p2_y] == 'G')
                    continue;
                if(visited[next_p1_x][next_p1_y][next_p2_x][next_p2_y])
                    continue;

                visited[next_p1_x][next_p1_y][next_p2_x][next_p2_y] = true;
                q.push(Pacman(next_p1_x, next_p1_y, next_p2_x, next_p2_y, nextRoute));
            }
        }
        t++;
    }
    resultTime = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while(T--){
        cin >> N >> M;

        init();
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'P'){
                    pac.push_back(make_pair(i, j));
                    arr[i][j] = '.';
                }
            }
        }

        q.push(Pacman(pac[0].first, pac[0].second, pac[1].first, pac[1].second, ""));

        bfs();

        if(resultTime == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << resultTime << ' ' << resultRoute << '\n';
    }
}
