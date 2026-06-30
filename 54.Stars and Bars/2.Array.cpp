//使数组满足非递增或者非递减的条件，输出有几种可能性
//在1-n中选n个数，可重复选择
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXIN = 1e6 + 5;
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

vector<ll> fact(MAXIN + 1), invfact(MAXIN + 1);

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXIN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXIN] = power(fact[MAXIN], MOD - 2);
    for (int i = MAXIN - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}

ll A(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k] % MOD;
}
ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k]% MOD;
}

int main() {                    
#ifndef ONLINE_JUDGE            
    freopen("in.txt", "r", stdin);  
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n;
    cin >> n;
    cout << (2 * C(2 * n - 1, n) % MOD - n) % MOD << endl;
}