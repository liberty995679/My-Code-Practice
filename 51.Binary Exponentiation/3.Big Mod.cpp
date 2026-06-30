//求幂, b ^ p mod m
#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b, p, m;
    while (cin >> b >> p >> m) {
        cout << power(b, p, m) << endl;
    }
    return 0;
}