//铺瓷砖w * h, 一个正方形对角切成两个三角形，一个黑色一个白色,把他们铺到厨房
//注意不能出现一个三角形和周围三角形颜色一样，求可能的铺砖方案数量
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 998244353;

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

void solve(int w, int h) {
    ll res = power(2, w + h, MOD);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h;
    cin >> w >> h;
    solve(w, h);
    return 0;
}