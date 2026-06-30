//给你一个由互不相同的整数组成的数组 a，下标从 1 到 n，还有一个整数 s。
//初始时，你位于 X 轴上的位置 pos = s。每一步，你必须且只能执行以下两种动作之一：
//从位置 pos 移动到位置 pos + 1。
//从位置 pos 移动到位置 pos - 1。
//如果整个行走过程中，你访问了 X 轴上每个 a[i] 位置至少一次，则这个步数序列被认为是成功的。注意，初始位置 pos = s 也算作已访问。
//你的任务是，求出任意成功步数序列的最小步数
//t个用例 输入n s 输入n长度的数组a
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
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i= 0; i < n; i++) cin >> arr[i];
    if (n == 1) {
        cout << abs(s - arr[0]) << enl;
        return;
    }
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());
    if (s < mn) {
        cout << mx - mn + mn - s << enl;
    } else if (s > mx) {
        cout << s - mx + mx - mn << enl;
    } else {
        int dist1 = s - mn + mx - mn;
        int dist2 = mx - s + mx - mn;
        cout << min(dist1, dist2) << enl;
    }
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