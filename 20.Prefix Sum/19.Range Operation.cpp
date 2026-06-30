//给一个长度为n的数组a
//选择区间[l, r] 将区间内所有元素替换为(l + r)
//如果最多执行一次操作
//计算数组的最大可能总和
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n + 1);   // 操作收益 = (r-l+1)*(l+r) - sum(a[l..r])
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<ll> prefix(n + 1);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        ll best_g = 0;  //最大收益
        ll max_g = LLONG_MIN; //gl的最大值
        ll total = prefix[n];  //原数组总和
        for (int r = 1; r <= n; r++) {
            ll gl = prefix[r - 1] - (ll) r * r + r;  // 先用 l=r 更新 max_g，确保 l <= r 的约束
            max_g = max(max_g, gl);
            ll fr = (ll)r * r + r - prefix[r];  // 计算 f(r)，与当前最优 g(l) 组合得到最大收益
            best_g = max(best_g, fr + max_g);
        }
        cout << total + best_g << endl;
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