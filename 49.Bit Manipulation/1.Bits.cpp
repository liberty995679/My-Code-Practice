//输出l到r中，二进制数位为1最多的数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve(ll l, ll r) {
    ll res = l;
    for (int i = 0; i < 63; i++) {  //ll的位数
        ll x = l | ((1LL << i) - 1);   //只把低 i 位改成 1
        if (x <= r) res = x;
    }
    cout << res << endl;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll l, r;   //0 <= l <= r <= 1e18
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}