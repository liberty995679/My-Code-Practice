//t个用例 n长度 数组a
//每次操作选择两个数，使其中一个数变成gcd(a, b)
//计算最少操作数
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
#include <set>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void solve() { 
    int n;
    cin >> n;
    vector<int> arr;
    priority_queue<int> pq;
    int mx;
    cin >> mx; //最大公约数
    arr.push_back(mx);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        mx = gcd(mx, x);
        arr.push_back(x);
    }
    int cnt_mx = count(arr.begin(), arr.end(), mx);
    if (cnt_mx != 0) {
        cout << n - cnt_mx << "\n";
        return;  // ← 关键：提前返回，跳过dp
    }
    unordered_map<int, int> dp;
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> ndp;
        ndp[arr[i]] = 1;   //选一个值 gcd为1
        for (auto it: dp) {
            int g = it.first;
            int cnt = it.second;
            int ng = gcd(g, arr[i]);
            if (!ndp.count(ng)) {
                ndp[ng] = cnt + 1;
            } else {  //如果这个 gcd 之前已经出现过,我们要取 最少用几个数所以取 min
                ndp[ng] = min(ndp[ng], cnt + 1);
            }
        }
        for (auto it: ndp) {
            int ng = it.first;
            int cnt = it.second;
            if (!dp.count(ng)) dp[ng] = cnt;
            else dp[ng] = min(dp[ng], cnt);
        }

    }
    int s = dp[mx];
    cout << n + s - 2 << endl;
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