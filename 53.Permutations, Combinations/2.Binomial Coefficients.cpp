//输出a! / (b!(a - b)!),并对1e9 + 7取模
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

vector<ll> arr(1e6 + 1);
void coeff() {
    arr[0] = 1;
    for (ll i = 1; i <= 1e6; i++) {
        arr[i] = (arr[i - 1] * i) % MOD;
    }
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

void solve(ll a, ll b) {    //除法取模要用模逆元
    ll x = arr[b] * arr[a - b] % MOD;
    ll ans = power(x, MOD - 2) % MOD;
    cout << (arr[a] * ans) % MOD << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    coeff();
    while (n--) {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}