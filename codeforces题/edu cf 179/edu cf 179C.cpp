//输入n长度的数组
//可以执行两种操作之一
//选择一个位置i 将它左边的元素变成ai 代价为(i - 1) * ai
//选择一个位置i 将它右边的元素变成ai 代价为(n - i) * ai
//可以执行任意操作
//计算使数组所有元素相等的最小总代价
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
ll check(const vector<int> &a) {
    ll res = LLONG_MAX;
    int n = a.size() - 1;
    int i = 1;
    ll cost = 0;
    while (i <= n) {  //就是把每个连续段的结果都计算一下取最小
        int j = i;
        while (j <= n && a[j] == a[i]) {
            j++;
        }
        cost = (ll)(i + n - j) * a[i];
        res = min(res, cost);
        i = j;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ll ans = check(arr);
    cout << ans << endl;
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