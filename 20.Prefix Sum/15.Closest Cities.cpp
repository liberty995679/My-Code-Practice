//数轴上有 n座城市，第 i座城市位于坐标 ai处。城市的按坐标升序给出
//两座城市 x和 y之间的距离定义为 ∣ax−ay∣
//对每座城市，最近城市是唯一确定的。
//前往城市 x的最近城市，花费 1 枚硬币
//给定 m次查询。每次查询给出两座城市，你需要计算从一座城市到另一座城市的最少硬币花费
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
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        // preR[i]：从城市 i-1 沿最优路走到城市 i 的累计花费（从左往右）
        vector<ll> preR(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            ll directCost = a[i] - a[i-1]; // 直跳到 i 的花费
            ll stepCost;
            if (i - 1 == 1) {
                // 城市1只有右邻，最近城市必是城市2（即 i）
                stepCost = 1;
            } else {
                ll leftDist  = a[i-1] - a[i-2]; // i-1 到左邻的距离
                ll rightDist = a[i]   - a[i-1]; // i-1 到右邻(i)的距离
                // i-1 的最近城市是右边(i) → 可花费1跳过来
                stepCost = (rightDist <= leftDist) ? 1 : directCost;
            }
            preR[i] = preR[i-1] + stepCost;
        }

        // preL[i]：从城市 i+1 沿最优路走到城市 i 的累计花费（从右往左）
        vector<ll> preL(n + 2, 0);
        for (int i = n - 1; i >= 1; i--) {
            ll directCost = a[i+1] - a[i]; // 直跳到 i 的花费
            ll stepCost;
            if (i + 1 == n) {
                // 城市n只有左邻，最近城市必是城市n-1（即 i）
                stepCost = 1;
            } else {
                ll leftDist  = a[i+1] - a[i];   // i+1 到左邻(i)的距离
                ll rightDist = a[i+2] - a[i+1]; // i+1 到右邻的距离
                // i+1 的最近城市是左边(i) → 可花费1跳过来
                stepCost = (leftDist <= rightDist) ? 1 : directCost;
            }
            preL[i] = preL[i+1] + stepCost;
        }

        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            if (x < y) {
                // 向右走
                cout << preR[y] - preR[x] << "\n";
            } else {
                // 向左走
                cout << preL[y] - preL[x] << "\n";
            }
        }
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