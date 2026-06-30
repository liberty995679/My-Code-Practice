/*把一份原件复制成 n 份副本（不算原件），
有两台复印机，分别需要 x 秒和 y 秒复印一张纸。
两台机可以同时工作，也可以从已有的副本继续复印。求完成 n 份副本最少需要多少秒。*/
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll solve (ll n, ll x, ll y) {
    ll l = 0; ll r = max(x, y) * n; 
    while (l < r) {
        ll t = l + (r - l) / 2;
        if (t / x + t / y < n) l = t + 1;  //t / x + t / y >= n - 1
        else r = t;
    }
    return l;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, y;
    cin >> n >> x >> y;
    if (n == 1) cout << min(x, y) << '\n';
    else {
        int seconds = min(x, y);
        cout << solve(n - 1, x, y) + seconds << endl;
    }
}