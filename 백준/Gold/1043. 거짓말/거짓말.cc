#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> party[50], graph[51];
    queue<int> q;
    int N, M, p, t, num, result = 0;
    bool check[51] = { false };

    cin >> N >> M >> t;
    for(int i = 0; i < t; i++){
        cin >> num;
        check[num] = true;
        q.push(num);
    }

    for(int i = 0; i < M; i++){
        cin >> p;
        for(int j = 0; j < p; j++){
            cin >> num;
            party[i].push_back(num);
            if(j >= 1){
                graph[party[i][j - 1]].push_back(num);
                graph[num].push_back(party[i][j - 1]);
            }
        }
    }
    int gSize, temp;
    while(!q.empty()){
        gSize = graph[q.front()].size();
        for(int i = 0; i < gSize; i++){
            temp = graph[q.front()][i];
            if(!check[temp]){
                check[temp] = true;
                q.push(temp);
            }
        }
        q.pop();
    }
    
    int size;
    bool isTruthExist; 
    for(int i = 0; i < M; i++){
        isTruthExist = false;
        size = party[i].size();
        for(int j = 0; j < size; j++){
            if(check[party[i][j]]){
                isTruthExist = true;
                break;
            }
        }
        result += !isTruthExist ? 1 : 0;
    }

    cout << result << '\n';
}