#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
    int N, num, n;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        if(i > 0){
            pq.push(num);
        }
        else{
            n = num;
        }
    }

    if(pq.empty())
        cout << 0 << '\n';
    else{
        int result = 0;
        while(n <= pq.top()){
            int c = pq.top() - 1;
            pq.pop();
            n++;
            result++;
            pq.push(c);
        }
        cout << result << '\n';
    }
}