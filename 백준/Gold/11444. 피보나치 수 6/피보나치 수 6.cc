#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;

map<long long, int> mem;

long long fibo(long long n) {
    if(mem.find(n) != mem.end())
        return mem[n];
        
    long long k = n / 2;
    
    int res = (fibo(k + 1) * fibo(n - k)) % MOD;
    res += (fibo(k) * fibo(n - (k + 1))) % MOD;
    res %= MOD;
    
    return mem[n] = res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 1;

    long long num;

    cin >> num;

    cout << fibo(num) << '\n';

    return 0;
}