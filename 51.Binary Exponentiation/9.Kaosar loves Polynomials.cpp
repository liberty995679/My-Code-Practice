//p(x) = a0 + a1*x + a2*x^2 +..+ an*x^n,求p(x)^k对1e9 + 7取模
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll power(ll a, ll b, ll mod) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void solve(ll k, ll n, const vector<ll> &nums) {
    ll ans = 0;
    for (auto &i : nums) {
        ans = (ans + i) % MOD; 
    }
    ans = (ans % MOD + MOD) % MOD; //考虑负数取模
    cout << power(ans, k, MOD) << endl;
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
        ll k, n;
        cin >> k >> n;
        vector<ll> arr(n + 1);
        for (int i = 0; i < n + 1; i++) cin >> arr[i];
        solve(k, n, arr);
    }
    return 0;
}