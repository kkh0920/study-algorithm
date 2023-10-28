#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int n, num = 666, cnt, cnt2 = 0;
    string title;
    cin >> n;
    while(cnt2 < n){
        title = to_string(num);
        cnt = 0;
        for(int j = 0; j < title.size(); j++){
            if(title[j] == '6')
                cnt++;
            else
                cnt = 0;
            if(cnt == 3){
                cnt2++;
                break;
            }
        }
        num++;
    }
    cout << num - 1 << '\n';
}