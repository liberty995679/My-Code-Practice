//t个用例，n 长度 k 总回合数
//数组a的元素 数组b的元素,有两个玩家
//每个回合，玩家都可以选择一个下标
//使得ai = ai + bi 或者 ai = ai - bi
//A玩家要最大化最终得分，B玩家要最大化最终得分
//计算最终得分   最终得分 = 修改后的数组 a的最大非空子数组和。
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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    k = k % 2;
    vector<ll> L(n); // 以i结尾的最大子段和
    for (int i = 0; i < n; i++) {
        L[i] = (i && L[i - 1] > 0 ? L[i - 1] : 0LL) + a[i];
    }
    vector<ll> R(n);
    for (int i = n - 1; i >= 0; i--) {
        R[i] = (i + 1 < n && R[i + 1] > 0 ? R[i + 1] : 0LL) + a[i];
    }
    if (k == 0) {
        ll ans = *max_element(L.begin(), L.end());
        cout << ans << '\n';
    } else {   //选择以 a[i] 为中心的子段，将 Alice 的一次操作加在 a[i] 上得到的最大子段和
        ll ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, L[i] + R[i] - a[i] + b[i]); //L[i] + R[i] 会把 a[i] 加了两次，所以减去一次a[i]
        }
        cout << ans << '\n';
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