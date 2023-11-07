#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

queue< pair<int, int> > cur, coord;
int destX, destY, T, N;

void bfs(){
    while(!cur.empty()){
        int curX = cur.front().first;
        int curY = cur.front().second;
        cur.pop();

        int dist = abs(destX - curX) + abs(destY - curY);

        if(dist <= 50 * 20){
            cout << "happy" << '\n';
            return;
        }

        int size = coord.size();
        for(int i = 0; i < size; i++){
            int nX = coord.front().first;
            int nY = coord.front().second;
            coord.pop();

            int d = abs(nX - curX) + abs(nY - curY);

            if(d <= 50 * 20)
                cur.push(make_pair(nX, nY));
            else
                coord.push(make_pair(nX, nY));
        }
    }
    cout << "sad" << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while(T--){
        cin >> N;

        int curX, curY;
        cin >> curX >> curY;
        cur.push(make_pair(curX, curY));
        
        int x, y;
        for(int i = 0; i < N; i++){
            cin >> x >> y;
            coord.push(make_pair(x, y));   
        }
        
        cin >> destX >> destY;

        bfs();

        while(!cur.empty()) cur.pop();
        while(!coord.empty()) coord.pop();
    }
}