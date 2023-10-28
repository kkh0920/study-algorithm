#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    stack< pair<int, int> > s;

    cin >> N;

    int a;
    for(int i = 0; i < N; i++){
        cin >> a;

        if(s.empty())
            cout << 0 << ' ';
        
        else{
            while(!s.empty() && a > s.top().first){
                s.pop();
            }
            if(s.empty())
                cout << 0 << ' ';
            else
                cout << s.top().second << ' ';
        }

        s.push(make_pair(a, i + 1));
    }
    cout << '\n';
}
