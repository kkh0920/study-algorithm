#include <bits/stdc++.h>
using namespace std;

bool isPrimeNumber[10000], checked[10000] = { false };
int T, curNum, resNum;

int bfs(){
    queue<int> q;
    q.push(curNum);

    fill(checked, checked + 10000, false);
    checked[curNum] = true;

    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        for(int k = 0; k < size; k++){
            int cur = q.front();
            q.pop();

            if(cur == resNum){
                return cnt;
            }

            for(int i = 0; i < 4; i++){
                string s = to_string(cur);
                for(int j = 0; j <= 9; j++){
                    if(i == 0 && j == 0)
                        continue;

                    s[i] = j + '0';
                    int next = stoi(s);
                    if(!checked[next] && isPrimeNumber[next]){
                        checked[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        cnt++;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(isPrimeNumber, isPrimeNumber + 10000, true);
    for(int i = 2; i <= 100; i++){
        if(!isPrimeNumber[i])
            continue;
        for(int j = i * i; j < 10000; j += i){
            isPrimeNumber[j] = false;
        }
    }

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> curNum >> resNum;
        
        int result = bfs();
        if(result == -1)
            cout << "Impossible\n";
        else
            cout << result << '\n';
    }
}