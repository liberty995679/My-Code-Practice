//t个例子 n个元素的数组a
//将整个数组的最大公约数等于1
//每次操作可将 ai 改为gcd(ai, i) 操作代价为n - i + 1
//计算最小代价
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int g = 0;
        for (int x: arr) g = gcd(g, x);
        if (g == 1) {
            cout << 0 << '\n';
            continue;
        }
        unordered_map<int, int> dp;
        dp[0] = 0;   // dp[g] = 达到当前整体gcd为g的最小代价
        for (int i = 0; i < n; i++) {
            int cost = n - i; // 操作位置i的代价
            int v0 = arr[i];  //不操作
            int v1 = gcd(arr[i], i + 1);  //操作
            unordered_map<int, int> ndp;
            for (auto x: dp) {
                int cur_gcd = x.first;
                int cur_cost = x.second;
                int ndp0 = gcd(v0, cur_gcd);  //不操作
                if (!ndp.count(ndp0) || ndp[ndp0] > cur_cost) {// 如果这个gcd值没出现过，或者出现过但代价更大
                    ndp[ndp0] = cur_cost;  //就更新为更小的代价
                }
                int ndp1 = gcd(v1, cur_gcd); //操作
                int ndp1cost = cur_cost + cost;
                if (!ndp.count(ndp1) || ndp[ndp1] > ndp1cost) {
                    ndp[ndp1] = ndp1cost;
                }
            }
            dp = move(ndp);  // 新状态替换旧状态，准备处理下一个元素
        }
        cout << dp[1] << '\n';
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