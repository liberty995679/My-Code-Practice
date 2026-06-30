//t个用例 n个元素的数组a 每个元素都不同
//在数组插入一个a(n+1) 每个数组元素不同
//选择一个x(x > 0) 使数组每个元素加x 直到每个元素相等
//计算所有元素想等的最小操作次数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

void solve() {     
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        ll g = 0;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++) {
            g = gcd(g, arr[i] - arr[i - 1]);
        }
        if (g == 0) {
            // 说明 n == 1
            cout << 1 << '\n';
            continue;
        }
        ll mxnum = arr.back();
        ll minum = arr[0];
        ll a_new = minum - g;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ((mxnum - arr[i]) / g);
        }
        ll extra_cnt = LLONG_MAX;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > g) {
                ll cur = arr[i] - g;  //要插入的值
                extra_cnt = min(extra_cnt, (mxnum - cur) / g);
            }
        }
        if (extra_cnt == LLONG_MAX) {  //如果中间没有就选最左边
            ll cur = minum - g;
            extra_cnt = (mxnum - cur) / g;
        }
        cout << ans + extra_cnt << endl;
    }
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