//给n个孩子分m个苹果, 并对1e9 + 7取模
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;  
const int MAXIN = 2e6;   //求得是C(n, m), 数组可能越界

vector<ll> fact(MAXIN + 1), invfact(MAXIN + 1);
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

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

ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
} 
void solve(ll n, ll m) {
    ll k = n - 1;
    ll N = m + n - 1;
    cout << C(N, k) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    init();
    solve(n, m);
    return 0;
}