//找长度为n的数组，满足a1​&a2​&…&an​=0，元素和尽可能大，并取模
#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;    //从位来看，每列只需要有一个0，有n种可能，一共有k列，则n^k
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
        int n, k;
        cin >> n >> k;
        ll res = power(n, k, MOD);
        cout << res % MOD << endl;
    }
    return 0;
}