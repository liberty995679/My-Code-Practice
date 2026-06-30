//t个用例 n长度 数组a元素 -1e9 <= ai <= 1e9
//一共有n - 1次操作 ,  x 初始为0
//每次操作可以选择第一个孩子或者第二个孩子
//如果选择第一个 x += ai 如果选择第二个 x -= ai
//计算所有操作完成后x的最大值
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
    int n = a.size();
    vector<ll> pre(n + 1), suf(n + 1); //左边的贡献右边的贡献
    for (int i = 1; i < n; i++) {   //1 ... n - 1 前缀和
        pre[i + 1] = pre[i] + abs(a[i]);  //s[2] = a[1] s[3] = a[1] + a[2]
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] - a[i + 1];  //k + 1, k + 2 .....n - 1
    }
    ll ans = LLONG_MIN;
    for (int k = 0; k < n; k++) {
        ll x = 0;
        if (k > 0) x += a[0];
         x += pre[k];
         x += suf[k];
        ans = max(ans, x);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n; 
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll ans = convert(arr);
    cout << ans << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}