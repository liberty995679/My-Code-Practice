//费马小定理，模逆元,求 a / b mod n的值
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

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

void solve(ll a, ll b, ll n) {
    ll ans = a % n;
    ll b_pow = power(b, n - 2, n);
    cout << (ans * b_pow) % n << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, n;
    cin >> a >> b >> n;
    solve(a, b, n);
    return 0;
}