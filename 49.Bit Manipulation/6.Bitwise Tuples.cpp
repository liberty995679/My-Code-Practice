//An <= 2^m - 1,且a1&a2&...an = 0
#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;    //从位来看，每列可以是0或1，也就是2^n - 1,减掉了竖着全1的情况，共有m列
ll power(ll a, ll n, ll mod) {
    ll res = 1;
    a %= mod;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll res = (power(2, n, MOD) - 1) % MOD;
        res = power(res, m, MOD);
        cout << res % MOD << endl;
    }
    return 0;
}