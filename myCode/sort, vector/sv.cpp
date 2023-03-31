#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair < int, pair <int, string> > p1, pair < int, pair <int, string> > p2){
    if(p1.second.first == p2.second.first)
        return p1.first < p2.first;
    return p1.second.first < p2.second.first;
}

int main(){
    vector< pair < int, pair <int, string> > > v;
    int n, age, order;
    string name;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> age >> name;
        order = i;
        v.push_back(make_pair(order, make_pair(age, name)));
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].second.first << ' ' << v[i].second.second << '\n';
    }
}