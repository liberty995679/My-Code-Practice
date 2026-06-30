//输入n 和 k
//在 1 到 n 中 找数，使其异或总和最大
//不超过k个数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k; //找小于n 的 2^m - 1
    ll m = 0;
    if (k == 1) {
        cout << n << "\n";
        return ;
    }
    while ((1LL << m) <= n) m++;
    ll ans = (1LL << m) - 1;
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}