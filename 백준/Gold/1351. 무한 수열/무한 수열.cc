#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;
long long N, P, Q;

long long dp(long long n){
	if(m.find(n) != m.end())
		return m[n];
	return m[n] = dp(n / P) + dp(n / Q);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N >> P >> Q;

	m[0] = 1;
	cout << dp(N) << '\n';
}