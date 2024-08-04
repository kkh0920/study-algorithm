#include <iostream>
#include <queue>
using namespace std;

int n, arr[3], attack[3] = { 9, 3, 1 }, result = 0;
// 5(012), 7(021), 11(102), 15(120), 19(201), 21(210)
int order[6] = { 5, 7, 11, 15, 19, 21 };
bool checked[61][61][61];

void solution(int scv1, int scv2, int scv3) {
    queue< pair<int, pair<int, int> > > q;
    q.push(make_pair(arr[0], make_pair(arr[1], arr[2])));
    checked[arr[0]][arr[1]][arr[2]] = true;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int s1 = q.front().first;
            int s2 = q.front().second.first;
            int s3 = q.front().second.second;
            q.pop();

            if(s1 <= 0 && s2 <= 0 && s3 <= 0) {
                return;
            }
            
            for(int i = 0; i < 6; i++) {
                int o = order[i];
                int ns1 = s1 - attack[o / 9]; o %= 9;
                int ns2 = s2 - attack[o / 3]; o %= 3;
                int ns3 = s3 - attack[o];
                
                if(ns1 < 0) ns1 = 0;
                if(ns2 < 0) ns2 = 0;
                if(ns3 < 0) ns3 = 0;

                if(!checked[ns1][ns2][ns3]) {
                    checked[ns1][ns2][ns3] = true;
                    q.push(make_pair(ns1, make_pair(ns2, ns3)));
                }
            }
        }
        result++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solution(arr[0], arr[1], arr[2]);

    cout << result << '\n';

    return 0;
}