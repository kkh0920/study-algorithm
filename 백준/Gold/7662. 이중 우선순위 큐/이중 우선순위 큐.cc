#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    int T, k, num;

    cin >> T;
    for(int i = 0; i < T; i++){
        priority_queue<int> maxPQ;
        priority_queue< int, vector<int>, greater<int> > minPQ;
        map<int, int> mp;

        cin >> k;

        for(int j = 0; j < k; j++){
            cin >> c >> num;
            if(c == 'I'){
                maxPQ.push(num);
                minPQ.push(num);
                
                mp[num]++;
            }

            else if(c == 'D'){                
                if(num == 1){
                    while(!maxPQ.empty() && mp[maxPQ.top()] == 0)
                        maxPQ.pop();

                    if(maxPQ.empty())
                        continue;
                    
                    mp[maxPQ.top()]--;
                    maxPQ.pop();
                }
                else{
                    while(!minPQ.empty() && mp[minPQ.top()] == 0)
                        minPQ.pop();

                    if(minPQ.empty())
                        continue;
                    
                    mp[minPQ.top()]--;
                    minPQ.pop();
                }
            }
        }

        while(!maxPQ.empty() && mp[maxPQ.top()] == 0)
            maxPQ.pop();
        while(!minPQ.empty() && mp[minPQ.top()] == 0)
            minPQ.pop();

        if(maxPQ.empty() || minPQ.empty())
            cout << "EMPTY\n";
        else
            cout << maxPQ.top() << ' ' << minPQ.top() << '\n';
    }
}
