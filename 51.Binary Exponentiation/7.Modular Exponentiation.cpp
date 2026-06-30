//反向取余, 求m mod 2 ^ n
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll power(ll a, ll b, int mod) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void solve(ll n, ll m) {
    if (n >= 63) {                   //1ll << n 会在 n >= 63 时溢出（long long 只有 64 位)
        cout << m << endl;            //当 n >= 63 时，2^n 已经大到比 m 还大；所以 m % 2^n = m。
        return;
    }
    ll res = m & ((1ll << n) - 1); //(1ll << n) 表示2^n ,-1则是低n位
    cout << res << endl;           //而“取 m 的低 n 位”恰好就是 m mod 2^n
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}