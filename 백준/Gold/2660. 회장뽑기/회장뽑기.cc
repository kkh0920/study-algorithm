#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[51], result[51];
int N, dist[51][51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i != j)
                dist[i][j] = 123456;
        }
    }

    int s = 0, e = 0;
    while(1){
        cin >> s >> e;
        if(s == -1 || e == -1)
            break;

        graph[s].push_back(e);
        graph[e].push_back(s);
        
        dist[s][e] = 1;
        dist[e][s] = 1;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    int minDist = 123456;
    for(int i = 1; i <= N; i++){
        int maxDist = 0;
        for(int j = 1; j <= N; j++){    
            maxDist = max(maxDist, dist[i][j]);
        }
        minDist = min(minDist, maxDist);
        result[maxDist].push_back(i);
    }

    cout << minDist << ' ' << result[minDist].size() << '\n';
    for(auto x : result[minDist]){
        cout << x << ' ';
    }
    cout << '\n';
}
