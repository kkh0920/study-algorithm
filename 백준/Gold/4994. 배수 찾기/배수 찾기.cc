#include <iostream>
#include <queue>
using namespace std;

string result[201];

string bfs(int N){
    queue< pair<string, int> > q;
    q.push(make_pair("1", 1));

    while(1){
        string num = q.front().first;
        int mod = q.front().second % N;
        q.pop();

        if(mod == 0)
            return num;
        
        q.push(make_pair(num + "1", mod * 10 + 1));
        q.push(make_pair(num + "0", mod * 10));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 200; i++){
        result[i] = bfs(i);
    }

    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        cout << result[n] << '\n';
    }
}