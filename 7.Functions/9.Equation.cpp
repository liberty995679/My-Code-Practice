//计算S = (X0 - 1) + (X2) + (X4) + (X6) + ... + (XN)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
 
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void calculate(int x, int n) {
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }
    ll res = 0;
    for (int i = 2; i <= n; i += 2) {
        res += power(x, i);
    }
    cout << res << endl;
}

void solve() {
    int x, n;
    cin >> x >> n;
    calculate(x, n);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r" ,stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}