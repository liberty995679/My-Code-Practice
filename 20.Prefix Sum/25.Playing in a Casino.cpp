//给出n个数组每个有m个元素
//计算两两之间的差的绝对值之和
//计算曼哈顿距离总和
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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    vector<vector<ll>> prefix(m + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<ll>> b(m, vector<ll> (n)); //保存排序后的数组,按列
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            b[j][i] = arr[i][j];
        }
    }
    for (auto &i: b) {
        sort(i.begin(), i.end());
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i][j - 1] + b[i][j - 1];
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            ans += (b[i][j - 1] * (j - 1) - prefix[i][j - 1]); //ai * i - sum ,sum指前面的前缀和i-1
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}