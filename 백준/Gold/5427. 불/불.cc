#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, int> > person, fire;
int T, w, h, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[1000][1001];
bool visited[1000][1001];

void init(){
    while(!person.empty())
        person.pop();
    while(!fire.empty())
        fire.pop();
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            visited[i][j] = false;
        }
    }
}

int bfs(){
    int result = 0;
    while(!person.empty()){
        result++;

        // Spread Fire
        int fSize = fire.size();
        while(fSize--){
            int curFI = fire.front().first;
            int curFJ = fire.front().second;
            fire.pop();

            for(int i = 0; i < 4; i++){
                int nextFI = curFI + dx[i];
                int nextFJ = curFJ + dy[i];
                if(nextFI < 0 || nextFI >= h || nextFJ < 0 || nextFJ >= w)
                    continue;
                if(arr[nextFI][nextFJ] != '.')
                    continue;
                arr[nextFI][nextFJ] = '*';
                fire.push(make_pair(nextFI, nextFJ));
            }
        }

        // Move Person
        int pSize = person.size();
        while(pSize--){
            int curPI = person.front().first;
            int curPJ = person.front().second;
            person.pop();

            for(int i = 0; i < 4; i++){
                int nextPI = curPI + dx[i];
                int nextPJ = curPJ + dy[i];
                if(nextPI < 0 || nextPI >= h || nextPJ < 0 || nextPJ >= w)
                    return result;
                if(visited[nextPI][nextPJ] || arr[nextPI][nextPJ] != '.')
                    continue;
                visited[nextPI][nextPJ] = true;
                person.push(make_pair(nextPI, nextPJ));
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        cin >> w >> h;
        
        init();

        // Input array
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '@'){
                    person.push(make_pair(i, j));
                    arr[i][j] = '.';
                    visited[i][j] = true;
                }
                else if(arr[i][j] == '*')
                    fire.push(make_pair(i, j));
            }
        }

        // Output result
        int result = bfs();
        if(result == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << result << '\n';
    }       
}