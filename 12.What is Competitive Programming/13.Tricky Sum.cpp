//计算1 到 n 的总和
//然后减去2的次方
//输出结果
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    ll res = n * (n + 1) / 2;
    ll sum = 0;
    for (int i = 1; i <= res; i <<= 1) sum += i;
    cout << res - sum << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >>  t;
    while (t--) solve();
    return 0;
}