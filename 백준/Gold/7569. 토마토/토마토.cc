#include <bits/stdc++.h>
using namespace std;

queue< pair<int, pair<int, int> > > q;
int arr[100][100][100];
int N, M, H, cnt = 0, result = 0;
int dx[6] = { -1, 1, 0, 0, 0, 0 }, dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

void bfs(){
    while(!q.empty() && cnt){
        int size = q.size();  
        for(int i = 0; i < size; i++){
            int curH = q.front().first;
            int curN = q.front().second.first;
            int curM = q.front().second.second;
            q.pop();

            for(int i = 0; i < 6; i++){
                int nH = curH + dz[i];
                int nN = curN + dx[i];
                int nM = curM + dy[i];
                if(nH < 0 || nH >= H || nN < 0 || nN >= N || nM < 0 || nM >= M)
                    continue;
                if(arr[nH][nN][nM] == 1 || arr[nH][nN][nM] == -1)
                    continue;
                cnt--;
                arr[nH][nN][nM] = 1;
                q.push(make_pair(nH, make_pair(nN, nM)));
            }
        }
        result++;
    }

    if(cnt)
        result = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1)
                    q.push(make_pair(i, make_pair(j, k)));
                else if(arr[i][j][k] == 0)
                    cnt++;
            }
        }
    }

    bfs();

    cout << result << '\n';
}