//t个用例 n个位置 数组a 每秒的熔岩速率p
//ai = 0 表示i位置是火山
//ai > 0 表示位置有一栋ai的建筑物
//对于每个位置i 计算建筑物i被熔岩完全淹没的最早时间
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
void solve() {  //矮的建筑物会被前面或者后面高的建筑物挡住，时间会和高建筑一样
    int n;
    ll p;
    cin >> n >> p;
    vector<int> arr(n);
    vector<ll> need(n);     // 每个建筑单独被淹需要多少秒
    vector<ll> ans(n, LLONG_MAX);  // 最终答案
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            need[i] = 0;
        } else {
            need[i] = (arr[i] + p - 1) / p;  //整数向上取整
        }
    }
    ll cur = -1;   // 从当前火山走到这里，中间建筑被淹没需要的最大时间
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cur = 0;
        } else if (cur != -1) {
            cur = max(cur, need[i]);  //如果有熔岩流过来，最高建筑被淹没
        }
        if (cur != -1) {
            ans[i] = min(ans[i], cur);
        }
    }
    cur = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            cur = 0;
        }else if (cur != -1) {
            cur = max(cur, need[i]);  //如果有熔岩流过来，最高建筑被淹没
        }
        if (cur != -1) {
            ans[i] = min(ans[i], cur);
        }
    }
    for (auto &it: ans) {
        cout << it << ' ';
    }cout << endl;
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