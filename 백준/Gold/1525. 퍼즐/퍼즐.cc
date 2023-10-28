#include <bits/stdc++.h>
using namespace std;

string str = "";
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int result = 0;

void bfs(int s){
    queue< pair<string, int> > q;
    q.push(make_pair(str, s));

    map<string, int> visited;
    visited[str] = 1;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            string cur = q.front().first;
            int curIndex = q.front().second;
            q.pop();

            if(cur == "123456780")
                return;

            for(int j = 0; j < 4; j++){
                int nI = curIndex / 3 + dx[j];
                int nJ = curIndex % 3 + dy[j];
                string next = cur;

                if(nI < 0 || nI >= 3 || nJ < 0 || nJ >= 3)
                    continue;
                
                int nextIndex = nI * 3 + nJ;

                swap(next[curIndex], next[nextIndex]);

                if(visited[next] == 1)
                    continue;
                
                visited[next] = 1;
                q.push(make_pair(next, nextIndex));
            }
        }
        result++;
    }
    
    result = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, s;
    for(int i = 0; i < 9; i++){
        cin >> num;
        str.append(to_string(num));
        if(num == 0)
            s = i;
    }

    bfs(s);

    cout << result << '\n';
}