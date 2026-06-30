//已知每个苹果的重量
//输入 n 个 苹果
//将苹果分成两组 使其权重差异最小
//输出最小权重差异值
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll ans = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++) {
        ll asum = 0;
        ll bsum = 0;
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit)) {
                asum += arr[bit];
            } else {
                bsum += arr[bit];
            }
        }
        ans = min(ans, abs(asum - bsum));
    }
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