#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > entrance;
queue< pair<int, int> > q;
int t, h, w, result = 0;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[100][101];
bool key[26], visited[100][100];

void initVisited(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(){
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= h || nJ < 0 || nJ >= w){
                for(auto x : entrance){
                    char c = arr[x.first][x.second];
                    if((c >= 'A' && c <= 'Z' && !key[c - 'A']) || visited[x.first][x.second])
                        continue;
                    visited[x.first][x.second] = true;
                    q.push(make_pair(x.first, x.second));
                }
                continue;
            }
                   
            if(visited[nI][nJ] || arr[nI][nJ] == '*')
                continue;
            if(arr[nI][nJ] >= 'A' && arr[nI][nJ] <= 'Z' && !key[arr[nI][nJ] - 'A'])
                continue;
            
            if(arr[nI][nJ] >= 'a' && arr[nI][nJ] <= 'z' && !key[arr[nI][nJ] - 'a']){
                key[arr[nI][nJ] - 'a'] = true;
                initVisited();
            }

            if(arr[nI][nJ] == '$'){
                arr[nI][nJ] = '.';
                result++;
            }

            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++){
        result = 0;
        entrance.clear();
        for(int j = 0; j < 26; j++){
            key[j] = false;
        }

        cin >> h >> w;

        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                cin >> arr[j][k];
                visited[j][k] = false;
                if((j == 0 || j == h - 1 || k == 0 || k == w - 1) && arr[j][k] != '*'){
                    if(arr[j][k] >= 'a' && arr[j][k] <= 'z')
                        key[arr[j][k] - 'a'] = true;
                    entrance.push_back(make_pair(j, k));
                }
            }
        }

        string s;
        cin >> s;
        if(s != "0"){
            for(auto x : s){
                key[x - 'a'] = true;
            }
        }

        for(auto x : entrance){
            char c = arr[x.first][x.second];
            if(c >= 'A' && c <= 'Z' && !key[c - 'A'])
                continue;
            if(c == '$'){
                arr[x.first][x.second] = '.';
                result++;
            }
            visited[x.first][x.second] = true;
            q.push(make_pair(x.first, x.second));
        }

        bfs();

        cout << result << '\n';
    }
}