//一个字符串包含n个0,m个1，求有多少种1开头的排列
//结果对1e9 + 7取模
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXIN = 2e6 + 5;
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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << C(n + m - 1, n) << endl;
    }
}