//背包问题
//n个物品，一共能装w重量的东西
//每个物品的数量和价值
//计算能带到背包里的最大价值
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <unordered_map>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int ww = 0;
        int v = 0;
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit)) {
                ww += arr[bit].first;
                v += arr[bit].second;
            }
        }
        if (ww <= w) {
            ans = max(ans, v);
        }
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