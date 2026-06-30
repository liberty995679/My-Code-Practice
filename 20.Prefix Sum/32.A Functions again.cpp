//n个元素，数组a
//f(l, r) = |al - a(l + 1) |+ .... |a(r - 1) - ar| * (-1)^(i - l)
//计算f(l, r) 的最大值
//求最大子段和
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <deque>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;

ll convert(const vector<ll> &a) {
    ll cur1 = 0; ll cur2 = 0;
    ll ans = 0;
    int n = a.size() - 1;
    for (int i = 1; i < n; i++) {
        ll x;
        if (i % 2 == 0) {   //情况1： 正负 正负
            x = -a[i];
        } else {
            x = a[i];
        }
        cur1 = max(x, cur1 + x); //最大子段和
        ans = max(ans, cur1);
        x = -x;   //情况2： 负正 负正
        cur2 = max(x, cur2 + x);
        ans = max(ans, cur2);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<ll> b(n + 1);
    for (int i = 1; i < n; i++) {
        b[i] = abs(arr[i] - arr[i + 1]);
    }
    ll ans = 0;
    ans = convert(b);
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