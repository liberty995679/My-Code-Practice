//偶数位是偶数，奇数位是素数，输入n,输出这样符合条件的数对1e9+7取模
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll x = power(5, n / 2, MOD);
    ll y = power(4, n / 2, MOD);
    if (n % 2 == 0) {
        ll ans = (x * y) % MOD;
        cout << ans << endl;
    } else {
        ll ans = (x * y) % MOD;
        ans = (ans * 5) % MOD;
        cout << ans << endl;
    }
    return 0;
}