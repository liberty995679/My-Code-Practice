//n个数组元素, 连续k天视为一周
//总共需要n - k + 1周去考虑
//计算平均睡眠时间
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    ll ans = 0;
    for (int i = k; i <= n; i++) {
        ans += (prefix[i] - prefix[i - k]);
    }
    double res = (double)ans / (double)(n - k + 1);
    cout << fixed << setprecision(9);
    cout << res << endl;
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