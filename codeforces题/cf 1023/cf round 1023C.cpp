//填充缺失的部分,使得a的最大子数组和恰好等于k
//你会得到字符串s 和数组a
//如果ai有值 si = 1,如果没有值 ai = 0; si = 0;
//如果存在一个解
//输出Yes 和数组的每一个元素
//否则输出No
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    ll n, k; 
    string s;
    cin >> n >> k >> s;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int pos = -1;
    ll sum = 0;
    ll mx = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            pos = i;
            arr[pos] = -1e18;  //填大负数为了隔断元素
        }
    }
    for (int i = 0; i < n; i++) {
        sum = (arr[i] > -1e7 ? max(arr[i] + sum, arr[i]) : arr[i]);
        mx = max(mx, sum);
    }
    // 如果当前最大子数组和已经大于 k，或者没有缺失位置但不等于 k，则无解
    if (mx > k || (mx != k && pos == -1)) {
        cout << "No\n";
        return;
    }
    if (pos != -1) {
        ll l_max = 0; //pos左边最大值
        ll r_max = 0; //pos右边最大值
        ll cur = 0;
        for (int i = pos - 1; i >= 0; i--) {
            if (arr[i] < -1e6) break;
            cur += arr[i];
            l_max = max(l_max, cur);
        }
        cur = 0;
        for (int i = pos + 1; i < n; i++) {
            if (arr[i] < -1e6) break;  //遇到隔断符直接出来
            cur += arr[i];
            r_max = max(r_max, cur);
        }
        arr[pos] = k - l_max - r_max;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " \n"[i + 1 == n];
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